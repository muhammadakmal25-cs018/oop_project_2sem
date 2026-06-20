#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class Enrollment {
private:
    Student* student;
    Course* course;
    string enrollmentDate;
    char grade;

public:
    Enrollment(Student* student, Course* course, string enrollmentDate, char grade);

    void displayEnrollment() const;
};

#endif