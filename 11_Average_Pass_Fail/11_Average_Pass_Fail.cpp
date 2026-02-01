// Project: Level 1 - Problem 11 Average Pass Fail
// Architecture: Layered OOP with Business Rules & Validation

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <algorithm>

namespace Config {
	const short MIN_AGE = 10;
	const short MAX_AGE = 15;
	const float MIN_MARK = 0.0f;
	const float MAX_MARK = 100.0f;
}

// Infrastructure: Enums & Types
namespace AppType {
	enum class enGender { Male, Female };
	enum class enStatus { Pass, Fail };
	enum class enAction { Yes, No };
}

/**
 * @class Utils
 * @brief Provides generic static utility functions, primarily for handling the
 * input stream.
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

	bool static isInRange(double mark, short minScore, short maxScore) {
		return mark >= minScore && mark <= maxScore;
	}
};

/**
 * @class InputHandler
 * @brief Responsible for reading numeric input and ensuring its validity (Input Layer).
 */
class InputHandler {
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

	/**
	 * @brief Prompts the user to enter a mark and repeats until valid input is received.
	 * @param promptMessage The message displayed to the user.
	 * @return The validated mark value (double).
	 */
	template<typename T>
	static T readNumber(const std::string& promptMessage, short min, short max, const std::string& promptError) {
		T inputMark;

		do {
			std::cout << promptMessage;
			if (std::cin >> inputMark && Utils::isInRange(inputMark, min, max)) {
				Utils::clearInputStream();
				return inputMark;
			}
			else {
				Utils::clearInputStream(promptError);
			}
		} while (true);
	}

	static char readGender(const std::string& promptMessage) {
		char inputGender;
		do {
			std::cout << promptMessage;
			if (std::cin >> inputGender && (inputGender == 'M' || inputGender == 'F' || inputGender == 'm' || inputGender == 'f')) {
				Utils::clearInputStream();
				return toupper(inputGender);
			}
			else {
				Utils::clearInputStream("Invalid input! Please enter 'M' for Male or 'F' for Female .\n");
			}
		} while (true);
	};

	static char readAction(const std::string& promptMessage) {
		char inputAction;
		do {
			std::cout << promptMessage;
			if (std::cin >> inputAction && (inputAction == 'Y' || inputAction == 'N' || inputAction == 'y' || inputAction == 'n')) {
				Utils::clearInputStream();
				return toupper(inputAction);
			}
			else {
				Utils::clearInputStream("Invalid input! Please enter 'Y' for Yes or 'N' for No.\n");
			}
		} while (true);
	}
};

class AppTypeHelper {
public:
	static std::string statusToString(AppType::enStatus status) {
		return (status == AppType::enStatus::Pass) ? "Pass" : "Fail";
	}

	static AppType::enGender charToGender(char inputChar) {
		return (toupper(inputChar) == 'M') ? AppType::enGender::Male : AppType::enGender::Female;
	}

	static std::string genderToString(AppType::enGender gender) {
		return (gender == AppType::enGender::Male) ? "Male" : "Female";
	}

	static char genderToChar(AppType::enGender gender) {
		return (gender == AppType::enGender::Male) ? 'M' : 'F';
	}


	static AppType::enAction charToAction(char inputChar) {
		return (toupper(inputChar) == 'Y') ? AppType::enAction::Yes : AppType::enAction::No;
	}

	static std::string actionToString(AppType::enAction action) {
		return (action == AppType::enAction::Yes) ? "Yes" : "No";
	}
};

class Person {
private:
	std::string _firstName;
	std::string _lastName;
	short _age;
	AppType::enGender _gender;

public:
	/**
	 * @brief Constructor for the Person class.
	 */
	Person(const std::string& firstName, const std::string& lastName, const short age, AppType::enGender gender) :
		_firstName(firstName), _lastName(lastName), _age(age), _gender(gender) {
	}

	// Getters (const reference to prevent unnecessary copies)
	const std::string& getFirstName() const { return _firstName; }
	const std::string& getLastName() const { return _lastName; }
	const short getAge() const { return _age; }
	AppType::enGender getGender() const { return _gender; }

};

class Marks {
private:
	float _Arabic;
	float _English;
	float _Math;

	constexpr static int NUMBER_OF_MARKS = 3;
	constexpr static float PASSING_MARK = 50.0f;
public:
	Marks(float arabic, float english, float math)
		: _Arabic(arabic), _English(english), _Math(math) {
	}

	float getSum() const {
		return _Arabic + _English + _Math;
	}

	float getAverage() const {
		return getSum() / NUMBER_OF_MARKS;
	}

	AppType::enStatus getStatus() const {
		return (getAverage() >= PASSING_MARK) ? AppType::enStatus::Pass : AppType::enStatus::Fail;
	}
};

class Student : public Person {
private:
	Marks _marks;
public:
	/**
	 * @brief Constructor for the Student class.
	 */
	Student(const std::string& firstName, const std::string& lastName, const short age, AppType::enGender gender, const Marks& marks) :
		Person(firstName, lastName, age, gender), _marks(marks) {
	}
	const Marks& getMarks() const { return _marks; }
};

class ApplicationFlow {
public:
	void run() {
		char action;

		do {
			// ===== Read Personal Info =====
			std::string firstName = InputHandler::ReadString("Enter First Name: ");
			std::string lastName = InputHandler::ReadString("Enter Last Name: ");

			short age = InputHandler::readNumber<short>("Enter Age: ", Config::MIN_AGE, Config::MAX_AGE, "Invalid age! Please enter a valid number.\n");

			// ===== Read Gender =====
			char genderChar = InputHandler::readGender("Enter Gender (M/F): ");
			AppType::enGender gender = AppTypeHelper::charToGender(genderChar);

			// ===== Read Marks =====
			float arabic = InputHandler::readNumber<float>("Enter Arabic Mark: ", Config::MIN_MARK, Config::MAX_MARK, "Invalid mark! Must be between 0 and 100.\n");

			float english = InputHandler::readNumber<float>("Enter English Mark: ", Config::MIN_MARK, Config::MAX_MARK, "Invalid mark! Must be between 0 and 100.\n");

			float math = InputHandler::readNumber<float>("Enter Math Mark: ", Config::MIN_MARK, Config::MAX_MARK, "Invalid mark! Must be between 0 and 100.\n");

			// ===== Create Domain Objects =====
			Marks marks(arabic, english, math);
			Student student(firstName, lastName, age, gender, marks);

			// ===== Output Result =====
			std::cout << "\n========= Student Result =========\n";
			std::cout << "Name    : " << student.getFirstName() << " " << student.getLastName() << "\n";
			std::cout << "Age     : " << student.getAge() << "\n";
			std::cout << "Gender  : " << AppTypeHelper::genderToString(student.getGender()) << "\n";

			std::cout << std::fixed << std::setprecision(2);
			std::cout << "Average : " << student.getMarks().getAverage() << "\n";
			std::cout << "Status  : " << AppTypeHelper::statusToString(student.getMarks().getStatus()) << "\n";
			std::cout << "==================================\n\n";

			// ===== Continue? =====
			action = InputHandler::readAction("Do you want to enter another student? (Y/N): ");

		} while (AppTypeHelper::charToAction(action) == AppType::enAction::Yes);
	}
};

int main() {
	ApplicationFlow app;
	app.run();
	return 0;
}
