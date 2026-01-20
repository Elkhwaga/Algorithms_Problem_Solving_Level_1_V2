# Problem 08: Mark Pass/Fail

## 📝 Description
Evaluates a student's mark based on a predefined passing threshold.

## 🏗 Key Features
- **Range Validation:** Ensures input marks are strictly between 0 and 100.
- **Enumerated Status:** Uses `ResultStatus` enum to avoid magic strings and ensure type safety.
- **Separated Presentation:** Distinguishes between data formatting (`ResultFormatter`) and actual console output (`ConsolePrinter`).

## ⚙️ Logic Rules
- **Threshold:** 50.0
- **Pass:** Mark >= 50
- **Fail:** Mark < 50