#include "Student.h"

Student::Student(string name, string cnic, int age, string contact,string rollNo, int semester, float gpa): Person(name, cnic, age, contact) {
    this->rollNo = rollNo;
    this->semester = semester;
    this->gpa = gpa;
}

string Student::getRollNo() const {
    return rollNo;
}

float Student::getGPA() const {
    return gpa;
}

void Student::addCourse(string courseCode) {
    enrolledCourses.push_back(courseCode);
}

char Student::calculateGrade() const {
    if (gpa >= 3.7) return 'A';
    else if (gpa >= 3.0) return 'B';
    else if (gpa >= 2.0) return 'C';
    else if (gpa >= 1.0) return 'D';
    else return 'F';
}

void Student::displayInfo() const {
    cout << "\n----- Student Info -----\n";
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Age: " << age << endl;
    cout << "Contact: " << contact << endl;
    cout << "Semester: " << semester << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Grade: " << calculateGrade() << endl;

    cout << "Courses: ";
    for (string c : enrolledCourses)
        cout << c << " ";
    cout << endl;
}