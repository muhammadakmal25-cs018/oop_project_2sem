#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H

#include "Accommodation.h"
#include "Reportable.h"
#include "HostelBlock.h"

class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock block;

public:
    HostelManager(const HostelBlock& block);

    void allocateRoom(Student* student, int roomNo) override;
    void vacateRoom(Student* student, int roomNo) override;
    void generateReport() const override;

    void displayHostel() const;
};

#endif