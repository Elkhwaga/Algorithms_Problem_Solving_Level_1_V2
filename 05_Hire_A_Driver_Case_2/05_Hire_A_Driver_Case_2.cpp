// Project: Level 1 - Problem 05 (Hire a Driver - Case 2)
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
	static AppType::Choice mapCharToChoice(char input) {
		// Assumption: input is already validated and converted to uppercase.
		return (input == 'Y') ? AppType::Choice::Yes : AppType::Choice::No;
	}

	/**
	 * @brief Clears the input stream error flags and discards the remaining buffer contents.
	 * @param message Optional message to display before clearing the stream.
	 */
	static void clearInputStream(std::string message = "") {
		if (!message.empty()) {
			std::cout << message;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

/**
 * @class InputReader
 * @brief Class responsible for handling all user input operations and validation.
 * Ensures secure and type-safe data acquisition.
 */
class InputReader {
public:
	/**
	 * @brief Prompts for and validates the user's age. Loops until a positive integer is entered.
	 * @return A positive short integer representing the age.
	 */
	static short readAge() {
		short age;
		std::cout << "Please enter your age: ";
		// Input validation loop for positive integer age.
		while (!(std::cin >> age) || age < 0) {
			Utils::clearInputStream("Invalid age. Please enter a positive whole number for your age: ");
		}
		// Clear the remaining buffer ('\n') after successful input.
		Utils::clearInputStream();

		return age;
	}

	/**
	 * @brief Prompts for and validates a Yes/No question using 'Y' or 'N'.
	 * @param message The question to ask the user.
	 * @return An AppType::Choice value (Yes or No).
	 */
	static AppType::Choice readChoice(std::string message) {
		char input;
		std::cout << message;

		// Input validation loop for 'Y' or 'N'.
		while (true) {
			if (!(std::cin >> input)) {
				Utils::clearInputStream("Input stream failed. Please try again: ");
				continue;
			}

			input = std::toupper(input);

			if (input == 'Y' || input == 'N') {
				Utils::clearInputStream();
				return Utils::mapCharToChoice(input);
			}
			else {
				Utils::clearInputStream("Invalid input. Please enter only Y or N: ");
			}
		}
	}
};

/**
 * @class Candidate
 * @brief Class representing the data entity for the employment application.
 * Contains only data fields and getters (Data Model Layer).
 */
class Candidate {
private:
	short _age;
	AppType::Choice _hasLicense;
	AppType::Choice _hasRecommendation;

public:
	/**
	 * @brief Constructor: Initializes a Candidate object.
	 */
	Candidate(short age, AppType::Choice hasLicense, AppType::Choice hasRecommendation)
		: _age(age), _hasLicense(hasLicense), _hasRecommendation(hasRecommendation) {
	}

	// Getters (const for data safety)
	short getAge() const { return _age; }
	AppType::Choice getHasLicense() const { return _hasLicense; }
	AppType::Choice getHasRecommendation() const { return _hasRecommendation; }
};

/**
 * @class EligibilityChecker
 * @brief Responsible for defining and applying the hiring criteria logic (Business Logic Layer).
 */
class EligibilityChecker {
private:
	// Constants related to the business rules.
	static constexpr short MIN_AGE_FOR_LICENSE_PATH = 21;

public:
	/**
	 * @brief Checks if the candidate meets the hiring criteria.
	 * CRITERIA: (Age > 21 AND Has License is Yes) OR (Has Recommendation is Yes).
	 * @param candidate The Candidate object to evaluate.
	 * @return AppType::HiringDecision (Hired or Rejected).
	 */
	static AppType::HiringDecision checkEligibility(const Candidate& candidate) {
		// Basic Path: Older than 21 AND has a license
		bool basicPathMet = (candidate.getAge() > MIN_AGE_FOR_LICENSE_PATH && candidate.getHasLicense() == AppType::Choice::Yes);

		// Alternative Path: Has a recommendation
		bool alternativePathMet = (candidate.getHasRecommendation() == AppType::Choice::Yes);

		return (basicPathMet || alternativePathMet)
			? AppType::HiringDecision::Hired
			: AppType::HiringDecision::Rejected;
	}

	/**
	 * @brief Helper function to retrieve the minimum required age for the basic path.
	 */
	static short getMinimumAgeForLicensePath() {
		return MIN_AGE_FOR_LICENSE_PATH;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for converting internal types to displayable strings and preparing output.
 */
class ResultFormatter {
private:
	static constexpr const char* UNKNOWN_CHOICE = "UNKNOWN";

public:
	/**
	 * @brief Converts the Choice enum to "Yes" or "No".
	 */
	static std::string formatChoice(AppType::Choice choice) {
		switch (choice) {
		case AppType::Choice::Yes:
			return "Yes";
		case AppType::Choice::No:
			return "No";
		default:
			return UNKNOWN_CHOICE;
		}
	}

	/**
	 * @brief Prints the final hiring decision and specific rejection reasons.
	 * This is the main presentation logic function.
	 */
	static void printResult(const Candidate& applicant, AppType::HiringDecision decision) {
		std::cout << "\n--- Application Eligibility Check ---\n";

		// Display applicant data
		std::cout << "Candidate Data:\n";
		std::cout << "  Age: " << applicant.getAge() << "\n";
		std::cout << "  License: " << formatChoice(applicant.getHasLicense()) << "\n";
		std::cout << "  Recommendation: " << formatChoice(applicant.getHasRecommendation()) << "\n";
		std::cout << "-----------------------------------\n";

		if (decision == AppType::HiringDecision::Hired) {
			std::cout << "FINAL DECISION: Hired\n";
		}
		else {
			std::cout << "FINAL DECISION: Rejected\n";
			std::cout << "Reason: Failed both the basic criteria and lacked the alternative path.\n";

			// List specific failures within the basic path for clarity:
			short minAge = EligibilityChecker::getMinimumAgeForLicensePath();

			if (applicant.getAge() <= minAge) {
				std::cout << "- Failed Age: Must be older than " << minAge
					<< " (Current Age: " << applicant.getAge() << ").\n";
			}
			if (applicant.getHasLicense() == AppType::Choice::No) {
				std::cout << "- Failed License: Driver's license is required for basic path.\n";
			}
			if (applicant.getHasRecommendation() == AppType::Choice::No) {
				std::cout << "- Failed Alternative Path: Recommendation was not provided.\n";
			}
		}
	}
};


/**
 * @class ApplicationFlow
 * @brief Class responsible for orchestrating the overall flow of the application.
 */
class ApplicationFlow {
public:
	void run() {
		std::ios_base::sync_with_stdio(false); // Optimization
		std::cout << "\n--- Driver Employment Eligibility Checker ---\n";

		// 1. Input: Collect validated data (InputReader Layer)
		short age = InputReader::readAge();
		AppType::Choice hasLicense = InputReader::readChoice("Do you have a driver's license? (Y/N): ");
		AppType::Choice hasRecommendation = InputReader::readChoice("Do you have a recommendation? (Y/N): ");

		// 2. Data Creation: Encapsulate data (Data Model Layer)
		Candidate jobCandidate(age, hasLicense, hasRecommendation);

		// 3. Business Logic: Determine decision (Business Logic Layer)
		AppType::HiringDecision decision = EligibilityChecker::checkEligibility(jobCandidate);

		// 4. Output: Format and print result (Presentation Layer)
		ResultFormatter::printResult(jobCandidate, decision);
	}
};

/**
 * @brief Main function, the program entry point.
 */
int main() {
	ApplicationFlow app;
	app.run();

	return 0;
}