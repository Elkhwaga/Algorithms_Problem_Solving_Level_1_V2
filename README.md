# 🚀 C++ Programming Journey – Engineering Approach

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B)
![OOP](https://img.shields.io/badge/OOP-Object%20Oriented-success?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Architecture-Layered-informational?style=for-the-badge)
![Clean Code](https://img.shields.io/badge/Clean%20Code-Principles-brightgreen?style=for-the-badge)
![Engineering Mindset](https://img.shields.io/badge/Mindset-Engineering%20First-black?style=for-the-badge)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202026-purple?style=for-the-badge)

---

## 📌 Overview

This repository contains **Level 1 C++ problem-solving challenges**, implemented using a **Software Engineering mindset**, not just basic coding.

Each problem is treated as a **mini software system**, applying:
- Object-Oriented Programming (OOP)
- Clean Code principles
- Separation of Concerns
- Layered Architecture

The goal is to build **strong engineering fundamentals** from the very first level.

---

## 🧠 Architectural Philosophy

The project follows a **Layered Architecture** to keep responsibilities clear and code maintainable:

### 🔹 Input Layer
Responsible for:
- Reading user input
- Validating data
- Recovering input streams  
Examples: `InputHandler`, `InputReader`

### 🔹 Business / Domain Layer
Encapsulates core logic and rules  
Examples:
- `MaxCalculator`
- `EligibilityChecker`
- `AreaCalculator`

### 🔹 Infrastructure Layer
Low-level utilities shared across the system  
Examples: `Utils`, stream helpers

### 🔹 Application Flow (Control Layer)
Coordinates execution without containing business logic  
Example: `ApplicationFlow`

## 📂 Problem Index

| # | Problem Title | Core Concepts | Solution Link |
| :--- | :--- | :--- | :--- |
| 01 | Print Your Name | OOP Basics, Layered Design | [View Code](./01_Print_Your_Name/01_Print_Your_Name.cpp) |
| 02 | Read & Print Name | Input Validation, String Trimming | [View Code](./02_Read_And_Print_Name/02_Read_And_Print_Name.cpp) |
| 03 | Odd or Even | Enums, Namespaces, Error Handling | [View Code](./03_Check_Even_Odd_Number/03_Check_Even_Odd_Number.cpp) |
| 04 | Hire a Driver (Case 1) | Business Logic Isolation, Multi-Criteria Validation | [View Code](./04_Hire_A_Driver_Case_1/04_Hire_A_Driver_Case_1.cpp) |
| 05 | Hire a Driver (Case 2) | Logic Branching (OR), Complex Eligibility Rules | [View Code](./05_Hire_A_Driver_Case_2/05_Hire_A_Driver_Case_2.cpp) |
| 06 | Print Full Name | Immutable Objects, STL Trimming (find_if) | [View Code](./06_Full_Name/06_Full_Name.cpp) |
| 07 | Half of a Number | Floating Point Precision, Input Stream Recovery | [View Code](./07_Half_Number/07_Half_Number.cpp) |
| 08 | Mark Pass/Fail | Range Validation, Enum-based Status, Strict Layering | [View Code](./08_Mark_Pass_Fail/08_Mark_Pass_Fail.cpp) |
| 09 | Sum of 3 Numbers | Layered Calculation, Input Stream Management | [View Code](./09_Sum_Of_3_Numbers/09_Sum_Of_3_Numbers.cpp) |
| 10 | Average of 3 Marks | Logic Reusability, Precision Formatting (iomanip) | [View Code](./10_Average_Of_3_Marks/10_Average_Of_3_Marks.cpp) |
| 11 | Average Pass/Fail | OOP Layered Architecture, Input Validation, Enum-based Status, Repeatable Flow | [View Code](./11_Average_Pass_Fail/11_Average_Pass_Fail.cpp) |
| 12 | Max of 2 Numbers | Input Validation, Templated Class, Layered OOP | [View Code](./12_Max_of_2_Numbers/12_Max_of_2_Numbers.cpp) |
| 13 | Max of 3 Numbers | Layered OOP, Template Methods, Input Validation | [View Code](./13_Max_of_3_Numbers/13_Max_of_3_Numbers.cpp) |
| 14 | Swap Numbers | Layered OOP, Templates, Input Validation | [View Code](./14_Swap_Numbers/14_Swap_Numbers.cpp) |
| 15 | Rectangle Area | Input Validation, Layered OOP, Domain Encapsulation | [View Code](./14_Swap_Numbers/14_Swap_Numbers.cpp) |

---

## ▶️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/Elkhwaga/Algorithms_Problem_Solving_Level_1_V2.git
2. Open the solution or desired `.cpp` file using **Visual Studio Community 2026**
3. Each problem has:
- Separate folder
- Clean .cpp file
- Dedicated README.md

4. Build & Run any problem independently

---

## 🏗 Project Structure
- Each problem is self-contained
- No shared global state
- Independent build & execution
- Focus on readability over tricks

---

## 🎯 Learning Goals
- Master C++ fundamentals and STL
- Practice Clean Code from day one
- Think in rules, layers, and responsibilities
- Build a strong base for advanced OOP & Architecture

---

## 👨‍💻 Author

- Mohamed Elkhwaga
- Aspiring Software Engineer
- Learning by building real, structured systems 🚀

*Developed with ❤️ as part of my learning journey in Software Engineering.*