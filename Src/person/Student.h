#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>

class Student : public Person {
private:
    string rollNo;
    int semester;
    float gpa;
    vector<string> enrolledCourses;

public:
    Student(string name, string cnic, int age, string contact, string rollNo, int semester, float gpa);

    string getRollNo() const;
    float getGPA() const;

    void addCourse(string courseCode);
    char calculateGrade() const;
    void displayInfo() const override;
};

#endif