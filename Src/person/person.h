#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string cnic;
    int age;
    string contact;

public:
    Person(string name, string cnic, int age, string contact);
    virtual ~Person();

    virtual void displayInfo() const = 0;

    string getName() const;
    string getCNIC() const;
    int getAge() const;
    string getContact() const;
};

#endif