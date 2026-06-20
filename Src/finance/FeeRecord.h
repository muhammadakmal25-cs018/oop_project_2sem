#ifndef FEERECORD_H
#define FEERECORD_H

#include <iostream>
#include <string>
#include "../person/Student.h"
using namespace std;

class FeeRecord {
private:
    Student* studentRef;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;

public:
    FeeRecord(Student* studentRef = nullptr, double semesterFee = 0, double hostelFee = 0, double libraryFine = 0, double totalPaid = 0);

    // Copy constructor
    FeeRecord(const FeeRecord& other);

    // Copy assignment operator
    FeeRecord& operator=(const FeeRecord& other);

    void calculateBalance();
    void displayFeeRecord() const;

    // operator -= to record payment
    FeeRecord& operator-=(double payment);

    double getBalance() const;
    Student* getStudentRef() const;
};

#endif