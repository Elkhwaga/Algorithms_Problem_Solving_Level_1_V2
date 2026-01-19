# Problem 05: Hire a Driver (Case 2)

## 📝 Description
An advanced hiring evaluation system that introduces an **Alternative Path** for eligibility. A candidate can now be hired regardless of age or license if they possess a recommendation.

## 🏗 Engineering Design (OOP)
- **Candidate Model:** Updated to include `_hasRecommendation`.
- **Eligibility Logic:** Implements the `OR` logic between the basic requirements and the recommendation status.
- **Detailed Reporting:** The `ResultFormatter` now breaks down exactly why a candidate was rejected across both possible hiring paths.

## ⚙️ Business Rules
A candidate is **HIRED** if:
1.  (Age > 21 **AND** Has License)
2.  **OR** (Has Recommendation)