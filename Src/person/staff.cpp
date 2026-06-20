#include "Staff.h"

Staff::Staff(string name, string cnic, int age, string contact,string staffID, string role, double salary)
    : Person(name, cnic, age, contact) {
    this->staffID = staffID;
    this->role = role;
    this->salary = salary;
}

void Staff::displayInfo() const {
    cout << "\n----- Staff Info -----\n";
    cout << "Name: " << name << endl;
    cout << "Staff ID: " << staffID << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Age: " << age << endl;
    cout << "Contact: " << contact << endl;
    cout << "Role: " << role << endl;
    cout << "Salary: " << salary << endl;
}