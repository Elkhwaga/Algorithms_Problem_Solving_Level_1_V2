# Problem 12 - Max of 2 Numbers

## 📖 Problem Statement
Write a program that asks the user to enter **two numbers** and prints the **maximum** of the two.

## Example
**Input:**
10
20

**Output:**
20

---

## 🛠 Core Concepts

* **OOP (Object-Oriented Programming):** Classes encapsulate logic and responsibilities.
* **Templates:** Generic `MaxCalculator` works for any numeric type.
* **Layered Architecture:** Separation of concerns between:
  * **Input Layer:** `InputHandler` handles validated user input.
  * **Business Logic Layer:** `MaxCalculator` determines the maximum value.
  * **Control Layer:** `ApplicationFlow` orchestrates execution.
* **Infrastructure Layer:** `Utils` handles input stream clearing and error recovery.

---

## 💡 Solution Approach

1. **Input Validation:** `InputHandler::readNumber` ensures the user inputs a valid number.
2. **Business Rule:** `MaxCalculator<T>::getMax(first, second)` computes the maximum value.
3. **Execution Orchestration:** `ApplicationFlow::run()` manages the sequence:
   * Read first number
   * Read second number
   * Compute max
   * Display result

This design ensures **maintainability**, **reusability**, and **clean separation** of concerns.

---

## 📂 Folder Structure

12_Max_Of_2_Numbers/
│
├─ 12_Max_Of_2_Numbers.cpp # Main C++ solution
└─ README.md # This documentation