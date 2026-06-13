// courses & enrollment management (encapsulation, operator overloading)
#include<iostream>
#include<string>
#include <vector>   
#include<stdexcept>
using namespace std;
// exception
class capacityexceeded:public exception{
    public:
    const char* what() const noexcept override{
        return "Course capacity exceeded. Cannot enroll more students.";
    }
};
// student clas
class student{
    private:
    string id;
    string name;
public:
    student(string id,string name){
        this->id=id;
        this->name=name;
    }
    string getid(){
        return id;
    }
    string getname(){
        return name;
    }
};
//  faculty class
class faculty{
    private:
    string id;
    string name;   
public:    faculty(string id,string name){
        this->id=id;
        this->name=name;
    }
    string getid(){
        return id;
    }
    string getname(){
        return name;
    }
};
//course class
class course{
    private:
    string Cours_code;
    string Cours_name;
    int cradit_hors;
    faculty* instructor;
    int max_capacity;
    int enrol_count;
    vector<student*> enrolled_students;
    vector<student*> waitlist;
public:
    course(string code,string name,int credit,faculty* instructor,int capacity):Cours_code(code),Cours_name(name),cradit_hors(credit),instructor(instructor),max_capacity(capacity),enrol_count(0){}
   string getcors_code(){
        return Cours_code;
    }

    void enroll(student* s){
        if(enrol_count>=max_capacity)
        throw capacityexceeded();
        enrolled_students.push_back(s);
        enrol_count++;
    }
//add waiting list
void addtowaitlist(student* s){
    waitlist.push_back(s);
}
//Operator ==

bool operator==(const course& c)
{
return Cours_code ==c.Cours_code;
}
// Operator +
vector<student*> operator+(course& c) {
vector<student*> merged =waitlist;
for (auto s:c.waitlist) {

merged. push_back(s);
}
return merged;
}
// friend operator<<
friend ostream& operator<<(ostream& os,const course& c){
    os<<"Course Code: "<<c.Cours_code<<endl;
    os<<"Course Name: "<<c.Cours_name<<endl;
    os<<"Credit Hours: "<<c.cradit_hors<<endl;
    os<<"Instructor: "<<c.instructor->getname()<<endl;
    os<<"capacity: "<<c.max_capacity<<endl;
    os<<"Enrolled Students: "<<c.enrolled_students.size()<<endl;
    return os;
}
};
// enrlment class
class enrollment{
    student* s;
    course* c;
    string enrollment_date;
    char grade;
public:
    enrollment(student* s,course* c,string date):s(s),c(c),enrollment_date(date),grade('I'){}
    void assigngrade(char g){
        grade=g;
    }
};
