#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H

#include "Room.h"

class HostelBlock {
private:
    string blockName;
    Room* rooms;
    int roomCount;

public:
    HostelBlock(string blockName = "", int roomCount = 0);
    HostelBlock(const HostelBlock& other);
    HostelBlock& operator=(const HostelBlock& other);
    ~HostelBlock();

    string getBlockName() const;
    int getRoomCount() const;
    Room* getRooms() const;

    void setRoom(int index, const Room& room);
    void displayBlock() const;
};

#endif