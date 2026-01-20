// Project: Level 1 - Problem 08 Mark Pass Fail
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <string>
#include <limits>

/**
 * @namespace AppType
 * @brief Contains application-specific types and enumerations.
 */
namespace AppType {
	/**
	 * @enum ResultStatus
	 * @brief Represents the final result status (Pass or Fail).
	 */
	enum class ResultStatus {
		Pass,
		Fail
	};
}

/**
 * @class Student
 * @brief Class representing a student and their mark.
 */
class Student {
private:
	double mark;

public:
	/**
	 * @brief Constructor for the Student class.
	 * @param studentMark The mark obtained by the student.
	 */
	Student(double studentMark) : mark(studentMark) {}

	/**
	 * @brief Getter for the student's mark.
	 * @return The stored mark.
	 */
	double getMark() const {
		return mark;
	}
};

/**
 * @class ResultChecker
 * @brief Responsible for applying business logic and determining the pass/fail status.
 */
class ResultChecker {
private:
	/// The minimum threshold required to achieve a passing status.
	static constexpr double PASSING_THRESHOLD = 50.0;

public:
	/**
	 * @brief Checks the student's result based on their mark and the passing threshold.
	 * @param student The student object to be checked.
	 * @return AppType::ResultStatus (Pass or Fail).
	 */
	static AppType::ResultStatus checkResult(const Student& student) {
		return (student.getMark() >= PASSING_THRESHOLD)
			? AppType::ResultStatus::Pass
			: AppType::ResultStatus::Fail;
	}

	/**
	 * @brief Retrieves the passing threshold used for checking.
	 * @return The passing mark value.
	 */
	static double getPassingThreshold() {
		return PASSING_THRESHOLD;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for converting internal data (like Enums) into display-ready strings.
 */
class ResultFormatter {
public:
	/**
	 * @brief Formats the internal ResultStatus enum into a displayable string.
	 * @param status The internal result status.
	 * @return A string representing the status ("Pass" or "Fail").
	 */
	static std::string formatStatus(AppType::ResultStatus status) {
		switch (status)
		{
		case AppType::ResultStatus::Pass:
			return "Pass";
		case AppType::ResultStatus::Fail:
			return "Fail";
		default:
			return "UNKNOWN STATUS";
		}
	}
};

/**
 * @class Utils
 * @brief A utility class containing general helper functions, such as input stream handling.
 */
class Utils {
public:
	/**
	 * @brief Clears the fail state of the input stream and discards any remaining input in the buffer.
	 * @param message An optional message to display before clearing.
	 */
	static void clearInputStream(std::string message = "") {
		if (!message.empty()) {
			std::cout << message;
		}
		std::cin.clear(); // Clear error flags (failbit, badbit)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard buffered input up to the newline
	}
};

/**
 * @class InputReader
 * @brief Responsible for reading the student's mark from the user and validating its integrity.
 */
class InputReader {
public:
	/**
	 * @brief Reads the mark from the user, looping until a valid numeric value (0-100) is entered.
	 * Ensures a clean, valid mark is returned.
	 * @return The validated student mark.
	 */
	static double readMark() {
		double inputMark;

		while (true) {
			std::cout << "Enter the mark (0 - 100): ";

			if (std::cin >> inputMark) {
				// Check range
				if (inputMark < 0.0 || inputMark > 100.0) {
					std::cerr << "Mark must be between 0 and 100.\n";
					continue; // Loop again
				}
				return inputMark; // Return the valid value
			}

			// Input failed (non-numeric input)
			Utils::clearInputStream("Invalid input. Please enter a number.\n");
		}
	}
};

/**
 * @class ConsolePrinter
 * @brief Responsible for outputting final data and error messages to the console.
 */
class ConsolePrinter {
public:
	/**
	 * @brief Formats all data (mark, threshold, result) into a complete display-ready string.
	 * @param mark The student's mark.
	 * @param resultText The formatted result (e.g., "Pass").
	 */
	static void displayData(double mark, const std::string& resultText) {
		std::cout << "\n--------------------\n";
		std::cout << "Student Mark: " << mark << "\n";
		std::cout << "Passing Threshold: " << ResultChecker::getPassingThreshold() << "\n";
		std::cout << "Final Result: " << resultText << "\n";
	}
};

/**
 * @class ApplicationFlow
 * @brief Represents the application entry point and controls the sequence of operations.
 */
class ApplicationFlow {
public:
	/**
	 * @brief Executes the main application workflow (Read -> Process -> Display).
	 */
	void run() {
		// 1. Input: Read the validated mark
		double inputMark = InputReader::readMark();

		// 2. Data Creation: Create the student object
		Student student(inputMark);

		// 3. Business Logic: Determine Pass/Fail status
		AppType::ResultStatus status = ResultChecker::checkResult(student);

		// 4. Presentation Logic: Format status to display text
		std::string resultText = ResultFormatter::formatStatus(status);

		// 5. Output: Print the final result
		ConsolePrinter::displayData(inputMark, resultText);
	}
};

int main() {
	ApplicationFlow app;
	app.run();

	return 0;
}