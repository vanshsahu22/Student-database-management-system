# Student Management System (C++)

A beginner-friendly, menu-driven console application for managing student records. This project demonstrates fundamental C++ programming concepts and simple record-management operations.

## Features

- Add a student with a unique roll number
- Display all student records
- Search for a student by roll number
- Update a student's name, course, and marks
- Delete a student record
- Validate user input and marks (0-100)

## Concepts Used

- C++ classes and objects
- Structures and vectors
- Functions and loops
- Conditional statements
- Input validation
- Basic CRUD operations (Create, Read, Update, Delete)

## Requirements

- A C++ compiler that supports C++11 or newer (such as GCC, Clang, or MinGW)
- A terminal or command prompt

## Compile and Run

### Linux / macOS

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o student_management
./student_management
```

### Windows (MinGW)

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o student_management.exe
student_management.exe
```

## Important Note

This version stores records in memory while the program is running. Records are cleared when you exit. File storage can be added as a future enhancement.

## Future Improvements

- Save and load records using file handling
- Sort students by name or marks
- Calculate grades and class averages
- Add automated tests

## Author

Vansh Sahu
