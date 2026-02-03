// Project: Level 1 - Problem 14 Swap Numbers
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
 * @class NumberSwapper
 * @brief Encapsulates the business logic for swapping two numbers.
 */
template<typename T>
class NumberSwapper {
public:
	static void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates application execution.
 */
class ApplicationFlow {
public:
	void run() const {
		double number1 = InputHandler::readNumber<double>("Enter the first number: ");
		double number2 = InputHandler::readNumber<double>("Enter the second number: ");

		std::cout << "\nBefore Swap: Number1 = " << number1 << ", Number2 = " << number2 << "\n";

		NumberSwapper<double>::swap(number1, number2);

		std::cout << "After Swap:  Number1 = " << number1 << ", Number2 = " << number2 << "\n";
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}
