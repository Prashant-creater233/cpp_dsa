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

    // methods/ member funnctions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    //setter
    void setSalary(double s)
    {
        salary = s;
    }

    //getter
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    Teacher t1;
    t1.name = "Prashant";
    t1.dept = "Computer Science";
    t1.subject = "Data Structures";
    t1.setSalary(50000);

    cout << "Teacher Name: " << t1.name << endl;
    cout << "Teacher Dept: " << t1.dept << endl;
    cout << "Teacher Subject: " << t1.subject << endl;
    cout << "Teacher Salary: " << t1.getSalary() << endl;
    return 0;
}