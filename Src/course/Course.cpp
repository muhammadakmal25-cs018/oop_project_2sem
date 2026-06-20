#include "Course.h"

Course::Course(string courseCode, string courseName, int creditHours, Faculty* instructor, int maxCapacity) {
    this->courseCode=courseCode;
    this->courseName=courseName;
    this->creditHours=creditHours;
    this->instructor=instructor;
    this->maxCapacity=maxCapacity;
    enrolledCount=0;
}

string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

void Course::enrollStudent(Student* s) {
    if (enrolledCount < maxCapacity) {
        enrolledStudents.push_back(s);
        enrolledCount++;
        s->addCourse(courseCode);
        cout << s->getName() << " enrolled in " << courseCode << endl;
    } else {
        waitingList.push_back(s);
        throw CapacityExceededException();
    }
}

void Course::showEnrolledStudents() const {
    cout << "\nEnrolled Students in " << courseCode << ":\n";
    for (auto s : enrolledStudents) {
        cout << s->getRollNo() << " - " << s->getName() << endl;
    }
}

void Course::showWaitingList() const {
    cout << "\nWaiting List of " << courseCode << ":\n";
    for (auto s : waitingList) {
        cout << s->getRollNo() << " - " << s->getName() << endl;
    }
}

bool Course::operator==(const Course& c) const {
    return courseCode == c.courseCode;
}

vector<Student*> Course::operator+(Course& c) {
    vector<Student*> merged = waitingList;
    for (auto s : c.waitingList)
        merged.push_back(s);
    return merged;
}

ostream& operator<<(ostream& out, const Course& c) {
    out << "\n----- Course Details -----\n";
    out << "Course Code: " << c.courseCode << endl;
    out << "Course Name: " << c.courseName << endl;
    out << "Credit Hours: " << c.creditHours << endl;
    out << "Max Capacity: " << c.maxCapacity << endl;
    out << "Enrolled Count: " << c.enrolledCount << endl;

    if (c.instructor != nullptr)
        out << "Instructor: " << c.instructor->getName() << endl;
    else
        out << "Instructor: Not Assigned" << endl;

    return out;
}