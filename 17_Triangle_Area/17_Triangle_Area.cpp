// Project: Level 1 - Problem 17 Triangle Area
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
	static T readPositiveNumber(const std::string& promptMessage) {
		T value;

		while (true) {
			std::cout << promptMessage;
			if (std::cin >> value && value > 0) {
				Utils::clearInputStream();
				return value;
			}
			Utils::clearInputStream("Invalid input! Please enter a positive number.\n");
		}
	}
};

/**
 * @class TriangleAreaCalculator
 * @brief Encapsulates triangle area calculation logic.
 */
class TriangleAreaCalculator {
public:
	static double calculate(double base, double height) {
		return (base * height) / 2.0;
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates application execution.
 */
class ApplicationFlow {
public:
	void run() const {
		const double base = InputHandler::readPositiveNumber<double>("Enter triangle base: ");
		const double height = InputHandler::readPositiveNumber<double>("Enter triangle height: ");

		std::cout << "\nTriangle Area = " << TriangleAreaCalculator::calculate(base, height) << "\n";
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}
