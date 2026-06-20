#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include "../person/Student.h"
#include "../person/Faculty.h"
using namespace std;

class CapacityExceededException {
public:
    void showError() const {
        cout << "Error: Course capacity exceeded!\n";
    }
};

class Course {
private:
    string courseCode;
    string courseName;
    int creditHours;
    Faculty* instructor;
    int maxCapacity;
    int enrolledCount;

    vector<Student*> enrolledStudents;
    vector<Student*> waitingList;

public:
    Course(string courseCode, string courseName, int creditHours,
           Faculty* instructor, int maxCapacity);

    string getCourseCode() const;
    string getCourseName() const;

    void enrollStudent(Student* s);
    void showEnrolledStudents() const;
    void showWaitingList() const;

    bool operator==(const Course& c) const;
    vector<Student*> operator+(Course& c);

    friend ostream& operator<<(ostream& out, const Course& c);
};

#endif