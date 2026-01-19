# Problem 03: Even or Odd Number Checker

## 📝 Task
Write a program that asks the user for a number and determines if it is Even or Odd.

## 🏗 System Design
For this solution, I implemented:
1. **Enum Class (`AppType::Parity`):** To represent the state of the number safely.
2. **Business Logic (`NumberChecker`):** Independent logic to check parity using the modulus operator.
3. **Input Validation:** A loop that ensures the user enters a valid integer, handling stream errors.

## 🛠 Logic Breakdown
- Input: `int`
- Process: `number % 2 == 0`
- Output: `string` ("Even" or "Odd")