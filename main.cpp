#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string course;
    double marks;
};

class StudentManagementSystem {
private:
    vector<Student> students;

    int findStudentIndex(int rollNumber) const {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].rollNumber == rollNumber) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    static void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void addStudent() {
        Student student{};

        cout << "\nEnter roll number: ";
        if (!(cin >> student.rollNumber)) {
            cout << "Invalid roll number. Please enter a number.\n";
            clearInput();
            return;
        }
        clearInput();

        if (findStudentIndex(student.rollNumber) != -1) {
            cout << "A student with this roll number already exists.\n";
            return;
        }

        cout << "Enter student name: ";
        getline(cin, student.name);

        cout << "Enter course/branch: ";
        getline(cin, student.course);

        cout << "Enter marks (0-100): ";
        if (!(cin >> student.marks)) {
            cout << "Invalid marks. Please enter a number.\n";
            clearInput();
            return;
        }
        clearInput();

        if (student.name.empty() || student.course.empty() ||
            student.marks < 0 || student.marks > 100) {
            cout << "Invalid details. Name/course cannot be empty and marks must be 0-100.\n";
            return;
        }

        students.push_back(student);
        cout << "Student added successfully.\n";
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "\nNo student records available.\n";
            return;
        }

        cout << "\n--- Student Records ---\n";
        cout << "Roll No.\tName\t\tCourse\t\tMarks\n";
        cout << "------------------------------------------------------------\n";

        for (const Student& student : students) {
            cout << student.rollNumber << "\t\t"
                 << student.name << "\t\t"
                 << student.course << "\t\t"
                 << student.marks << '\n';
        }
    }

    void searchStudent() const {
        int rollNumber;
        cout << "\nEnter roll number to search: ";
        if (!(cin >> rollNumber)) {
            cout << "Invalid roll number.\n";
            clearInput();
            return;
        }
        clearInput();

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        const Student& student = students[index];
        cout << "\nStudent found:\n"
             << "Roll number: " << student.rollNumber << '\n'
             << "Name: " << student.name << '\n'
             << "Course: " << student.course << '\n'
             << "Marks: " << student.marks << '\n';
    }

    void updateStudent() {
        int rollNumber;
        cout << "\nEnter roll number to update: ";
        if (!(cin >> rollNumber)) {
            cout << "Invalid roll number.\n";
            clearInput();
            return;
        }
        clearInput();

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        Student& student = students[index];
        string newName, newCourse;
        double newMarks;

        cout << "Enter new name: ";
        getline(cin, newName);
        cout << "Enter new course/branch: ";
        getline(cin, newCourse);
        cout << "Enter new marks (0-100): ";

        if (!(cin >> newMarks)) {
            cout << "Invalid marks.\n";
            clearInput();
            return;
        }
        clearInput();

        if (newName.empty() || newCourse.empty() || newMarks < 0 || newMarks > 100) {
            cout << "Invalid details. Update cancelled.\n";
            return;
        }

        student.name = newName;
        student.course = newCourse;
        student.marks = newMarks;
        cout << "Student record updated successfully.\n";
    }

    void deleteStudent() {
        int rollNumber;
        cout << "\nEnter roll number to delete: ";
        if (!(cin >> rollNumber)) {
            cout << "Invalid roll number.\n";
            clearInput();
            return;
        }
        clearInput();

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        students.erase(students.begin() + index);
        cout << "Student record deleted successfully.\n";
    }

    void run() {
        int choice = 0;
        do {
            cout << "\n====================================\n";
            cout << "     STUDENT MANAGEMENT SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Add student\n";
            cout << "2. Display all students\n";
            cout << "3. Search student by roll number\n";
            cout << "4. Update student record\n";
            cout << "5. Delete student record\n";
            cout << "6. Exit\n";
            cout << "Choose an option: ";

            if (!(cin >> choice)) {
                cout << "Please enter a valid menu number.\n";
                clearInput();
                continue;
            }
            clearInput();

            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayStudents(); break;
                case 3: searchStudent(); break;
                case 4: updateStudent(); break;
                case 5: deleteStudent(); break;
                case 6: cout << "Thank you for using the Student Management System!\n"; break;
                default: cout << "Invalid choice. Please select 1-6.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    StudentManagementSystem system;
    system.run();
    return 0;
}
