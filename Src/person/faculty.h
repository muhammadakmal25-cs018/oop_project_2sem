#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <vector>

class Faculty : public Person {
private:
    string employeeID;
    string department;
    string designation;
    vector<string> assignedCourses;

public:
    Faculty(string name, string cnic, int age, string contact,  string employeeID, string department, string designation);

    string getEmployeeID() const;
    void addAssignedCourse(string courseCode);
    void displayInfo() const override;
};

#endif