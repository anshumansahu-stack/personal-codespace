import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler


def create_input_state_circuit():
    """
    Circuit 1: Input State Initialization
    Visualizes the superposition of precision qubits and the eigenstate preparation.
    """
    # 4 Qubits total: 3 Precision (0,1,2), 1 Eigenstate (3)
    qr = QuantumRegister(4, "q")
    cr = ClassicalRegister(4, "c")  # Measuring all 4 for visualization
    qc = QuantumCircuit(qr, cr)

    # 1. Initialize State
    # Apply Hadamard to precision qubits (q0, q1, q2) to create superposition
    qc.h([0, 1, 2])

    # Apply X to eigenstate qubit (q3) to prepare state |1>
    # The T-gate has eigenstate |1> with eigenvalue e^(i*pi/4)
    qc.x(3)

    qc.barrier()

    # Measure all qubits for the initial state histogram
    qc.measure(qr, cr)

    return qc


def create_qpe_circuit():
    """
    Circuit 2: Full Quantum Phase Estimation (QPE)
    Estimates the phase of the T-gate unitary.
    """
    # 3 Precision Qubits (0-2), 1 Eigenstate Qubit (3)
    q_prec = QuantumRegister(3, "precision")
    q_eig = QuantumRegister(1, "eigen")
    # We only measure the 3 precision qubits
    c_prec = ClassicalRegister(3, "meas")

    qc = QuantumCircuit(q_prec, q_eig, c_prec)

    # =========================================================
    # Step 1: Initialization
    # =========================================================
    # Superposition on precision qubits
    qc.h(q_prec)
    # Prepare eigenstate |1> on qubit 3
    qc.x(q_eig)

    qc.barrier()

    # =========================================================
    # Step 2: Controlled-Unitary Operations (Phase Kickback)
    # =========================================================
    # The precision qubits act as controls for powers of the unitary U (T-gate).
    # This encodes the phase information into the relative phases of the precision qubits.
    # U = T-gate = diag(1, e^{i*pi/4}).
    # T|1> = e^{i*pi/4}|1>. Phase phi = 1/8.

    # q2 (MSB of precision) controls T^1 (Angle: pi/4)
    qc.cp(np.pi / 4, q_prec[2], q_eig[0])

    # q1 controls T^2 (Angle: 2*pi/4 = pi/2)
    qc.cp(np.pi / 2, q_prec[1], q_eig[0])

    # q0 (LSB of precision) controls T^4 (Angle: 4*pi/4 = pi)
    qc.cp(np.pi, q_prec[0], q_eig[0])

    qc.barrier()

    # =========================================================
    # Step 3: Inverse Quantum Fourier Transform (IQFT)
    # =========================================================
    # IQFT transforms the phase encoded in the amplitudes back into the computational basis.

    # 1. SWAP Gates to reverse qubit order (standard QFT/IQFT requirement)
    qc.swap(q_prec[0], q_prec[2])

    # 2. IQFT on q2
    qc.h(q_prec[2])
    qc.cp(-np.pi / 2, q_prec[2], q_prec[1])  # Controlled-R2 inverse

    # 3. IQFT on q1
    qc.h(q_prec[1])
    qc.cp(-np.pi / 4, q_prec[2], q_prec[0])  # Controlled-R3 inverse
    qc.cp(-np.pi / 2, q_prec[1], q_prec[0])  # Controlled-R2 inverse

    # 4. IQFT on q0
    qc.h(q_prec[0])

    qc.barrier()

    # =========================================================
    # Step 4: Measurement
    # =========================================================
    # We measure only the precision qubits to read out the binary expansion of the phase.
    # The eigenstate qubit (q3) is unentangled at the end and is not measured.
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
        # Note: classical registers in SamplerV2 results are accessed by name.
        # qc_input register was named 'c', qc_qpe register was named 'meas'.
        counts_input = result[0].data.c.get_counts()
        counts_qpe = result[1].data.meas.get_counts()

        print("\n=== Raw Counts ===")
        print(f"Input Circuit: {counts_input}")
        print(f"QPE Circuit:   {counts_qpe}")

        # =========================================================
        # Phase Calculation and Verification
        # =========================================================
        # 1. Identify Peak
        # Get the bitstring with the highest count
        peak_bitstring = max(counts_qpe, key=counts_qpe.get)
        measured_int = int(peak_bitstring, 2)

        # 2. Calculate Phase
        # Formula: phase = integer_value / 2^(number_of_precision_qubits)
        precision_qubits = 3
        phase_estimate = measured_int / (2**precision_qubits)
        theoretical_phase = 1 / 8  # T-gate phase is 1/8 (0.125)

        print("\n=== QPE Analysis ===")
        print(
            f"Most frequent measurement: |{peak_bitstring}⟩ (decimal: {measured_int})"
        )
        print(f"Estimated phase: φ = {phase_estimate}")
        print(f"Theoretical phase: φ = {theoretical_phase} (1/8)")

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
        # Expectation: Uniform distribution on q0-q2 (last 3 bits usually), q3=1
        plot_histogram(counts_input, ax=ax1, title="Initial State")
        ax1.legend(["Initial State"])

        # Plot QPE Result
        # Expectation: Peak at |001>
        plot_histogram(counts_qpe, ax=ax2, title="QPE Result")
        ax2.legend(["QPE Result"])

        fig.suptitle(f"3-Qubit Precision QPE (T-gate) - {backend.name}")
        plt.tight_layout()

        filename = "qpe_3qubit_tgate_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")
        import traceback

        traceback.print_exc()


if __name__ == "__main__":
    main()
