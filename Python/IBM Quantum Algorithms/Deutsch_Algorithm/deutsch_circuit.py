from qiskit import QuantumCircuit, transpile
from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2 as Sampler
from qiskit.visualization import plot_histogram  # Import visualization tool
import matplotlib.pyplot as plt  # Import matplotlib to handle the figure


# ---- Oracle definitions ----
def oracle_constant_0(qc):
    pass


def oracle_constant_1(qc):
    qc.x(1)


def oracle_balanced_identity(qc):
    qc.cx(0, 1)


def oracle_balanced_not(qc):
    qc.x(0)
    qc.cx(0, 1)
    qc.x(0)


# ---- Deutsch Circuit Builder ----
def build_deutsch_circuit(oracle):
    qc = QuantumCircuit(2, 1)
    qc.x(1)
    qc.h(0)
    qc.h(1)
    qc.barrier()
    oracle(qc)
    qc.barrier()
    qc.h(0)
    qc.measure(0, 0)
    return qc


# ---- Main Execution ----
if __name__ == "__main__":
    # 1. Initialize Service
    service = QiskitRuntimeService()

    # 2. Select the least busy backend automatically
    print("Finding the least busy backend...")
    backend = service.least_busy(operational=True, simulator=False)
    print(f"✓ Selected Backend: {backend.name}")

    # 3. Prepare all 4 circuits
    tests = [
        ("Constant 0", oracle_constant_0),
        ("Constant 1", oracle_constant_1),
        ("Balanced Identity", oracle_balanced_identity),
        ("Balanced NOT", oracle_balanced_not),
    ]

    circuits = []
    print("\nPreparing circuits...")
    for name, oracle in tests:
        qc = build_deutsch_circuit(oracle)
        circuits.append(qc)

    # 4. Transpile all circuits at once
    print(f"Transpiling circuits for {backend.name}...")
    transpiled_circuits = transpile(circuits, backend=backend, optimization_level=3)

    # 5. Submit ONE job containing ALL circuits (Batching)
    sampler = Sampler(mode=backend)

    # Format for V2: List of tuples [(qc1,), (qc2,), ...]
    pubs = [(qc,) for qc in transpiled_circuits]

    print(f"\nSubmitting batch job (4 circuits) to {backend.name}...")
    job = sampler.run(pubs, shots=1024)
    print(f"Job ID: {job.job_id()}")
    print("Waiting for results...")

    try:
        # 6. Get Results
        result = job.result()
        print("\n" + "=" * 60)
        print("FINAL RESULTS")
        print("=" * 60)

        # List to store data for the histogram
        all_counts_data = []
        legend_names = []

        for i, (test_name, _) in enumerate(tests):
            # Extract data for the specific circuit
            counts = result[i].data.c.get_counts()

            # Save for histogram
            all_counts_data.append(counts)
            legend_names.append(test_name)

            # Count the outcomes
            count_0 = counts.get("0", 0)
            count_1 = counts.get("1", 0)

            print(f"\nTest: {test_name}")
            print(f"Counts: {counts}")

            # Logic: If 0 is dominant -> Constant. If 1 is dominant -> Balanced.
            if count_0 > count_1:
                print(f"✓ Conclusion: CONSTANT function (Theory: Constant)")
            else:
                print(f"✓ Conclusion: BALANCED function (Theory: Balanced)")

        # 7. Generate and Save Histogram
        print("\n" + "=" * 60)
        print("GENERATING HISTOGRAM")
        print("=" * 60)

        # Create the histogram figure
        fig = plot_histogram(
            all_counts_data,
            legend=legend_names,
            title=f"Deutsch Algorithm Results - {backend.name}",
            figsize=(10, 6),
        )

        # Save the figure to a file
        filename = "deutsch_histogram_results.png"
        fig.savefig(filename)
        print(f"✓ Histogram saved successfully as '{filename}'")

        # Optional: If you are in a local environment with a display, you can uncomment the next line:
        # plt.show()

    except Exception as e:
        print(f"Error retrieving results: {e}")
