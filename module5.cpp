#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string rollNo;
    Student(string n="",string r="") { 
        name=n;
        rollNo=r;
    }
};
class Accommodation {
public:
    virtual void allocateRoom(Student* s)=0;
    virtual void vacateRoom(Student* s)=0;
};
class Reportable {
public:
    virtual void generateReport()=0;
};
class Room {
public:
    int roomNumber;
    string type;
    Student* occupant;
    Room(int rn=0,string t="Single") {
        roomNumber=rn;
        type=t;
        occupant=nullptr;
    }
};
class HostelBlock {
public:
    string blockName;
    Room rooms[3];
    HostelBlock(string name="A") {
        blockName=name;
        rooms[0]=Room(101,"Single");
        rooms[1]=Room(102,"Double");
        rooms[2]=Room(103,"Triple");
    }
};
class HostelManager:public Accommodation,public Reportable {
private:
    HostelBlock block;
public:
    HostelManager():block("A") {}
    void allocateRoom(Student* s) override {
        for (int i=0;i<3;i++) {
            if (block.rooms[i].occupant==nullptr) {
                block.rooms[i].occupant=s;
                cout<<s->name<<" Allocated Room "
                     <<block.rooms[i].roomNumber<<endl;
                return;
            }
        }
        cout<<"No Room Available!"<<endl;
    }
    void vacateRoom(Student* s) override {
        for(int i=0;i<3;i++) {
            if (block.rooms[i].occupant==s) {
                block.rooms[i].occupant=nullptr;
                cout << s->name<<" vacated Room"
                     <<block.rooms[i].roomNumber << endl;
            }
        }
    }
    void generateReport() override {
        cout<<"Hostel Occupancy Report"<<endl;
        for(int i=0;i<3;i++) {
            cout<<"Room"<<block.rooms[i].roomNumber<<":";
            if(block.rooms[i].occupant)
                cout<<block.rooms[i].occupant->name;
            else
                cout<<"Empty";
            cout<<endl;
        }
    }
};
int main() {
    Student s1("Akmal","25-CS-018");
    Student s2("faizan","25-CS-037");
    HostelManager hm;

    hm.allocateRoom(&s1);
    hm.allocateRoom(&s2);
    hm.generateReport();

    hm.vacateRoom(&s1);

    hm.generateReport();

    return 0;
}