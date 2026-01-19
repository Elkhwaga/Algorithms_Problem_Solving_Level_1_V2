// Project: Level 1 - Problem 02 (Read & Print Name)
// Architecture: Layered OOP Approach (Model, View, Controller, Utils)

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

/**
 * @class Utils
 * @brief Helper functions for string manipulation.
 */
class Utils {
public:
	static void Trim(std::string& s) {
		// Right Trim
		s.erase(std::find_if(s.rbegin(), s.rend(), [](char ch) {
			return !std::isspace(static_cast<unsigned char>(ch));
			}).base(), s.end());

		// Left Trim
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char ch) {
			return !std::isspace(static_cast<unsigned char>(ch));
			}));
	}
};

/**
 * @class InputReader
 * @brief Handles user input and validation logic.
 */
class InputReader {
public:
	static std::string ReadString(const std::string& message) {
		std::string input;
		while (true) {
			std::cout << message;
			std::getline(std::cin, input);
			Utils::Trim(input);

			if (input.empty()) {
				std::cout << "Input cannot be empty! Please try again.\n";
			}
			else if (input.length() < 2) {
				std::cout << "Name is too short (min 2 characters).\n";
			}
			else {
				return input;
			}
		}
	}
};

/**
 * @class Person
 * @brief Domain Model for a Person entity.
 */
class Person {
private:
	std::string _firstName;
	std::string _lastName;

public:
	Person(const std::string& firstName, const std::string& lastName)
		: _firstName(firstName), _lastName(lastName) {
	}

	const std::string& getFirstName() const { return _firstName; }
	const std::string& getLastName() const { return _lastName; }
};

/**
 * @class Presenter
 * @brief Handles formatting and output display.
 */
class Presenter {
public:
	static void PrintName(const Person& person) {
		std::cout << "\nYour name is: "
			<< person.getFirstName() << " "
			<< person.getLastName() << std::endl;
	}
};

/**
 * @class ApplicationFlow
 * @brief Controller managing the input-process-output sequence.
 */
class ApplicationFlow {
public:
	void run() {
		std::string firstName = InputReader::ReadString("Please enter your first name: ");
		std::string lastName = InputReader::ReadString("Please enter your last name: ");

		Person person(firstName, lastName);

		Presenter::PrintName(person);
	}
};

int main() {
	ApplicationFlow app;
	app.run();

	return 0;
}