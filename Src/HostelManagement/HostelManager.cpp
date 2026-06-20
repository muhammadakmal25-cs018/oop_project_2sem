#include "HostelManager.h"

HostelManager::HostelManager(const HostelBlock& block) {
    this->block = block;
}

void HostelManager::allocateRoom(Student* student, int roomNo) {
    Room* rooms = block.getRooms();
    for (int i = 0; i < block.getRoomCount(); i++) {
        if (rooms[i].getRoomNumber() == roomNo) {
            if (rooms[i].addOccupant(student))
                cout << student->getName() << " allocated to room " << roomNo << endl;
            else
                cout << "Room is full!\n";
            return;
        }
    }
    cout << "Room not found!\n";
}

void HostelManager::vacateRoom(Student* student, int roomNo) {
    Room* rooms = block.getRooms();
    for (int i = 0; i < block.getRoomCount(); i++) {
        if (rooms[i].getRoomNumber() == roomNo) {
            if (rooms[i].removeOccupant(student))
                cout << student->getName() << " removed from room " << roomNo << endl;
            else
                cout << "Student not found in room!\n";
            return;
        }
    }
    cout << "Room not found!\n";
}

void HostelManager::generateReport() const {
    cout << "\n===== Hostel Occupancy Report =====\n";
    block.displayBlock();
}

void HostelManager::displayHostel() const {
    block.displayBlock();
}