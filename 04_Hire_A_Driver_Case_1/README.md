# Problem 04: Driver Hiring System (Case 1)

## 📝 Description
A system designed to evaluate job candidates for a driver position based on specific age and licensing criteria.

## 🏗 System Architecture
The solution is built using a **Layered OOP Approach**:
- **Candidate (Model):** Encapsulates candidate data (Age, License status).
- **EligibilityChecker (Business Logic):** Contains the hiring rules (Age > 21 AND Has License).
- **InputReader (Infrastructure):** Handles robust input validation and stream clearing.
- **ResultFormatter (Presentation):** Provides a detailed report with failure reasons if rejected.

## 🛠 Business Rules
- **Minimum Age:** 21 years.
- **Requirement:** Must possess a valid driver's license.
- **Outcome:** Hired only if BOTH criteria are met.