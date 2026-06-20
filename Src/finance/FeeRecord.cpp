#include "FeeRecord.h"

FeeRecord::FeeRecord(Student* studentRef, double semesterFee,double hostelFee, double libraryFine, double totalPaid) {
    this->studentRef = studentRef;
    this->semesterFee = semesterFee;
    this->hostelFee = hostelFee;
    this->libraryFine = libraryFine;
    this->totalPaid = totalPaid;
    calculateBalance();
}

FeeRecord::FeeRecord(const FeeRecord& other) {
    studentRef = other.studentRef;
    semesterFee = other.semesterFee;
    hostelFee = other.hostelFee;
    libraryFine = other.libraryFine;
    totalPaid = other.totalPaid;
    balance = other.balance;
}

FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this != &other) {
        studentRef = other.studentRef;
        semesterFee = other.semesterFee;
        hostelFee = other.hostelFee;
        libraryFine = other.libraryFine;
        totalPaid = other.totalPaid;
        balance = other.balance;
    }
    return *this;
}

void FeeRecord::calculateBalance() {
    balance = (semesterFee + hostelFee + libraryFine) - totalPaid;
}

void FeeRecord::displayFeeRecord() const {
    cout << "\n===== Fee Record =====\n";
    if (studentRef != nullptr) {
        cout << "Student: " << studentRef->getName() << endl;
        cout << "Roll No: " << studentRef->getRollNo() << endl;
    }
    cout << "Semester Fee: " << semesterFee << endl;
    cout << "Hostel Fee: " << hostelFee << endl;
    cout << "Library Fine: " << libraryFine << endl;
    cout << "Total Paid: " << totalPaid << endl;
    cout << "Balance: " << balance << endl;
}

FeeRecord& FeeRecord::operator-=(double payment) {
    totalPaid += payment;
    calculateBalance();
    return *this;
}

double FeeRecord::getBalance() const {
    return balance;
}

Student* FeeRecord::getStudentRef() const {
    return studentRef;
}