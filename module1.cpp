#include<iostream>
#include<string>
#include <vector>
using namespace std;
class person {
    protected:
    string name;
    int age;
    string cnic;
    string contact;
public:
    person(string name,int age,string cnic,string contact){
        this->name=name;
        this->age=age;
        this->cnic=cnic;
        this->contact=contact;
    }
    virtual void displayinfo()=0;
      
};
class student:public person{
    string rollno;
    float gpa;
    int semester;
    vector<string> enroll_course;
public:
    student(string name,int age,string cnic,string contact,string rollno,float gpa,int semester, const vector<string>& courses):person(name,age,cnic,contact){
        this->rollno=rollno;
        this->gpa=gpa;
        this->semester=semester;
        this->enroll_course = courses;
       
    }
   
   void displayinfo() override{
        cout<<"-----------Student Information---------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"CNIC: "<<cnic<<endl;
        cout<<"Contact: "<<contact<<endl;
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"GPA: "<<gpa<<endl;
        cout<<"Semester: "<<semester<<endl;
        cout<<"Enrolled Courses: "<<endl;
        for(const auto& course : enroll_course){
            cout<<"- "<<course<<endl;
        }
    }
    char calgrade(){
        if(gpa>=3.5){   return 'A';
        }
        else if(gpa>=3.0){return 'B';
        }
        else if(gpa>=2.5){ return 'C';
        }
        else if(gpa>=2.0){return 'D';
        }
        else{   return 'F';
        }
    
}
};
class Faculty:public person{
    string empid;
    string department;
    string designation;
    vector<string> assigned_courses;
public:
    Faculty(string name,int age,string cnic,string contact,string empid,string department,string designation, const vector<string>& courses):person(name,age,cnic,contact){
        this->empid=empid;
        this->department=department;
        this->designation=designation;
        this->assigned_courses = courses;
    }

    void displayinfo() override{
        cout<<"-----------Faculty Information---------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"CNIC: "<<cnic<<endl;
        cout<<"Contact: "<<contact<<endl;
        cout<<"Employee ID: "<<empid<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Assigned Courses: "<<endl;
        for(const auto& course : assigned_courses){
            cout<<"- "<<course<<endl;
        }
    }
};
class Staff:public person{
    string staffid;
    string role;
    float salary;
    public:
    Staff(string name,int age,string cnic,string contact,string staffid,float salary, string role):person(name,age,cnic,contact){
        this->staffid=staffid;
        this->role=role;
        this->salary=salary;
    }
void displayinfo() override{
        cout<<"-----------Staff Information---------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"CNIC: "<<cnic<<endl;
        cout<<"Contact: "<<contact<<endl;
        cout<<"Staff ID: "<<staffid<<endl;
        cout<<"Role: "<<role<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
int main(){
student s1("Ali",20,"12345-6789012-3","03001234567","S123",3.8,4,{"Math","Physics","Chemistry"});
Faculty f1("imran",45,"98765-4321098-7","03007654321","F456","Computer Science","Professor",{"Data Structures","Algorithms","Operating Systems"});
Staff st1("Sara",30,"56789-0123456-8","03009876543","ST789",50000,"Administrator");
s1.displayinfo();
f1.displayinfo();
st1.displayinfo();


return 0;   

}