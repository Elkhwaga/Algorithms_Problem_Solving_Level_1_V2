# C++ Problem Solving - Level 1 (Advanced Approach)

In this repository, I solve the 50 problems of Level 1, but with a focus on **Software Engineering Principles** rather than just getting the output.

## Problem 01: Print Your Name
### The Challenge
Simply print a name to the console.

### My Engineering Solution
Instead of a simple `cout`, I implemented a **Layered Architecture**:
- **Data Model (Person Class):** Encapsulates the data.
- **Presentation Layer (Presenter Class):** Separates the output logic.
- **Controller (ApplicationFlow):** Orchestrates the process.

**Why this way?** To ensure the code is scalable and follows the **Separation of Concerns** principle from day one.