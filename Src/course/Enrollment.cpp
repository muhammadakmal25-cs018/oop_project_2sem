#include "Enrollment.h"

Enrollment::Enrollment(Student* student, Course* course, string enrollmentDate, char grade) {
    this->student = student;
    this->course = course;
    this->enrollmentDate = enrollmentDate;
    this->grade = grade;
}

void Enrollment::displayEnrollment() const {
    cout << "\n----- Enrollment Info -----\n";
    if (student != nullptr)
        cout << "Student: " << student->getName() << endl;
    if (course != nullptr)
        cout << "Course: " << course->getCourseCode() << endl;

    cout << "Date: " << enrollmentDate << endl;
    cout << "Grade: " << grade << endl;
}