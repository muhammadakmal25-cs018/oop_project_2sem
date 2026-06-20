#include "Utils.h"

void Utils::sortStudentsByGPA(Student* students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j]->getGPA() < students[j + 1]->getGPA()) {
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "\nStudents sorted by GPA.\n";
}

void Utils::searchStudentByRollNo(Student* students[], int count, string rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i]->getRollNo() == rollNo) {
            cout << "\nStudent Found:\n";
            students[i]->displayInfo();
            return;
        }
    }
    cout << "Student not found!\n";
}