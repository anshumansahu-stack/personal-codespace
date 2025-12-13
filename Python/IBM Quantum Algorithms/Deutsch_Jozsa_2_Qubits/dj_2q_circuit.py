from qiskit import QuantumCircuit, transpile
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler
from qiskit.visualization import plot_histogram  # Import visualization tool
import matplotlib.pyplot as plt


# ---- Deutsch-Jozsa Circuit Builder ----
def build_dj_circuit(oracle_type):
    """
    Create Deutsch-Jozsa circuit with specified oracle (n=2)
    """
    # Create circuit with 2 working qubits (0,1) + 1 ancilla (2)
    # 2 Classical bits for measurement
    qc = QuantumCircuit(3, 2)

    # Initialize ancilla to |1⟩
    qc.x(2)

    # Apply Hadamard to all qubits (Input superposition + Ancilla setup)
    qc.h([0, 1, 2])
    qc.barrier()

    # ---- Oracle Implementation ----
    if oracle_type == "constant_0":
        # Constant-0: Identity (do nothing)
        pass

    elif oracle_type == "constant_1":
        # Constant-1: Flip ancilla
        qc.x(2)

    elif oracle_type == "balanced":
        # Balanced: f(x) = x0 (CNOT from q0 to q2)
        # If x0 is 0, ancilla stays. If x0 is 1, ancilla flips.
        # This creates a balanced distribution.
        qc.cx(0, 2)

    qc.barrier()

    # Apply Hadamard to working qubits (Interference)
    qc.h([0, 1])
    qc.barrier()

    # Measure working qubits only
    # Note: We measure q0->c0 and q1->c1
    qc.measure([0, 1], [0, 1])

    return qc


# ---- Main Execution ----
if __name__ == "__main__":
    try:
        print("=" * 60)
        print("DEUTSCH-JOZSA ALGO ON IBM QUANTUM HARDWARE")
        print("=" * 60)

        # 1. Initialize IBM Service
        service = QiskitRuntimeService()

        # 2. Select the least busy backend
        print("Searching for the least busy quantum computer...")
        backend = service.least_busy(operational=True, simulator=False)
        print(f"✓ Target Backend: {backend.name}")
        print(f"  (Status: {backend.status().pending_jobs} pending jobs)")

        # 3. Create all three circuits
        print("\nBuilding circuits...")
        tests = [
            ("Constant-0 (Identity)", "constant_0"),
            ("Constant-1 (Bit Flip)", "constant_1"),
            ("Balanced (f=x0)", "balanced"),
        ]

        circuits = []
        for name, type_key in tests:
            qc = build_dj_circuit(type_key)
            circuits.append(qc)

        # 4. Transpile circuits for the specific backend hardware
        print(f"Transpiling {len(circuits)} circuits...")
        transpiled_circuits = transpile(circuits, backend=backend, optimization_level=3)

        # 5. Submit ONE Batch Job
        sampler = Sampler(mode=backend)

        # Prepare inputs for Sampler V2: List of tuples [(qc1,), (qc2,), (qc3,)]
        pubs = [(qc,) for qc in transpiled_circuits]

        print(f"\nSubmitting job to {backend.name}...")
        job = sampler.run(pubs, shots=1024)

        print(f"Job ID: {job.job_id()}")
        print("Waiting for results (queue time depends on backend load)...")

        # 6. Get Results
        result = job.result()
        print("✓ Job completed successfully!")

        # 7. Analyze Results & Prepare Histogram Data
        print("\n" + "=" * 60)
        print("RESULTS ANALYSIS")
        print("=" * 60)

        # Lists to store data for visualization
        all_counts_data = []
        legend_names = []

        for i, (test_name, _) in enumerate(tests):
            # Extract counts from Sampler V2 result
            # Keys are bitstrings like '00', '01', '10', '11'
            counts = result[i].data.c.get_counts()

            # Save data for histogram
            all_counts_data.append(counts)
            legend_names.append(test_name)

            print(f"\nTest Case: {test_name}")
            print(f"Raw Counts: {counts}")

            # Interpret:
            # Ideally: Constant -> '00' (100%), Balanced -> Anything NOT '00'
            # Reality (Noise): We look for the dominant count.

            # Sort counts by frequency to find the winner
            sorted_counts = sorted(counts.items(), key=lambda x: x[1], reverse=True)
            dominant_state, dominant_count = sorted_counts[0]

            total_shots = sum(counts.values())
            probability = dominant_count / total_shots

            print(f"Dominant Outcome: '{dominant_state}' ({probability:.1%} of shots)")

            if (
                dominant_state == "00" or dominant_state == "0"
            ):  # Handle '0' vs '00' formatting
                print("✓ Conclusion: CONSTANT Function")
                print("  (Theory: Constant functions interfere constructively to |00>)")
            else:
                print("✓ Conclusion: BALANCED Function")
                print(
                    "  (Theory: Balanced functions interfere destructively, avoiding |00>)"
                )

        # 8. Generate and Save Histogram
        print("\n" + "=" * 60)
        print("GENERATING HISTOGRAM")
        print("=" * 60)

        # Create the histogram figure
        fig = plot_histogram(
            all_counts_data,
            legend=legend_names,
            title=f"Deutsch-Jozsa Results - {backend.name}",
            figsize=(12, 6),
        )

        # Save the figure to a file
        filename = "deutsch_jozsa_histogram.png"
        fig.savefig(filename)
        print(f"✓ Histogram saved successfully as '{filename}'")

        print("\nExperiment Complete.")

    except Exception as e:
        print(f"\n❌ Error: {e}")
        print("Tip: If this is a network error, check your connection.")
