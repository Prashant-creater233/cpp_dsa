#include <iostream>
#include <vector>
using namespace std;

class Teacher
{
    // properties/ attributes
private:
    double salary;    
public:
    string name;
    string dept;
    string subject;
    //non-parameterized constructor
    // Teacher() {
    //     dept = "Computer Science";
    // }

    //parameterized constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    Teacher(Teacher &orgOj){
        cout << "Copy constructor called" << endl;
        this->name = orgOj.name;
        this->dept = orgOj.dept;
        this->subject = orgOj.subject;
        this->salary = orgOj.salary;
    }

    // methods/ member funnctions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    //setter
    // void setSalary(double s)
    // {
    //     salary = s;
    // }

    // //getter
    // double getSalary()
    // {
    //     return salary;
    // }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Dept: " << dept << endl;
        cout << "Subject: " << subject << endl;
        // cout << "Salary: " << getSalary() << endl;
    }
};


class Account {
    private:
        double balance;
        string password;  // data hiding

    public:
        string accountId;
        string userName;    
};

int main()
{
    Teacher t1("Prashant", "Computer Science", "Data Structures", 50000);  // parameterized constructor is called here
    // Teacher t2; 
    // t1.name = "Prashant";
    // t1.subject = "Data Structures";
    // t1.setSalary(50000);
    //  t1.getInfo();

    Teacher t2(t1);  // copy constructor is called here
    t2.getInfo();

    return 0;
}