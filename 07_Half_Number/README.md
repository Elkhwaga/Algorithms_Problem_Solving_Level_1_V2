# Problem 07: Half of a Number

## 📝 Description
A simple utility to calculate exactly half of any given number (integer or decimal).

## 🏗 Architectural Overview
- **Precision Handling:** Uses `double` throughout the application to ensure that odd numbers (like 5) result in correct decimals (2.5) rather than truncated integers.
- **Robust Input:** The `InputReader` ensures the program doesn't crash or enter an infinite loop when receiving non-numeric characters.
- **Pure Logic:** `Calculator` is decoupled from I/O, making the logic testable.

## ⚙️ Mathematical Logic
- Result = Input / 2.0