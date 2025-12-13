# Running Deutsch & Deutsch–Jozsa Algorithms on IBM Quantum Hardware

This repository contains implementations and real-hardware executions of the **Deutsch Algorithm** and the **Deutsch–Jozsa Algorithm** using IBM Quantum superconducting processors via Qiskit Runtime.  
The goal of this project is to demonstrate the evolution of a simple quantum decision algorithm and observe how execution outcomes change as the number of qubits and oracle complexity increases on real devices.

**Note:** parts of the code, debugging workflow, and script structuring were assisted by AI tools (Google Gemini 3.0 and Anthropic Claude) for iterative code generation and refinement.

---

## 📌 Overview

Classical computers require multiple evaluations to determine whether a black-box Boolean function is constant or balanced. Quantum algorithms such as **Deutsch** and **Deutsch–Jozsa** reduce this to a **single query**, leveraging superposition and interference.

This repository includes:

- Circuit implementations
- Executions on IBM hardware
- Raw hardware job data (`result.json`, `info.json`)
- Measurement histograms
- Circuit diagrams
- Notes on noise and deviations from ideal theoretical output
- Further Circuit implementations will be uploaded in this repository.

AI-assisted development notes are included in the repository for reproducibility.

---

## 🧪 Included Algorithms

| Algorithm | Qubits Used | Goal | Hardware Executed |
|----------|------------|------|------------------|
| Deutsch Algorithm | 2 | Determine if a function is constant or balanced | ✔ Yes |
| Deutsch–Jozsa (Small) | 2 | Deterministic version of Deutsch algorithm | ✔ Yes |
| Deutsch–Jozsa (Scaled) | 4 | Demonstrate scalability and noise impact | ✔ Yes |

---

## 🛠 Tools & Technologies

- **Qiskit (qiskit-ibm-runtime, qiskit-aer)** — quantum circuit construction and runtime execution  
- **IBM Quantum Backends (example: ibm_fez)** — real superconducting hardware used for execution  
- **Python 3.10+** — execution environment  
- **Matplotlib / Qiskit visualization** — plotting histograms and circuit diagrams  
- **Google Gemini 3.0** — AI-assisted code generation and iteration (structure, helper functions, debugging suggestions)  
- **Anthropic Claude** — AI-assisted code review and refinement (code clarity, error handling, best-practice suggestions)  

> AI tools were used to accelerate development and to generate suggestions; all code, tests, and final decisions were executed and validated locally by the author.

---

## 📂 Repository Structure

IBM-Quantum-Algorithms/
│
├── README.md
│
├── Deutsch-Algorithm/
│ ├── deutsch_circuit.py
│ ├── job-info.json
│ ├── job-result.json
│ ├── circuit_diagram.png
│ └── histogram_result.png
│
├── Deutsch-Jozsa-2Q/
│ ├── dj_2q_circuit.py
│ ├── job-info.json
│ ├── job-result.json
│ ├── circuit_diagram.png
│ └── histogram_result.png
│
└── Deutsch-Jozsa-4Q/
├── dj_4q_circuit.py
├── job-info.json
├── job-result.json
├── circuit_diagram.png
└── histogram_result.png


---

## 📊 Expected vs Hardware Output

| Algorithm | Ideal Output | Notes |
|-----------|--------------|-------|
| Deutsch | `0` for constant, `1` for balanced | Near-perfect on simulator; hardware shows noise effects |
| DJ (2Q) | Single computational basis state with probability ≈1 | Minor noise observed on hardware |
| DJ (4Q) | Unique computational basis peak | Noise increases with circuit depth and qubit connectivity |

---

## 🔍 Observations & Takeaways

- Increasing qubit count and entangling gates results in **greater sensitivity to hardware noise**.
- Hardware execution differs from simulation but still demonstrates interference patterns when mitigation and careful backend selection are applied.
- AI-assisted tools (Gemini 3.0, Claude) accelerated code iteration but experimental validation and final results were produced on real hardware.

---

## 📎 Future Work

- Grover’s Algorithm on hardware  
- Bernstein–Vazirani implementation and benchmarking  
- Quantum Fourier Transform and simple phase-estimation experiments  
- Implementing Shor's Factoring ALgorithm
---

## 📮 Contact

If you are working in quantum computing, research, or education and want to discuss related experiments, feel free to connect.


