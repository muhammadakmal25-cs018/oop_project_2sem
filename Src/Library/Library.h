#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Journal.h"
using namespace std;

class OverdueException {
private:
    double fine;

public:
    OverdueException(double fine) {
        this->fine = fine;
    }

    void showError() const {
        cout << "Overdue item returned! Fine = Rs. " << fine << endl;
    }
};

struct IssueRecord {
    string rollNo;
    int itemID;
};

class Library {
private:
    vector<LibraryItem*> catalog;
    vector<IssueRecord> issuedItems;

public:
    ~Library();

    void addItem(LibraryItem* item);
    void displayAllItems() const;
    void searchByTitle(string t) const;
    void issueItem(string rollNo, int itemID);
    void returnItem(string rollNo, int itemID, int lateDays);

    void saveToFile(string filename);
    void loadFromFile(string filename);
};

#endif