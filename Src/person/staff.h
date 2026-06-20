#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
private:
    string staffID;
    string role;
    double salary;

public:
    Staff(string name, string cnic, int age, string contact,  string staffID, string role, double salary);

    void displayInfo() const override;
};

#endif