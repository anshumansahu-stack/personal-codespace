"""
Code 2: 3-Qubit Inverse Quantum Fourier Transform (IQFT)
Platform: IBM Quantum Runtime Service
"""

import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler


def apply_qft_logic(qc):
    """Helper to apply forward QFT logic (without measurement)"""
    # Initialize |101>
    qc.x(0)
    qc.x(2)
    qc.barrier()

    # QFT Gates
    qc.h(0)
    qc.cp(np.pi / 2, 1, 0)
    qc.cp(np.pi / 4, 2, 0)
    qc.h(1)
    qc.cp(np.pi / 2, 2, 1)
    qc.h(2)
    qc.swap(0, 2)
    return qc


def create_iqft_input_circuit():
    """Applies QFT and measures immediately (to show the mess/superposition)"""
    qr = QuantumRegister(3, "q")
    cr = ClassicalRegister(3, "c")
    qc = QuantumCircuit(qr, cr)

    qc = apply_qft_logic(qc)

    qc.barrier()
    qc.measure(qr, cr)
    return qc


def create_full_iqft_circuit():
    """Applies QFT then IQFT to recover original state"""
    qr = QuantumRegister(3, "q")
    cr = ClassicalRegister(3, "c")
    qc = QuantumCircuit(qr, cr)

    # 1. Apply Forward QFT
    qc = apply_qft_logic(qc)

    qc.barrier()

    # 2. Apply IQFT (Reverse of QFT)

    # Reverse SWAP
    qc.swap(0, 2)

    # Inverse H on q2
    qc.h(2)

    # Inverse R2 (angle -pi/2) from q2 to q1
    qc.cp(-np.pi / 2, 2, 1)

    # Inverse H on q1
    qc.h(1)

    # Inverse R3 (angle -pi/4) from q2 to q0
    qc.cp(-np.pi / 4, 2, 0)

    # Inverse R2 (angle -pi/2) from q1 to q0
    qc.cp(-np.pi / 2, 1, 0)

    # Inverse H on q0
    qc.h(0)

    qc.barrier()
    qc.measure(qr, cr)
    return qc


def main():
    try:
        # 1. Initialize Service
        print("Initializing IBM Quantum Service...")
        service = QiskitRuntimeService()

        # 2. Select Backend
        backend = service.least_busy(operational=True, simulator=False)
        print(f"Selected Backend: {backend.name}")

        # 3. Create Circuits
        print("Constructing circuits...")
        qc_iqft_in = create_iqft_input_circuit()
        qc_iqft_full = create_full_iqft_circuit()

        # 4. Transpile
        print("Transpiling circuits...")
        pm_in = transpile(qc_iqft_in, backend=backend, optimization_level=3)
        pm_full = transpile(qc_iqft_full, backend=backend, optimization_level=3)

        # 5. Submit Job
        sampler = Sampler(mode=backend)
        pubs = [(pm_in,), (pm_full,)]

        print("Submitting IQFT batch job...")
        job = sampler.run(pubs, shots=1024)
        print(f"Job ID: {job.job_id()}")

        # 6. Wait for results
        result = job.result()

        # Extract counts
        counts_in = result[0].data.c.get_counts()
        counts_out = result[1].data.c.get_counts()

        print("\n=== Results ===")
        print(f"IQFT Input (QFT Output): {counts_in}")
        print(f"Final IQFT Output:       {counts_out}")

        # Verification Logic
        target_count = counts_out.get("101", 0)
        total_shots = sum(counts_out.values())
        print(f"\nVerification: State |101> count = {target_count}/{total_shots}")

        if target_count > (total_shots * 0.5):
            print("✓ Original state |101⟩ recovered successfully")
        else:
            print("⚠ Low fidelity recovery (common in current noisy hardware)")

        # 7. Visualization
        print("Generating histogram...")
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

        # Plot IQFT Input
        plot_histogram(counts_in, ax=ax1)
        ax1.set_title("IQFT Input (QFT Output)")
        ax1.set_ylabel("Counts")

        # Plot IQFT Output
        plot_histogram(counts_out, ax=ax2)
        ax2.set_title("After IQFT (Recovered State)")
        ax2.set_ylabel("Counts")

        fig.suptitle(f"3-Qubit IQFT Results - {backend.name}")
        plt.tight_layout()

        filename = "iqft_3qubit_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    main()
