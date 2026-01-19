// Project: Level 1 - Problem 06 Full Name
// Architecture: Layered OOP with Business Rules & Validation


#include <iostream>
#include <algorithm> // Required for std::find_if
#include <cctype>    // Required for std::isspace
#include <string>

namespace AppType {
	enum class FormatName { Normal, Reverse };
}

/**
 * @class Utils
 * @brief Provides static utility functions, primarily for string manipulation and cleanup.
 */
class Utils {
public:
	/**
	 * @brief Removes leading and trailing whitespace characters from a string in-place.
	 * @param s The string reference to be trimmed (modified directly).
	 */
	static void Trim(std::string& s) {
		// 1. Right Trim (Remove trailing spaces):
		s.erase(std::find_if(s.rbegin(), s.rend(), [](char ch) { return !std::isspace(static_cast<unsigned char>(ch)); }).base(), s.end());

		// 2. Left Trim (Remove leading spaces):
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char ch) { return !std::isspace(static_cast<unsigned char>(ch)); }));
	}
};

/**
 * @class InputReader
 * @brief Handles secure, validated user input operations (Input Layer).
 */
class InputReader {
public:
	/**
	 * @brief Prompts the user for input, reads a line, trims whitespace, and
	 * validates it is not empty.
	 * @param message The prompt message displayed to the user.
	 * @return The validated and trimmed input string.
	 */
	static std::string ReadString(const std::string& message) {
		std::string input = "";
		do {
			std::cout << message;
			std::getline(std::cin, input);
			Utils::Trim(input);

			// Basic validation: check if input is empty
			if (input.empty()) {
				std::cout << "Input cannot be empty! Please try again.\n";
			}
		} while (input.empty());

		return input;
	}
};

/**
 * @class Person
 * @brief Represents a Person object with first and last name properties (Data Model Layer).
 * NOTE: The PrintName() function was moved out to the Presenter class.
 */
class Person {
private:
	std::string _firstName;
	std::string _lastName;

public:
	/**
	 * @brief Constructor for the Person class.
	 */
	Person(const std::string& firstName, const std::string& lastName) : _firstName(firstName), _lastName(lastName) {}

	// Getters (const reference to prevent unnecessary copies)
	const std::string& getFirstName() const { return _firstName; }
	const std::string& getLastName() const { return _lastName; }
};

/**
 * @class Presenter
 * @brief Handles formatting and printing output to the console (Presentation Layer).
 */
class Presenter {
public:
	/**
	 * @brief Formats and prints the full name (First Name + Last Name) to the console.
	 * @param person The Person object whose name is to be displayed.
	 */
	static void PrintName(const Person& person)
	{
		std::cout << "Your name is: " << person.getFirstName() << " " << person.getLastName() << std::endl;
	}

	static void PrintFullName(const Person& person, AppType::FormatName formate = AppType::FormatName::Normal)
	{
		formate == AppType::FormatName::Normal
			? std::cout << "Your name is: " << person.getFirstName() << " " << person.getLastName() << std::endl
			: std::cout << "Your name is: " << person.getLastName() << " " << person.getFirstName() << std::endl;
	}
};

/**
 * @class ApplicationFlow
 * @brief Controls the overall sequence of execution: Input -> Data -> Output (Control Layer).
 */
class ApplicationFlow {
public:
	void run() {
		// 1. Input: Read and validate names (InputReader Layer)
		std::string firstName = InputReader::ReadString("Please enter your first name: ");
		std::string lastName = InputReader::ReadString("Please enter your last name: ");

		// 2. Data Creation: Create a Person object (Data Model Layer)
		Person person(firstName, lastName);

		// 3. Output: Print the full name (Presenter Layer)
		Presenter::PrintFullName(person, AppType::FormatName::Reverse);
	}
};

/**
 * @brief Main function where the program execution begins.
 */
int main() {
	ApplicationFlow app;
	app.run();

	return 0;
}