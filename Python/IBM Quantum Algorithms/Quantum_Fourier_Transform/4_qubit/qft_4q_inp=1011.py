"""
Code 1: 4-Qubit Quantum Fourier Transform (QFT)
Platform: IBM Quantum Runtime Service
Description: Initializes state |1011>, applies QFT, and visualizes the 
             transformation from a computational basis state to a uniform superposition.
"""

import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler

def create_input_circuit():
    """Circuit to measure the initial state |1011>"""
    qr = QuantumRegister(4, 'q')
    cr = ClassicalRegister(4, 'c')
    qc = QuantumCircuit(qr, cr)
    
    # Initialize |1011> (|11>)
    # Qiskit ordering: q3 (MSB), q2, q1, q0 (LSB)
    # |1011> -> q3=1, q2=0, q1=1, q0=1
    qc.x(0)
    qc.x(1)
    # q2 stays 0
    qc.x(3)
    
    qc.barrier()
    qc.measure(qr, cr)
    return qc

def create_qft_circuit():
    """Circuit to apply 4-qubit QFT on |1011>"""
    qr = QuantumRegister(4, 'q')
    cr = ClassicalRegister(4, 'c')
    qc = QuantumCircuit(qr, cr)
    
    # 1. Initialize |1011>
    qc.x(0)
    qc.x(1)
    qc.x(3)
    qc.barrier()
    
    # 2. QFT Implementation
    
    # --- Qubit 0 Block ---
    qc.h(0)
    # Controlled-R2 (pi/2) from q1 to q0
    qc.cp(np.pi/2, 1, 0)
    # Controlled-R3 (pi/4) from q2 to q0
    qc.cp(np.pi/4, 2, 0)
    # Controlled-R4 (pi/8) from q3 to q0
    qc.cp(np.pi/8, 3, 0)
    qc.barrier()
    
    # --- Qubit 1 Block ---
    qc.h(1)
    # Controlled-R2 (pi/2) from q2 to q1
    qc.cp(np.pi/2, 2, 1)
    # Controlled-R3 (pi/4) from q3 to q1
    qc.cp(np.pi/4, 3, 1)
    qc.barrier()
    
    # --- Qubit 2 Block ---
    qc.h(2)
    # Controlled-R2 (pi/2) from q3 to q2
    qc.cp(np.pi/2, 3, 2)
    qc.barrier()
    
    # --- Qubit 3 Block ---
    qc.h(3)
    qc.barrier()
    
    # 3. SWAP Gates (Reverse qubit order)
    qc.swap(0, 3)
    qc.swap(1, 2)
    
    qc.barrier()
    qc.measure(qr, cr)
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
        qc_input = create_input_circuit()
        qc_qft = create_qft_circuit()
        
        # 4. Transpile
        print("Transpiling circuits (Optimization Level 3)...")
        pm_input = transpile(qc_input, backend=backend, optimization_level=3)
        pm_qft = transpile(qc_qft, backend=backend, optimization_level=3)
        
        # 5. Submit Job
        sampler = Sampler(mode=backend)
        pubs = [(pm_input,), (pm_qft,)]
        
        print("Submitting QFT batch job (2048 shots)...")
        job = sampler.run(pubs, shots=2048)
        print(f"Job ID: {job.job_id()}")
        
        # 6. Wait for results
        result = job.result()
        
        # Extract counts (Register 'c')
        counts_input = result[0].data.c.get_counts()
        counts_qft = result[1].data.c.get_counts()
        
        print("\n=== Results ===")
        print(f"Input State Counts: {counts_input}")
        print(f"QFT Output Counts:  {counts_qft}")
        
        # 7. Visualization
        print("Generating histogram...")
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
        
        # Plot Input
        plot_histogram(counts_input, ax=ax1, legend=["Input State |1011⟩"])
        ax1.set_title("Input State Histogram")
        
        # Plot QFT Output
        plot_histogram(counts_qft, ax=ax2, legend=["After QFT"])
        ax2.set_title("QFT Output (Uniform Superposition)")
        
        fig.suptitle(f"4-Qubit QFT Results - {backend.name}")
        plt.tight_layout()
        
        filename = "qft_4qubit_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()