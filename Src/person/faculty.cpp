#include "Faculty.h"

Faculty::Faculty(string name, string cnic, int age, string contact, string employeeID, string department, string designation)
    : Person(name, cnic, age, contact) {
    this->employeeID = employeeID;
    this->department = department;
    this->designation = designation;
}

string Faculty::getEmployeeID() const {
    return employeeID;
}

void Faculty::addAssignedCourse(string courseCode) {
    assignedCourses.push_back(courseCode);
}

void Faculty::displayInfo() const {
    cout << "\n----- Faculty Info -----\n";
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Age: " << age << endl;
    cout << "Contact: " << contact << endl;
    cout << "Department: " << department << endl;
    cout << "Designation: " << designation << endl;

    cout << "Assigned Courses: ";
    for (string c : assignedCourses)
        cout << c << " ";
    cout << endl;
}