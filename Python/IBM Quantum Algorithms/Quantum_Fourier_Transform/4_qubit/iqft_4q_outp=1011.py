"""
Code 2: 4-Qubit Inverse Quantum Fourier Transform (IQFT)
Platform: IBM Quantum Runtime Service
Description: Applies QFT to |1011> to create superposition, then applies IQFT 
             to recover the original state.
"""

import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.visualization import plot_histogram
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler

def apply_qft_logic(qc):
    """Helper to apply forward QFT logic (without measurement) to prepare input state"""
    # 1. Initialize |1011>
    qc.x(0)
    qc.x(1)
    qc.x(3)
    qc.barrier()
    
    # 2. Forward QFT
    qc.h(0)
    qc.cp(np.pi/2, 1, 0)
    qc.cp(np.pi/4, 2, 0)
    qc.cp(np.pi/8, 3, 0)
    qc.h(1)
    qc.cp(np.pi/2, 2, 1)
    qc.cp(np.pi/4, 3, 1)
    qc.h(2)
    qc.cp(np.pi/2, 3, 2)
    qc.h(3)
    qc.swap(0, 3)
    qc.swap(1, 2)
    return qc

def create_iqft_input_circuit():
    """Applies QFT and measures immediately (Input to IQFT)"""
    qr = QuantumRegister(4, 'q')
    cr = ClassicalRegister(4, 'c')
    qc = QuantumCircuit(qr, cr)
    
    qc = apply_qft_logic(qc)
    
    qc.barrier()
    qc.measure(qr, cr)
    return qc

def create_full_iqft_circuit():
    """Applies QFT then IQFT to recover original state"""
    qr = QuantumRegister(4, 'q')
    cr = ClassicalRegister(4, 'c')
    qc = QuantumCircuit(qr, cr)
    
    # 1. Apply Forward QFT (Prepare State)
    qc = apply_qft_logic(qc)
    
    qc.barrier()
    
    # 2. Apply IQFT (Reverse of QFT)
    
    # --- Reverse SWAP Gates ---
    qc.swap(0, 3)
    qc.swap(1, 2)
    
    # --- Reverse Qubit 3 Block ---
    qc.h(3)
    # Inverse R2 (-pi/2) from q3 to q2
    qc.cp(-np.pi/2, 3, 2)
    
    # --- Reverse Qubit 2 Block ---
    qc.h(2)
    # Inverse R3 (-pi/4) from q3 to q1
    qc.cp(-np.pi/4, 3, 1)
    # Inverse R2 (-pi/2) from q2 to q1
    qc.cp(-np.pi/2, 2, 1)
    
    # --- Reverse Qubit 1 Block ---
    qc.h(1)
    # Inverse R4 (-pi/8) from q3 to q0
    qc.cp(-np.pi/8, 3, 0)
    # Inverse R3 (-pi/4) from q2 to q0
    qc.cp(-np.pi/4, 2, 0)
    # Inverse R2 (-pi/2) from q1 to q0
    qc.cp(-np.pi/2, 1, 0)
    
    # --- Reverse Qubit 0 Block ---
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
        print("Selecting least busy operational backend...")
        backend = service.least_busy(operational=True, simulator=False)
        print(f"Selected Backend: {backend.name}")
        
        # 3. Create Circuits
        print("Constructing circuits...")
        qc_iqft_in = create_iqft_input_circuit()
        qc_iqft_full = create_full_iqft_circuit()
        
        # 4. Transpile
        print("Transpiling circuits (Optimization Level 3)...")
        pm_in = transpile(qc_iqft_in, backend=backend, optimization_level=3)
        pm_full = transpile(qc_iqft_full, backend=backend, optimization_level=3)
        
        # 5. Submit Job
        sampler = Sampler(mode=backend)
        pubs = [(pm_in,), (pm_full,)]
        
        print("Submitting IQFT batch job (2048 shots)...")
        job = sampler.run(pubs, shots=2048)
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
        target_count = counts_out.get('1011', 0)
        total_shots = sum(counts_out.values())
        print(f"\nVerification: State |1011> count = {target_count}/{total_shots}")
        
        if target_count > (total_shots * 0.5):
             print("✓ Original state |1011⟩ recovered successfully")
        else:
             print("⚠ Low fidelity recovery (Result may be affected by noise on real hardware)")

        # 7. Visualization
        print("Generating histogram...")
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
        
        # Plot IQFT Input
        plot_histogram(counts_in, ax=ax1, legend=["IQFT Input (QFT Output)"])
        ax1.set_title("IQFT Input (Uniform Superposition)")
        
        # Plot IQFT Output
        plot_histogram(counts_out, ax=ax2, legend=["After IQFT"])
        ax2.set_title("IQFT Output (Recovered State)")
        
        fig.suptitle(f"4-Qubit IQFT Results - {backend.name}")
        plt.tight_layout()
        
        filename = "iqft_4qubit_results.png"
        plt.savefig(filename)
        print(f"Plot saved to {filename}")
        plt.show()

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()