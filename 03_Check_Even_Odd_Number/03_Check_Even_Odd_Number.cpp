// Project: Level 1 - Problem 03 (Check Even or Odd)
// Architecture: Layered OOP with Enums and Error Handling

#include <iostream>
#include <limits>
#include <string>

/**
 * @namespace AppType
 * @brief Application-specific types and constants.
 */
namespace AppType {
	enum class Parity { Even, Odd };
}

/**
 * @class Utils
 * @brief Input/Output stream utility helpers.
 */
class Utils {
public:
	static void ClearInputStream(const std::string& errorMessage = "") {
		if (!errorMessage.empty()) {
			std::cout << errorMessage;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

/**
 * @class InputReader
 * @brief Layer responsible for reading and validating user input.
 */
class InputReader {
public:
	static int GetValidInteger() {
		int input;
		while (true) {
			std::cout << "Please enter a number: ";
			if (std::cin >> input) {
				return input;
			}
			Utils::ClearInputStream("Invalid input! Please enter an integer only.\n");
		}
	}
};

/**
 * @class NumberChecker
 * @brief Business Logic Layer for numerical properties.
 */
class NumberChecker {
public:
	static AppType::Parity CheckParity(int number) {
		return (number % 2 == 0) ? AppType::Parity::Even : AppType::Parity::Odd;
	}
};

/**
 * @class ResultFormatter
 * @brief Presentation Layer for data formatting.
 */
class ResultFormatter {
public:
	static std::string ParityToString(AppType::Parity p) {
		switch (p) {
		case AppType::Parity::Even:
			return "Even";
		case AppType::Parity::Odd:
			return "Odd";
		default:
			return "Unknown";
		}
	}
};

/**
 * @class ApplicationFlow
 * @brief Controller Layer managing the execution sequence.
 */
class ApplicationFlow {
public:
	void run() {
		int number = InputReader::GetValidInteger();
		AppType::Parity result = NumberChecker::CheckParity(number);

		std::cout << "Number " << number << " is "
			<< ResultFormatter::ParityToString(result) << "." << std::endl;
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}