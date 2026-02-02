// Project: Level 1 - Problem 12 Max of 2 Numbers
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <string>

/**
 * @class Utils
 * @brief Infrastructure utilities for stream handling.
 */
class Utils {
public:
	static void clearInputStream(const std::string& message = "") {
		if (!message.empty()) {
			std::cout << message;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

/**
 * @class InputHandler
 * @brief Handles validated user input (Input Layer).
 */
class InputHandler {
public:
	template<typename T>
	static T readNumber(const std::string& promptMessage) {
		T value;

		while (true) {
			std::cout << promptMessage;
			if (std::cin >> value) {
				Utils::clearInputStream();
				return value;
			}
			Utils::clearInputStream("Invalid input! Please enter a valid number.\n");
		}
	}
};

/**
 * @class MaxCalculator
 * @brief Encapsulates the business rule for determining the maximum value.
 */
template<typename T>
class MaxCalculator {
public:
	static T getMax(T first, T second) {
		return (first > second) ? first : second;
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates application execution.
 */
class ApplicationFlow {
public:
	void run() const {
		const double firstNumber = InputHandler::readNumber<double>("Enter the first number: ");
		const double secondNumber = InputHandler::readNumber<double>("Enter the second number: ");

		std::cout << "\nMax Number = " << MaxCalculator<double>::getMax(firstNumber, secondNumber) << "\n";
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}