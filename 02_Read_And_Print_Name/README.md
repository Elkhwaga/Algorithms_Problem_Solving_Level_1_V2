# Problem 02: Read and Print Name

## 📝 Description
A program that prompts the user to enter their first and last name, then displays the full name on the console.

## 🛠 Features in this implementation:
- **Input Validation:** Ensures name is not empty and has a minimum length.
- **String Cleaning:** Uses a `Utils` class to trim leading and trailing spaces.
- **Layered OOP:** Separation between Data, Input, and Presentation.

## ⚙️ Logic Flow
1. `ApplicationFlow` calls `InputReader`.
2. `InputReader` gets data, uses `Utils::Trim`, and validates.
3. `Person` object is created with cleaned data.
4. `Presenter` outputs the formatted result.