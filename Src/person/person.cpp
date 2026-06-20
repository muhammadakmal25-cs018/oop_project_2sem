#include "Person.h"

Person::Person(string name, string cnic, int age, string contact) {
    this->name = name;
    this->cnic = cnic;
    this->age = age;
    this->contact = contact;
}

Person::~Person() {}

string Person::getName() const {
    return name;
}

string Person::getCNIC() const {
    return cnic;
}

int Person::getAge() const {
    return age;
}

string Person::getContact() const {
    return contact;
}