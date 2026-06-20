#ifndef REPORTABLE_H
#define REPORTABLE_H

class Reportable {
public:
    virtual void generateReport() const = 0;
    virtual ~Reportable() {}
};

#endif