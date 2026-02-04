# Problem 16 – Rectangle Area from Diagonal and Side

## 📝 Problem Description

Write a program to calculate the **area of a rectangle** given:  
- One side `a`  
- The diagonal `d`  

The program should calculate and print the rectangle area.

**Example Inputs:**
5
40

**Expected Output:**
198.431

---

## 🛠 Core Concepts & Focus

- Layered OOP Design
- Input Validation and Stream Recovery
- Encapsulation of Calculation Logic in Domain Classes
- Separation of Concerns (Input Layer vs Business Logic vs Presentation)

---

## 🏗 Architecture

### 🔹 Input Layer
- Handles user input and validation
- Example class: `InputHandler`

### 🔹 Business / Domain Layer
- Calculates rectangle area from side and diagonal
- Example class: `RectangleCalculator`

### 🔹 Infrastructure Layer
- Utility functions for stream management and validation
- Example class: `Utils`

### 🔹 Control Layer (Application Flow)
- Orchestrates program execution
- Example class: `ApplicationFlow`

---

## ▶️ How to Run

1. Open the folder `16_Rectangle_Diagonal_Area` in **Visual Studio Community 2026**  
2. Compile and run `16_Rectangle_Diagonal_Area.cpp`  
3. Enter the side and diagonal values when prompted  
4. The program will output the calculated rectangle area

---

## 🎯 Learning Goals

- Master arithmetic operations in C++  
- Practice Clean Code and Layered Architecture  
- Strengthen understanding of input validation and encapsulation  
- Learn to separate calculation logic from I/O logic  
