# Problem 09: Sum of 3 Numbers

## 📝 Description
A basic utility that takes three integers from the user and calculates their total sum.

## 🏗 Architecture
- **Infrastructure Layer:** `InputReader` ensures that only valid integers are accepted.
- **Domain Layer:** `Calculator` performs the pure mathematical summation logic.
- **Presentation Layer:** `ResultFormatter` handles the visual output of the final sum.

## ⚙️ Logic
- **Formula:** `Total = num1 + num2 + num3`