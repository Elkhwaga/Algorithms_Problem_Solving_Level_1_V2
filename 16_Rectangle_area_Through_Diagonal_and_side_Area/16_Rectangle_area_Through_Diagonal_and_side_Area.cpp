// Project: Level 1 - Problem 16 Rectangle area Through Diagonal and side Area
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

class Utils {
public:
	static void clearInputStream(const std::string& message = "") {
		if (!message.empty()) std::cout << message;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

class InputHandler {
public:
	template<typename T>
	static T readNumber(const std::string& prompt) {
		T value;
		while (true) {
			std::cout << prompt;
			if (std::cin >> value && value > 0) {
				Utils::clearInputStream();
				return value;
			}
			Utils::clearInputStream("Invalid input! Enter a positive number.\n");
		}
	}
};

class Rectangle {
public:
	static double calculateAreaByDiagonalAndSide(double side, double diagonal) {
		return A * sqrt(pow(D, 2) - pow(A, 2));
	}
};

class ApplicationFlow {
public:
	void run() {
		double side = InputHandler::readNumber<double>("Enter one side (a): ");
		double diagonal = InputHandler::readNumber<double>("Enter diagonal (d): ");

		double area = Rectangle::calculateAreaByDiagonalAndSide(side, diagonal);
		std::cout << std::fixed << std::setprecision(3);
		std::cout << "Rectangle Area = " << area << "\n";
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}
