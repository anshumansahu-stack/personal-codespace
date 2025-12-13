"""
Code 1: 3-Qubit Quantum Fourier Transform (QFT)
Platform: IBM Quantum Runtime Service
"""

import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler


def create_input_circuit():
    """Circuit to measure the initial state |101>"""
    qr = QuantumRegister(3, "q")
    cr = ClassicalRegister(3, "c")
    qc = QuantumCircuit(qr, cr)

    # Initialize |101> (|5>)
    # Qiskit ordering: q2 (MSB), q1, q0 (LSB)
    # |101> -> q2=1, q1=0, q0=1
    qc.x(0)
    qc.x(2)

    qc.barrier()
    qc.measure(qr, cr)
    return qc


def create_qft_circuit():
    """Circuit to apply QFT on |101>"""
    qr = QuantumRegister(3, "q")
    cr = ClassicalRegister(3, "c")
    qc = QuantumCircuit(qr, cr)

    # 1. Initialize |101>
    qc.x(0)
    qc.x(2)
    qc.barrier()

    # 2. QFT Implementation
    # Apply Hadamard to qubit 0
    qc.h(0)
    # Controlled-R2 (pi/2) from q1 to q0
    qc.cp(np.pi / 2, 1, 0)
    # Controlled-R3 (pi/4) from q2 to q0
    qc.cp(np.pi / 4, 2, 0)

    qc.barrier()

    # Apply Hadamard to qubit 1
    qc.h(1)
    # Controlled-R2 (pi/2) from q2 to q1
    qc.cp(np.pi / 2, 2, 1)

    qc.barrier()

    # Apply Hadamard to qubit 2
    qc.h(2)

    qc.barrier()

    # 3. SWAP gates (Reverse order)
    qc.swap(0, 2)

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
        qc_input = create_input_circuit()
        qc_qft = create_qft_circuit()

        # 4. Transpile
        print("Transpiling circuits...")
        pm_input = transpile(qc_input, backend=backend, optimization_level=3)
        pm_qft = transpile(qc_qft, backend=backend, optimization_level=3)

        # 5. Submit Job
        sampler = Sampler(mode=backend)
        # Prepare inputs as a list of tuples (circuit,)
        pubs = [(pm_input,), (pm_qft,)]

        print("Submitting QFT batch job...")
        job = sampler.run(pubs, shots=1024)
        print(f"Job ID: {job.job_id()}")

        # 6. Wait for results
        result = job.result()

        # Extract counts (Classical register is named 'c')
        counts_input = result[0].data.c.get_counts()
        counts_qft = result[1].data.c.get_counts()

        print("\n=== Results ===")
        print(f"Input State Counts: {counts_input}")
        print(f"QFT Output Counts:  {counts_qft}")

        # 7. Visualization
        print("Generating histogram...")
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

        # Plot Input
        plot_histogram(counts_input, ax=ax1)
        ax1.set_title("Input State |101⟩")
        ax1.set_ylabel("Counts")

        # Plot QFT Output
        plot_histogram(counts_qft, ax=ax2)
        ax2.set_title("After QFT (Fourier Basis)")
        ax2.set_ylabel("Counts")

        fig.suptitle(f"3-Qubit QFT Results - {backend.name}")
        plt.tight_layout()

        filename = "qft_3qubit_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    main()
