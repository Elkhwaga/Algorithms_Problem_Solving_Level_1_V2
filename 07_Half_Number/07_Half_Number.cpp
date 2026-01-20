// Project: Level 1 - Problem 07 Half Number
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <string>
#include <iomanip> // For formatting output (optional, but good practice for division)

/**
 * @class Utils
 * @brief Provides generic static utility functions, primarily for handling the
 * input stream.
 */
class Utils {
public:
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
 * @brief Responsible for reading numeric input and ensuring its validity (Input Layer).
 */
class InputReader {
public:
	/**
	 * @brief Prompts the user to enter a number and repeats until valid input is received.
	 * NOTE: Reads as 'double' to handle non-integer input gracefully if needed later.
	 * @param promptMessage The message displayed to the user.
	 * @return The validated number value.
	 */
	static double readNumber(const std::string& promptMessage) {
		double inputNumber;

		do {
			std::cout << promptMessage;
			if (std::cin >> inputNumber) {
				Utils::clearInputStream(); // Clean up buffer after successful input
				return inputNumber;        // Valid input received
			}
			else {
				// Error handling for stream failure (non-numeric input)
				Utils::clearInputStream("Invalid input! Please enter a number.\n");
			}
		} while (true);
	}
};

/**
 * @class Calculator
 * @brief Contains the core business logic for mathematical operations (Business Logic Layer).
 */
class Calculator {
public:
	/**
	 * @brief Calculates half of the given number.
	 * @param number The number to be halved.
	 * @return The result of dividing the number by 2.
	 */
	static double calculateHalf(double number) {
		return number / 2.0;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for formatting and outputting the results (Presentation Layer).
 */
class ResultFormatter {
public:
	/**
	 * @brief Prints the final result in the format: "Half of [Original] is [Result]".
	 * @param original The original number entered by the user.
	 * @param halfResult The calculated half of the number.
	 */
	static void printHalfResult(double original, double halfResult) {
		std::cout << "Half of " << original << " is " << halfResult << std::endl;
	}
};

/**
 * @class ApplicationFlow
 * @brief Controls the overall sequence of program execution (Control Layer).
 */
class ApplicationFlow {
public:
	void run() {
		std::cout << "--- Number Halving Program ---\n";

		// 1. Input: Read the number using the InputReader
		double number = InputReader::readNumber("Enter a number: ");

		// 2. Business Logic: Calculate half of the number
		double halfResult = Calculator::calculateHalf(number);

		// 3. Output: Display the formatted result
		ResultFormatter::printHalfResult(number, halfResult);
	}
};

/**
 * @brief Main function, the program entry point.
 */
int main() {
	// Use the ApplicationFlow class to execute the complete workflow
	ApplicationFlow app;
	app.run();

	return 0;
}