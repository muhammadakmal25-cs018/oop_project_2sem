#include "HostelBlock.h"

HostelBlock::HostelBlock(string blockName, int roomCount) {
    this->blockName = blockName;
    this->roomCount = roomCount;

    if (roomCount > 0)
        rooms = new Room[roomCount];
    else
        rooms = nullptr;
}

HostelBlock::HostelBlock(const HostelBlock& other) {
    blockName = other.blockName;
    roomCount = other.roomCount;

    if (roomCount > 0) {
        rooms = new Room[roomCount];
        for (int i = 0; i < roomCount; i++)
            rooms[i] = other.rooms[i];
    } else {
        rooms = nullptr;
    }
}

HostelBlock& HostelBlock::operator=(const HostelBlock& other) {
    if (this != &other) {
        delete[] rooms;
        blockName = other.blockName;
        roomCount = other.roomCount;

        if (roomCount > 0) {
            rooms = new Room[roomCount];
            for (int i = 0; i < roomCount; i++)
                rooms[i] = other.rooms[i];
        } else {
            rooms = nullptr;
        }
    }
    return *this;
}

HostelBlock::~HostelBlock() {
    delete[] rooms;
}

string HostelBlock::getBlockName() const {
    return blockName;
}

int HostelBlock::getRoomCount() const {
    return roomCount;
}

Room* HostelBlock::getRooms() const {
    return rooms;
}

void HostelBlock::setRoom(int index, const Room& room) {
    if (index >= 0 && index < roomCount)
        rooms[index] = room;
}

void HostelBlock::displayBlock() const {
    cout << "\n===== Hostel Block: " << blockName << " =====\n";
    for (int i = 0; i < roomCount; i++)
        rooms[i].displayRoom();
}