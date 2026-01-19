# Problem 04: Hire a Driver (Case 1)

## 📝 Overview
This program evaluates a candidate's eligibility for a driving job based on their **age** and **license status**.

## 🏗 Applied Principles
- **Data Encapsulation:** Using the `Candidate` class to protect data.
- **Input Security:** `InputReader` ensures only valid data types reach the logic layer.
- **Business Logic Isolation:** `EligibilityChecker` holds the rules, making it easy to change the minimum age in one place.
- **Doxygen Documentation:** Full code documentation using professional tags (`@brief`, `@param`, `@class`).

## ⚙️ Hiring Rules
- **Age:** Must be > 21.
- **License:** Must be "Yes".