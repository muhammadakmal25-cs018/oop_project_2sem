#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "../person/Student.h"
using namespace std;

class Room {
private:
    int roomNumber;
    string type;      // single / double / triple
    int floor;
    Student** occupants;
    int maxOccupants;
    int occupantCount;

public:
    Room(int roomNumber = 0, string type = "single", int floor = 0);
    Room(const Room& other);
    Room& operator=(const Room& other);
    ~Room();

    int getRoomNumber() const;
    string getType() const;
    int getFloor() const;
    int getOccupantCount() const;
    int getMaxOccupants() const;

    bool addOccupant(Student* s);
    bool removeOccupant(Student* s);
    void displayRoom() const;
};

#endif