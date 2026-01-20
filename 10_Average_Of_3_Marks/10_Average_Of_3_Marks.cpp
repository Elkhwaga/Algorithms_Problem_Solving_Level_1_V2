// Project: Level 1 - Problem 10 Average Of 3 Marks
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

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
	 * @brief Prompts the user to enter a mark and repeats until valid input is received.
	 * @param promptMessage The message displayed to the user.
	 * @return The validated mark value (double).
	 */
	static double readMark(const std::string& promptMessage) {
		double inputMark;

		do {
			std::cout << promptMessage;
			if (std::cin >> inputMark) {
				Utils::clearInputStream();
				return inputMark;
			}
			else {
				Utils::clearInputStream("Invalid input! Please enter a number for the mark.\n");
			}
		} while (true);
	}
};

/**
 * @class Calculator
 * @brief Contains the core business logic for mathematical operations (Business Logic Layer).
 */
class Calculator {
private:
	static constexpr int NUMBER_OF_MARKS = 3;
public:
	/**
	 * @brief Calculates the sum of three integers.
	 * @param mark1 The first number.
	 * @param mark2 The second number.
	 * @param mark3 The third number.
	 * @return The sum of the numbers.
	 */
	static double calculateMark(double mark1, double mark2, double mark3) {
		return mark1 + mark2 + mark3;
	}

	/**
	 * @brief Calculates the average of three marks.
	 * @param mark1 The first mark.
	 * @param mark2 The second mark.
	 * @param mark3 The third mark.
	 * @return The calculated average as a double.
	 */
	static double calculateAverage(double mark1, double mark2, double mark3) {
		return calculateMark(mark1, mark2, mark3) / (double)NUMBER_OF_MARKS;
	}
};

/**
 * @class ResultFormatter
 * @brief Responsible for formatting and outputting the results (Presentation Layer).
 */
class ResultFormatter {
public:
	/**
	 * @brief Prints the final calculated average to the console.
	 * @param average The average value to display.
	 */
	static void printAverageResult(double average) {
		// Set precision to 2 decimal places for consistent output
		std::cout << std::fixed << std::setprecision(2);

		std::cout << "\n--------------------\n";
		std::cout << "The Average of the entered Marks is: " << average << std::endl;
		std::cout << "--------------------\n";
	}
};

/**
 * @class ApplicationFlow
 * @brief Controls the overall sequence of program execution: Input -> Process -> Output (Control Layer).
 */
class ApplicationFlow {
public:
	/**
	 * @brief Executes the main application workflow.
	 */
	void run() {
		std::cout << "--- Marks Average Calculation Program ---\n";

		// 1. Input collection
		double mark1 = InputReader::readMark("Enter Mark 1: ");
		double mark2 = InputReader::readMark("Enter Mark 2: ");
		double mark3 = InputReader::readMark("Enter Mark 3: ");

		// 2. Business Logic execution
		double averageResult = Calculator::calculateAverage(mark1, mark2, mark3);

		// 3. Output presentation
		ResultFormatter::printAverageResult(averageResult);
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