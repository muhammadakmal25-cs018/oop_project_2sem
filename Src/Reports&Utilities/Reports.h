#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include "../person/Student.h"
#include "../library/Library.h"
#include "../finance/FeeRecord.h"
using namespace std;

class Reports {
public:
    static void studentReport(Student* students[], int count);
    static void feeReport(FeeRecord records[], int count);
    static void libraryReport(const Library& lib);
};

#endif