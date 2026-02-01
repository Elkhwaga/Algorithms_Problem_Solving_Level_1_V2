# Student Average Pass/Fail Calculator

## Overview
This is a simple C++ console application that allows users to input student data (name, age, gender, marks) and calculates the average marks along with the pass/fail status.

The application supports multiple students in a single run and validates all user inputs to ensure correctness.

---

## Features
- **Input Validation:** All inputs are checked for correctness (age, marks, gender, names, action).
- **OOP Design:** Classes `Person`, `Student`, and `Marks` encapsulate the data and logic.
- **Enums:** Gender, Status, and Action are represented using enums for clarity.
- **Reusable Utilities:** `Utils` for trimming strings and clearing input streams.
- **Configurable:** Minimum and maximum values for age and marks are defined in the `Config` namespace.
- **Multiple Entries:** Users can enter multiple students until they choose to stop.

---

## Classes

### `Person`
Represents a general person with:
- First name
- Last name
- Age
- Gender

### `Marks`
Represents a student's marks:
- Arabic, English, Math marks
- Methods to calculate sum, average, and status (Pass/Fail)

### `Student` (inherits `Person`)
- Contains `Marks` object
- Provides access to personal info and marks

### `InputHandler`
- Handles validated input for strings, numbers, gender, and actions.

### `ApplicationFlow`
- Main flow of the application:
  - Reads student data
  - Calculates average and pass/fail
  - Displays results
  - Repeats until the user stops

---

## Usage

1. Compile the code using a C++ compiler:
```bash
g++ -std=c++17 -o student_app main.cpp
