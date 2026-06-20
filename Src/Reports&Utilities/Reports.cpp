#include "Reports.h"

void Reports::studentReport(Student* students[], int count) {
    cout << "\n===== STUDENT REPORT =====\n";
    for (int i = 0; i < count; i++) {
        if (students[i] != nullptr)
            students[i]->displayInfo();
    }
}

void Reports::feeReport(FeeRecord records[], int count) {
    cout << "\n===== FEE REPORT =====\n";
    for (int i = 0; i < count; i++) {
        records[i].displayFeeRecord();
    }
}

void Reports::libraryReport(const Library& lib) {
    cout << "\n===== LIBRARY REPORT =====\n";
    lib.displayAllItems();
}