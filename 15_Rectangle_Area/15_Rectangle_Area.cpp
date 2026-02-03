// Project: Level 1 - Problem 15 Rectangle Area
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
			if (std::cin >> value && value >= 0) {
				Utils::clearInputStream();
				return value;
			}
			Utils::clearInputStream("Invalid input! Please enter a non-negative number.\n");
		}
	}
};

/**
 * @class Rectangle
 * @brief Represents a rectangle and encapsulates area calculation.
 */
class Rectangle {
private:
	double _length;
	double _width;

public:
	Rectangle(double length, double width) : _length(length), _width(width) {}

	double getLength() const { return _length; }
	double getWidth() const { return _width; }

	double getArea() const {
		return _length * _width;
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates application execution.
 */
class ApplicationFlow {
public:
	void run() const {
		double length = InputHandler::readNumber<double>("Enter the length of the rectangle: ");
		double width = InputHandler::readNumber<double>("Enter the width of the rectangle: ");

		Rectangle rectangle(length, width);

		std::cout << "\nRectangle Dimensions: " << rectangle.getLength() << " x " << rectangle.getWidth() << "\n";
		std::cout << "Rectangle Area      : " << rectangle.getArea() << "\n";
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}
