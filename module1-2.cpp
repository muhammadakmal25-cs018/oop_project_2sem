#include<iostream>
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
    int gpa;
    float semester;
public:
    student(string name,int age,string cnic,string contact,string rollno,int gpa,float semester):person(name,age,cnic,contact){
        this->rollno=rollno;
        this->gpa=gpa;
        this->semester=semester;
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
public:
    Faculty(string name,int age,string cnic,string contact,string empid,string department,string designation):person(name,age,cnic,contact){
        this->empid=empid;
        this->department=department;
        this->designation=designation;
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
    }
};
class Staff:public person{
    string staffid;
    string role;
    double salary;
    public:
    Staff(string name,int age,string cnic,string contact,string staffid,double salary, string role):person(name,age,cnic,contact){
        this->staffid;
        this->role;
        this->salary;
    }
};
int main(){
student S1("Akmal",20,"16202-5709996-1","03300000","25-cs-018",3.4,2);
S1.displayinfo();
 return 0;   
}