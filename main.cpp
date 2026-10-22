#include <iostream>
#include <limits>
#include <string>
#include <vector>

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

    static void clearInputStream() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    static bool isValidMarks(double value) {
        return value >= 0.0 && value <= 100.0;
    }

    static string readText(const string& prompt) {
        string value;
        cout << prompt;
        getline(cin, value);
        return value;
    }

public:
    void addStudent() {
        Student newStudent{};

        cout << "\nEnter roll number: ";
        if (!(cin >> newStudent.rollNumber)) {
            cout << "Invalid roll number. Please enter a valid number.\n";
            clearInputStream();
            return;
        }
        clearInputStream();

        if (findStudentIndex(newStudent.rollNumber) != -1) {
            cout << "A student with this roll number already exists.\n";
            return;
        }

        newStudent.name = readText("Enter student name: ");
        newStudent.course = readText("Enter course/branch: ");

        cout << "Enter marks (0-100): ";
        if (!(cin >> newStudent.marks)) {
            cout << "Invalid marks. Please enter a numeric value.\n";
            clearInputStream();
            return;
        }
        clearInputStream();

        if (newStudent.name.empty() || newStudent.course.empty() || !isValidMarks(newStudent.marks)) {
            cout << "Invalid details. Name/course cannot be empty and marks must be between 0 and 100.\n";
            return;
        }

        students.push_back(newStudent);
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
            clearInputStream();
            return;
        }
        clearInputStream();

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
            clearInputStream();
            return;
        }
        clearInputStream();

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        Student& student = students[index];

        string updatedName = readText("Enter new name: ");
        string updatedCourse = readText("Enter new course/branch: ");

        double updatedMarks;
        cout << "Enter new marks (0-100): ";
        if (!(cin >> updatedMarks)) {
            cout << "Invalid marks.\n";
            clearInputStream();
            return;
        }
        clearInputStream();

        if (updatedName.empty() || updatedCourse.empty() || !isValidMarks(updatedMarks)) {
            cout << "Invalid details. Update cancelled.\n";
            return;
        }

        student.name = updatedName;
        student.course = updatedCourse;
        student.marks = updatedMarks;
        cout << "Student record updated successfully.\n";
    }

    void deleteStudent() {
        int rollNumber;

        cout << "\nEnter roll number to delete: ";
        if (!(cin >> rollNumber)) {
            cout << "Invalid roll number.\n";
            clearInputStream();
            return;
        }
        clearInputStream();

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        students.erase(students.begin() + index);
        cout << "Student record deleted successfully.\n";
    }

    void showMenu() const {
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
    }

    void run() {
        int choice = 0;

        do {
            showMenu();

            if (!(cin >> choice)) {
                cout << "Please enter a valid menu number.\n";
                clearInputStream();
                continue;
            }
            clearInputStream();

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayStudents();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    updateStudent();
                    break;
                case 5:
                    deleteStudent();
                    break;
                case 6:
                    cout << "Thank you for using the Student Management System!\n";
                    break;
                default:
                    cout << "Invalid choice. Please select a number from 1 to 6.\n";
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    StudentManagementSystem system;
    system.run();
    return 0;
}
