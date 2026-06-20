#include "Room.h"

Room::Room(int roomNumber, string type, int floor) {
    this->roomNumber = roomNumber;
    this->type = type;
    this->floor = floor;
    occupantCount = 0;

    if (type == "single") maxOccupants = 1;
    else if (type == "double") maxOccupants = 2;
    else maxOccupants = 3;

    occupants = new Student*[maxOccupants];
    for (int i = 0; i < maxOccupants; i++)
        occupants[i] = nullptr;
}

Room::Room(const Room& other) {
    roomNumber = other.roomNumber;
    type = other.type;
    floor = other.floor;
    maxOccupants = other.maxOccupants;
    occupantCount = other.occupantCount;

    occupants = new Student*[maxOccupants];
    for (int i = 0; i < maxOccupants; i++)
        occupants[i] = other.occupants[i];
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete[] occupants;

        roomNumber = other.roomNumber;
        type = other.type;
        floor = other.floor;
        maxOccupants = other.maxOccupants;
        occupantCount = other.occupantCount;

        occupants = new Student*[maxOccupants];
        for (int i = 0; i < maxOccupants; i++)
            occupants[i] = other.occupants[i];
    }
    return *this;
}

Room::~Room() {
    delete[] occupants;
}

int Room::getRoomNumber() const { return roomNumber; }
string Room::getType() const { return type; }
int Room::getFloor() const { return floor; }
int Room::getOccupantCount() const { return occupantCount; }
int Room::getMaxOccupants() const { return maxOccupants; }

bool Room::addOccupant(Student* s) {
    if (occupantCount < maxOccupants) {
        occupants[occupantCount++] = s;
        return true;
    }
    return false;
}

bool Room::removeOccupant(Student* s) {
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i] == s) {
            for (int j = i; j < occupantCount - 1; j++)
                occupants[j] = occupants[j + 1];
            occupants[occupantCount - 1] = nullptr;
            occupantCount--;
            return true;
        }
    }
    return false;
}

void Room::displayRoom() const {
    cout << "\nRoom No: " << roomNumber
         << " | Type: " << type
         << " | Floor: " << floor
         << " | Occupants: " << occupantCount << "/" << maxOccupants << endl;

    for (int i = 0; i < occupantCount; i++) {
        cout << "  - " << occupants[i]->getName()
             << " (" << occupants[i]->getRollNo() << ")\n";
    }
}