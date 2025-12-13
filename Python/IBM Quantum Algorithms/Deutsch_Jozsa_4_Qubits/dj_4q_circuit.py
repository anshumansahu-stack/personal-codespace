from qiskit import QuantumCircuit, transpile
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler
from qiskit.visualization import plot_histogram  # Import visualization tool
import matplotlib.pyplot as plt  # Import matplotlib


# ---- 4-Qubit Deutsch-Jozsa Circuit Builder ----
def build_dj_circuit_4q(oracle_type):
    """
    Constructs a Deutsch-Jozsa circuit with 4 input qubits + 1 ancilla.
    Total Qubits: 5 (q0, q1, q2, q3, q4)
    Measurement: 4 bits (c0, c1, c2, c3)
    """
    # 5 Quantum bits, 4 Classical bits
    qc = QuantumCircuit(5, 4)

    # 1. Initialize Ancilla (q4) to |1⟩
    qc.x(4)

    # 2. Apply Hadamard to ALL qubits (Inputs + Ancilla)
    qc.h([0, 1, 2, 3, 4])
    qc.barrier()

    # 3. Oracle Implementation
    if oracle_type == "constant_0":
        # Constant-0: Identity
        pass

    elif oracle_type == "constant_1":
        # Constant-1: Flip ancilla
        qc.x(4)

    elif oracle_type == "balanced":
        # Balanced Function: f(x) = x1 ⊕ x2
        # We wrap the inputs x1 (q1) and x2 (q2) with CNOTs targeting the ancilla (q4)
        qc.cx(1, 4)
        qc.cx(2, 4)

    qc.barrier()

    # 4. Apply Hadamard to Input qubits only
    qc.h([0, 1, 2, 3])
    qc.barrier()

    # 5. Measure Input qubits
    # Map q0->c0, q1->c1, q2->c2, q3->c3
    qc.measure([0, 1, 2, 3], [0, 1, 2, 3])

    return qc


# ---- Main Execution ----
if __name__ == "__main__":
    try:
        print("=" * 70)
        print("4-QUBIT DEUTSCH-JOZSA ON IBM QUANTUM HARDWARE")
        print("=" * 70)

        # 1. Initialize Service
        service = QiskitRuntimeService()

        # 2. Find least busy backend (Must have at least 5 qubits)
        print("Searching for available backend with >= 5 qubits...")
        backend = service.least_busy(
            operational=True, simulator=False, min_num_qubits=5
        )
        print(f"✓ Selected Backend: {backend.name}")
        print(f"  (Pending Jobs: {backend.status().pending_jobs})")

        # 3. Create Circuits
        print("\nBuilding circuits...")
        tests = [
            ("Constant-0 (Identity)", "constant_0"),
            ("Constant-1 (Bit Flip)", "constant_1"),
            ("Balanced (f = x1 XOR x2)", "balanced"),
        ]

        circuits = []
        for name, o_type in tests:
            qc = build_dj_circuit_4q(o_type)
            circuits.append(qc)

        # 4. Transpile
        print(f"Transpiling {len(circuits)} circuits for {backend.name}...")
        # Optimization level 3 helps reduce depth/noise
        transpiled_circuits = transpile(circuits, backend=backend, optimization_level=3)

        # 5. Batch Submit (Prevents 500 Errors)
        sampler = Sampler(mode=backend)

        # Create inputs for V2: [(qc1,), (qc2,), (qc3,)]
        pubs = [(qc,) for qc in transpiled_circuits]

        print(f"\nSubmitting batch job to {backend.name}...")
        job = sampler.run(pubs, shots=1024)

        print(f"Job ID: {job.job_id()}")
        print("Waiting for results (this may take a few minutes)...")

        # 6. Retrieve Results
        result = job.result()
        print("✓ Job completed!")

        # 7. Analyze Results
        print("\n" + "=" * 70)
        print("RESULTS ANALYSIS")
        print("=" * 70)

        # Lists to store data for visualization
        all_counts_data = []
        legend_names = []

        for i, (test_name, _) in enumerate(tests):
            # Access count data
            counts = result[i].data.c.get_counts()

            # Store for histogram
            all_counts_data.append(counts)
            legend_names.append(test_name)

            print(f"\nTest Case: {test_name}")

            # Find the most frequent measurement
            sorted_counts = sorted(counts.items(), key=lambda x: x[1], reverse=True)
            dominant_state, dominant_count = sorted_counts[0]

            # Format bits for display
            # Qiskit is Little Endian: State '0110' means q3=0, q2=1, q1=1, q0=0
            print(f"Dominant Outcome: |{dominant_state}⟩")
            print(f"Frequency: {dominant_count}/1024 shots")

            # Interpretation Logic
            # Theory: Constant -> |0000⟩
            # Theory: Balanced -> Anything EXCEPT |0000⟩

            # We use a threshold because of noise. If '0000' is the clear winner, it's Constant.
            if dominant_state == "0000" or dominant_state == "0":
                print("-> Conclusion: CONSTANT Function")
            else:
                print("-> Conclusion: BALANCED Function")

                # Detailed check for the balanced case (x1 XOR x2)
                # Theory predicts: q1 and q2 should be |1⟩.
                # Bitstring should be '0110' (q3 q2 q1 q0)
                if dominant_state == "0110":
                    print(
                        "   (Matches theoretical prediction for f = x1 ^ x2 perfectly!)"
                    )
                else:
                    print(
                        f"   (Result is balanced, but noise affected the specific bitstring)"
                    )
        
        # 8. Generate and Save Histogram
        print("\n" + "=" * 70)
        print("GENERATING HISTOGRAM")
        print("=" * 70)

        # Create the histogram figure
        # figsize is larger here because 4 qubits have 16 possible states
        fig = plot_histogram(
            all_counts_data, 
            legend=legend_names, 
            title=f"4-Qubit Deutsch-Jozsa Results - {backend.name}",
            figsize=(12, 7) 
        )
        
        # Save the figure to a file
        filename = "dj_4qubit_histogram.png"
        fig.savefig(filename)
        print(f"✓ Histogram saved successfully as '{filename}'")

        print("\nExperiment Complete.")

    except Exception as e:
        print(f"\n❌ Error: {e}")