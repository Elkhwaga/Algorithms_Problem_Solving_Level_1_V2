# Problem 10: Average of 3 Marks

## 📝 Description
A high-precision utility designed to calculate the arithmetic mean of three academic marks.

## 🏗 Architecture
- **Layered Design:** Strict separation between input validation, math logic, and output formatting.
- **Code Reusability:** The `calculateAverage` method internally leverages `calculateTotal` to minimize redundancy.
- **Precision Management:** Utilizes `double` types and `<iomanip>` to provide professional-grade reports.

## ⚙️ Logic Rule
- **Formula:** `(Mark1 + Mark2 + Mark3) / 3.0`
- **Output:** Rounded to 2 decimal places.