# Problem 06: Print Full Name

## 📝 Description
Collects, sanitizes, and displays user names using an Object-Oriented approach.

## 🏗 Architecture Highlights
- **Immutable Data Model:** The `Person` class is designed without setters to ensure data consistency.
- **Advanced Sanitization:** Uses `std::find_if` for efficient whitespace trimming (Left/Right).
- **Flexible Presentation:** Supports both Normal and Reverse name formatting via Enums.

## ⚙️ Logic Flow
1. **Input:** `InputReader` captures and trims user strings.
2. **Entity:** `Person` object stores validated data.
3. **Display:** `Presenter` formats the output based on `FormatName` criteria.