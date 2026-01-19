// Project: Level 1 - Problem 04 (Hire a Driver - Case 1)
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <cctype>   // Required for std::toupper
#include <limits>   // Required for std::numeric_limits
#include <string>

/**
 * @namespace AppType
 * @brief Contains application-specific types and enumerations.
 */
namespace AppType {
	/**
	 * @enum Choice
	 * @brief Represents binary choices (Yes/No) with strong type safety.
	 */
	enum class Choice { Yes, No };

	/**
	 * @enum HiringDecision
	 * @brief Represents the final outcome of the application (Hired or Rejected).
	 */
	enum class HiringDecision { Hired, Rejected };
}

/**
 * @class Utils
 * @brief Utility class containing static helper functions for common tasks.
 */
class Utils {
public:
	/**
	 * @brief Maps a validated character ('Y' or 'N') to the Choice enum.
	 */
	static AppType::Choice MapCharToChoice(char input) {
		return (std::toupper(input) == 'Y') ? AppType::Choice::Yes : AppType::Choice::No;
	}

	/**
	 * @brief Clears the input stream error flags and discards the remaining buffer contents.
	 * @param errorMessage Optional message to display before clearing the stream.
	 */
	static void ClearInputStream(const std::string& errorMessage = "") {
		if (!errorMessage.empty()) {
			std::cout << errorMessage;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

/**
 * @class InputReader
 * @brief Class responsible for handling all user input operations and validation (Input Layer).
 */
class InputReader {
public:
	/**
	 * @brief Prompts for and validates the user's age. Loops until a positive integer is entered.
	 * @return A positive short integer representing the age.
	 */
	static short ReadAge() {
		short age;
		std::cout << "Please enter your age: ";
		while (!(std::cin >> age) || age < 0) {
			Utils::ClearInputStream("Invalid age. Please enter a positive whole number for your age: ");
		}
		Utils::ClearInputStream();
		return age;
	}

	/**
	 * @brief Prompts for and validates a Yes/No question using 'Y' or 'N'.
	 * @param message The question to ask the user.
	 * @return An AppType::Choice value (Yes or No).
	 */
	static AppType::Choice ReadChoice(const std::string& message) {
		char input;
		while (true) {
			std::cout << message;
			if (std::cin >> input) {
				input = std::toupper(input);
				if (input == 'Y' || input == 'N') {
					Utils::ClearInputStream();
					return Utils::MapCharToChoice(input);
				}
			}
			Utils::ClearInputStream("Invalid input. Please enter only Y or N: ");
		}
	}
};

/**
 * @class Candidate
 * @brief Class representing the data entity for the employment application (Data Model Layer).
 */
class Candidate {
private:
	short _age;
	AppType::Choice _hasLicense;

public:
	/**
	 * @brief Constructor: Initializes a Candidate object.
	 */
	Candidate(short age, AppType::Choice hasLicense) : _age(age), _hasLicense(hasLicense) {}

	// Getters (const for data safety)
	short GetAge() const { return _age; }
	AppType::Choice GetHasLicense() const { return _hasLicense; }
};

/**
 * @class EligibilityChecker
 * @brief Responsible for defining and applying the hiring criteria logic (Business Logic Layer).
 */
class EligibilityChecker {
public:
	// Constant representing the rule (minimum age requirement).
	static constexpr short MIN_AGE = 21;

	/**
	 * @brief Checks if the candidate meets the hiring criteria.
	 * CRITERIA: (Age > 21 AND Has License is Yes).
	 */
	static AppType::HiringDecision CheckEligibility(const Candidate& candidate) {
		bool isEligible = (candidate.GetAge() > MIN_AGE &&
			candidate.GetHasLicense() == AppType::Choice::Yes);

		return isEligible ? AppType::HiringDecision::Hired : AppType::HiringDecision::Rejected;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for converting internal types to displayable strings (Presentation Layer).
 */
class ResultFormatter {
public:
	/**
	 * @brief Prints the final hiring decision and specific rejection reasons.
	 */
	static void PrintResult(const Candidate& candidate, AppType::HiringDecision decision) {
		std::cout << "\n--- Hiring Eligibility Report ---\n";
		std::cout << "Age: " << candidate.GetAge() << "\n";
		std::cout << "License: " << (candidate.GetHasLicense() == AppType::Choice::Yes ? "Yes" : "No") << "\n";
		std::cout << "---------------------------------\n";

		if (decision == AppType::HiringDecision::Hired) {
			std::cout << "RESULT: HIRED\n";
		}
		else {
			std::cout << "RESULT: REJECTED\n";
			if (candidate.GetAge() <= EligibilityChecker::MIN_AGE)
				std::cout << "- Reason: Age must be strictly greater than " << EligibilityChecker::MIN_AGE << ".\n";
			if (candidate.GetHasLicense() == AppType::Choice::No)
				std::cout << "- Reason: Driver's license is required.\n";
		}
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates the overall flow of the application (Control Layer).
 */
class ApplicationFlow {
public:
	/**
	 * @brief Runs the main logic: Input -> Process -> Output.
	 */
	void Run() {
		std::cout << "\n--- Driver Employment Eligibility Checker ---\n";

		short age = InputReader::ReadAge();
		AppType::Choice hasLicense = InputReader::ReadChoice("Do you have a license? (Y/N): ");

		Candidate candidate(age, hasLicense);
		AppType::HiringDecision decision = EligibilityChecker::CheckEligibility(candidate);

		ResultFormatter::PrintResult(candidate, decision);
	}
};

/**
 * @brief Main function, the program entry point.
 */
int main() {
	ApplicationFlow app;
	app.Run();
	return 0;
}