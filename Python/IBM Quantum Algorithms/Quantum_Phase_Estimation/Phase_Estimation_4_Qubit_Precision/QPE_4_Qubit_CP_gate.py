"""
Quantum Phase Estimation (QPE) Implementation
Platform: IBM Quantum Runtime Service
Description: Estimates the phase of a Controlled-Phase (CP) gate unitary.
             Uses 4 precision qubits and 2 eigenstate qubits.
             FIXED: Replaced deprecated 'mcphase' with 'mcp'.
"""

import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler


def create_input_state_circuit():
    """
    Circuit 1: Input State Initialization
    Visualizes the superposition of precision qubits and the |11> eigenstate preparation.
    """
    # 6 Qubits total: 4 Precision (0-3), 2 Eigenstate (4-5)
    qr = QuantumRegister(6, "q")
    cr = ClassicalRegister(6, "c")  # Measuring all 6 for visualization
    qc = QuantumCircuit(qr, cr)

    # 1. Initialize State
    # Apply Hadamard to precision qubits (q0-q3) to create equal superposition
    qc.h([0, 1, 2, 3])

    # Apply X to eigenstate qubits (q4, q5) to prepare state |11>
    # The Unitary is CP(pi/2). |11> is an eigenvector with eigenvalue e^(i*pi/2)
    qc.x([4, 5])

    qc.barrier()

    # Measure all qubits for the initial state histogram
    qc.measure(qr, cr)

    return qc


def create_qpe_circuit():
    """
    Circuit 2: Full Quantum Phase Estimation (QPE)
    Estimates the phase of the CP(pi/2) unitary.
    """
    # 4 Precision Qubits (0-3), 2 Eigenstate Qubits (4-5)
    q_prec = QuantumRegister(4, "precision")
    q_eig = QuantumRegister(2, "eigen")
    # We only measure the 4 precision qubits
    c_prec = ClassicalRegister(4, "meas")

    qc = QuantumCircuit(q_prec, q_eig, c_prec)

    # =========================================================
    # Step 1: Initialization
    # =========================================================
    # Precision qubits into superposition
    qc.h(q_prec)
    # Eigenstate qubits to |11>
    qc.x(q_eig)

    qc.barrier()

    # =========================================================
    # Step 2: Controlled-Unitary Operations (Phase Kickback)
    # =========================================================
    # Unitary U = CP(pi/2) acting on q4, q5.
    # We apply Controlled-U^k from precision qubits.
    # This results in Multi-Controlled-Phase gates (3 qubits: 1 prec + 2 eigen).
    # Since eigenstate is |11>, applying CP(theta) on q4,q5 controlled by q_p
    # is equivalent to a CCPhase(theta) on q_p, q4, q5.

    # REPLACEMENT: Used qc.mcp() instead of qc.mcphase()

    # q3 controls U^1 (Angle: 1 * pi/2)
    # logic: if q3=1 and q4=1 and q5=1 -> phase shift pi/2
    qc.mcp(np.pi / 2, [q_prec[3], q_eig[0]], q_eig[1])

    # q2 controls U^2 (Angle: 2 * pi/2 = pi)
    qc.mcp(np.pi, [q_prec[2], q_eig[0]], q_eig[1])

    # q1 controls U^4 (Angle: 4 * pi/2 = 2pi)
    # Note: 2pi rotation is effectively Identity, but included for completeness logic
    qc.mcp(2 * np.pi, [q_prec[1], q_eig[0]], q_eig[1])

    # q0 controls U^8 (Angle: 8 * pi/2 = 4pi)
    # Note: 4pi rotation is effectively Identity
    qc.mcp(4 * np.pi, [q_prec[0], q_eig[0]], q_eig[1])

    qc.barrier()

    # =========================================================
    # Step 3: Inverse Quantum Fourier Transform (IQFT)
    # =========================================================
    # Transforms the phase encoded in amplitudes back to computational basis.

    # 1. Reverse Qubit Order (SWAP)
    qc.swap(q_prec[0], q_prec[3])
    qc.swap(q_prec[1], q_prec[2])

    # 2. IQFT Sequence
    # Block for q3 (original MSB location)
    qc.h(q_prec[3])
    qc.cp(-np.pi / 2, q_prec[3], q_prec[2])

    # Block for q2
    qc.h(q_prec[2])
    qc.cp(-np.pi / 4, q_prec[3], q_prec[1])
    qc.cp(-np.pi / 2, q_prec[2], q_prec[1])

    # Block for q1
    qc.h(q_prec[1])
    qc.cp(-np.pi / 8, q_prec[3], q_prec[0])
    qc.cp(-np.pi / 4, q_prec[2], q_prec[0])
    qc.cp(-np.pi / 2, q_prec[1], q_prec[0])

    # Block for q0
    qc.h(q_prec[0])

    qc.barrier()

    # =========================================================
    # Step 4: Measurement
    # =========================================================
    # Measure only the precision register
    qc.measure(q_prec, c_prec)

    return qc


def main():
    try:
        # 1. Initialize Service
        print("Initializing IBM Quantum Service...")
        service = QiskitRuntimeService()

        # 2. Select Backend
        print("Selecting least busy operational backend...")
        backend = service.least_busy(operational=True, simulator=False)
        print(f"Selected Backend: {backend.name}")

        # 3. Create Circuits
        print("Constructing circuits...")
        qc_input = create_input_state_circuit()
        qc_qpe = create_qpe_circuit()

        # 4. Transpile
        print("Transpiling circuits (Optimization Level 3)...")
        pm_input = transpile(qc_input, backend=backend, optimization_level=3)
        pm_qpe = transpile(qc_qpe, backend=backend, optimization_level=3)

        # 5. Submit Job
        sampler = Sampler(mode=backend)
        pubs = [(pm_input,), (pm_qpe,)]

        print("Submitting QPE batch job (2048 shots)...")
        job = sampler.run(pubs, shots=2048)
        print(f"Job ID: {job.job_id()}")
        print("Waiting for results...")

        # 6. Wait for results
        result = job.result()

        # Extract counts
        # Register names in result follow the circuit definition
        counts_input = result[0].data.c.get_counts()
        counts_qpe = result[1].data.meas.get_counts()

        print("\n=== Raw Counts ===")
        print(f"Input Circuit: {counts_input}")
        print(f"QPE Circuit:   {counts_qpe}")

        # =========================================================
        # Phase Calculation and Verification
        # =========================================================
        # 1. Identify Peak
        peak_bitstring = max(counts_qpe, key=counts_qpe.get)
        measured_int = int(peak_bitstring, 2)

        # 2. Calculate Phase
        # Formula: phase = integer_value / 2^(number_of_precision_qubits)
        precision_qubits = 4
        phase_estimate = measured_int / (2**precision_qubits)

        # Theoretical: CP(pi/2) corresponds to phi = 1/4
        theoretical_phase = 0.25

        print("\n=== QPE Analysis ===")
        print(
            f"Most frequent measurement: |{peak_bitstring}⟩ (decimal: {measured_int})"
        )
        print(f"Estimated phase: φ = {phase_estimate}")
        print(f"Theoretical phase: φ = {theoretical_phase} (1/4)")

        # Verification
        if abs(phase_estimate - theoretical_phase) < 0.01:
            print("✓ Phase estimation successful!")
        else:
            print(
                "⚠ Phase estimation deviated. (Could be due to noise or readout error)"
            )

        # =========================================================
        # Visualization
        # =========================================================
        print("Generating histogram...")
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

        # Plot Input State
        # Expectation: Uniform superposition on first 4 chars, 11 on last 2 chars
        plot_histogram(counts_input, ax=ax1, title="Initial State")
        ax1.legend(["Initial State"])

        # Plot QPE Result
        # Expectation: Peak at |0100>
        plot_histogram(counts_qpe, ax=ax2, title="QPE Result")
        ax2.legend(["QPE Result"])

        fig.suptitle(f"4-Qubit Precision QPE (CP Gate) - {backend.name}")
        plt.tight_layout()

        filename = "qpe_4qubit_cpgate_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")
        import traceback

        traceback.print_exc()


if __name__ == "__main__":
    main()
