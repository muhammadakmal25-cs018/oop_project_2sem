#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include "../person/Student.h"
using namespace std;

class Utils {
public:
    static void sortStudentsByGPA(Student* students[], int count);
    static void searchStudentByRollNo(Student* students[], int count, string rollNo);
};

#endif