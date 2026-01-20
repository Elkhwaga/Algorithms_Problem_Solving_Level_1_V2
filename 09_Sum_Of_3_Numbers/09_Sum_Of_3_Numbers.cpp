// Project: Level 1 - Problem 09 Sum Of 3 Numbers
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <string>

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
	 * @brief Prompts the user to enter an integer and repeats until valid input is received.
	 * @param promptMessage The message displayed to the user.
	 * @return The validated integer value.
	 */
	static int readInteger(const std::string& promptMessage) {
		int inputNumber;

		do {
			std::cout << promptMessage;
			if (std::cin >> inputNumber) {
				Utils::clearInputStream(); // Clean up buffer after successful input
				return inputNumber;        // Valid input received
			}
			else {
				// Error handling for stream failure (non-numeric input)
				Utils::clearInputStream("Invalid input! Please enter an integer only.\n");
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
	 * @brief Calculates the sum of three integers.
	 * @param num1 The first number.
	 * @param num2 The second number.
	 * @param num3 The third number.
	 * @return The sum of the numbers.
	 */
	static int calculateSum(int num1, int num2, int num3) {
		return num1 + num2 + num3;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for formatting and outputting the results (Presentation Layer).
 */
class ResultFormatter {
public:
	/**
	 * @brief Prints the final summation result to the console.
	 * @param result The calculated sum.
	 */
	static void printSumResult(int result) {
		std::cout << "\n--------------------\n";
		std::cout << "The Sum of the entered numbers is: " << result << std::endl;
		std::cout << "--------------------\n";
	}
};

/**
 * @class ApplicationFlow
 * @brief Controls the overall sequence of program execution (Control Layer).
 */
class ApplicationFlow {
public:
	void run() {
		std::cout << "--- Number Summation Program ---\n";

		// 1. Input: Read the three numbers using the InputReader
		int number1 = InputReader::readInteger("Enter Number 1: ");
		int number2 = InputReader::readInteger("Enter Number 2: ");
		int number3 = InputReader::readInteger("Enter Number 3: ");

		// 2. Business Logic: Calculate the sum using the Calculator
		int sumResult = Calculator::calculateSum(number1, number2, number3);

		// 3. Output: Display the formatted result using the ResultFormatter
		ResultFormatter::printSumResult(sumResult);
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