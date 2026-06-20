#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H

#include "../person/Student.h"

class Accommodation {
public:
    virtual void allocateRoom(Student* student, int roomNo) = 0;
    virtual void vacateRoom(Student* student, int roomNo) = 0;
    virtual ~Accommodation() {}
};

#endif