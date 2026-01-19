// Project: Level 1 - Problem 01 (Print Name)
// Architecture: Layered OOP Approach

#include <iostream>
#include <string>

/**
 * @class Person
 * @brief Domain Model representing a human entity.
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
 * @brief Handles the UI/Console formatting logic.
 */
class Presenter {
public:
	static void PrintName(const Person& person) {
		std::cout << "Your name is: "
			<< person.getFirstName() << " "
			<< person.getLastName() << std::endl;
	}
};

/**
 * @class ApplicationFlow
 * @brief Orchestrates the flow between data models and presenters.
 */
class ApplicationFlow {
public:
	void run() {
		// Defining input data
		const std::string firstName = "FirstName";
		const std::string lastName = "LastName";

		// Initializing the Domain Model
		Person person(firstName, lastName);

		// Displaying results
		Presenter::PrintName(person);
	}
};

int main() {
	ApplicationFlow app;
	app.run();

	return 0;
}