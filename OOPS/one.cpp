#include <iostream>
#include <vector>
using namespace std;

// class Teacher
// {
//     // properties/ attributes
// private:
//     double salary;    
// public:
//     string name;
//     string dept;
//     string subject;
//     //non-parameterized constructor
//     // Teacher() {
//     //     dept = "Computer Science";
//     // }

//     //parameterized constructor
//     Teacher(string name, string dept, string subject, double salary) {
//         this->name = name;
//         this->dept = dept;
//         this->subject = subject;
//         this->salary = salary;
//     }

//     Teacher(Teacher &orgOj){
//         cout << "Copy constructor called" << endl;
//         this->name = orgOj.name;
//         this->dept = orgOj.dept;
//         this->subject = orgOj.subject;
//         this->salary = orgOj.salary;
//     }

//     // methods/ member funnctions
//     void changeDept(string newDept)
//     {
//         dept = newDept;
//     }

//     //setter
//     // void setSalary(double s)
//     // {
//     //     salary = s;
//     // }

//     // //getter
//     // double getSalary()
//     // {
//     //     return salary;
//     // }

//     void getInfo() {
//         cout << "Name: " << name << endl;
//         cout << "Dept: " << dept << endl;
//         cout << "Subject: " << subject << endl;
//         // cout << "Salary: " << getSalary() << endl;
//     }
// };


// class Account {
//     private:
//         double balance;
//         string password;  // data hiding

//     public:
//         string accountId;
//         string userName;    
// };

// int main()
// {
//     Teacher t1("Prashant", "Computer Science", "Data Structures", 50000);  // parameterized constructor is called here
//     // Teacher t2; 
//     // t1.name = "Prashant";
//     // t1.subject = "Data Structures";
//     // t1.setSalary(50000);
//     //  t1.getInfo();

//     Teacher t2(t1);  // copy constructor is called here
//     t2.getInfo();

//     return 0;
// }


// class Student {
//     public:
//         string name;
//         double* cgpaPtr;  // pointer to double

//         Student(string name, double cgpa) {
//             this->name = name;
//             cgpaPtr = new double;  // allocate memory for cgpa
//             *cgpaPtr = cgpa;
//         }
 
//         // ye hmara copy constructor h jo ki object ko copy krne k liye use hota h 
//         Student(Student &obj){
//             cout << "Copy constructor called" << endl;
//             this->name = obj.name;
//             cgpaPtr = new double;  // allocate new memory for cgpa
//             *cgpaPtr = *(obj.cgpaPtr);  // copy the value of cg
//         }

//         // destructor to free the allocated memory
//         ~Student() {
//             delete cgpaPtr;  // free the allocated memory
//         }

//         void getInfo() {
//             cout << "Name: " << name << endl;
//             cout << "CGPA: " << *cgpaPtr << endl;
//         }
// };

// int main(){
//     Student s1("prashant", 9.8);
//     // s1.getInfo();

//     Student s2(s1);  // copy constructor is called here
//     // s2.getInfo();

//     s1.getInfo();
//     *(s2.cgpaPtr) = 8.5;  // changing the value of cgpa for s2
//     s1.getInfo();  // this will also change the value of cgpa for s1 as well because both s1 and s2 are pointing to the same memory location

//     return 0;
// }



// Inheritance in C++: It is a mechanism in which one class acquires the properties (data members) and behaviors (member functions) of another class. The class that inherits the properties of another class is called the derived class (or child class), and the class whose properties are inherited is called the base class (or parent class).

//single inheritance

// class Person {
//     public:
//         string name;
//         int age;

//         Person(string name, int age) {
//             this->name = name;
//             this->age = age;
//         }

//         // Person() {
//         //     cout << "Parent constructor called" << endl;
//         // }

//         ~Person() {
//             cout << "Parent destructor called" << endl;
//         }

// };

// class Student : public Person {
//     public:
//         int rollNo;

//         // Student() {
//         //     cout << "child constructor called" << endl;
//         // }

//         Student(string name, int age, int rollNo) : Person(name, age) {
//             this->rollNo = rollNo;
//         }

//         ~Student() {
//             cout << "Child destructor called" << endl;
//         }

//         void getInfo() {
//             cout << "Name: " << name << endl;
//             cout << "Age: " << age << endl;
//             cout << "Roll No: " << rollNo << endl;
//         }
// };

// int main() {
//     Student s1("Prashant", 20, 101);  // iska andar tab likhage jab apna constrructor khud likh rhe h to parent ka constructor call krna hoga otherwise parent ka constructor call nhi hoga
//     // s1.name = "Prashant"; // or ye tab linkhange tab jab apna constructor default call hoga
//     // s1.age = 20;
//     // s1.rollNo = 101;
//     s1.getInfo();

//     return 0;
// }


// Multi-level inheritance

// class Person {
//     public:
//         string name;
//         int age;
// };

// class Student : public Person {
//     public:
//         int rollNo;
// };

// class GradStudent : public Student {
//     public:
//         string researchArea;
// };

// int main() {
//     GradStudent s1;
//     s1.name = "Prashant";
//     s1.age = 20;
//     s1.rollNo = 101;
//     s1.researchArea = "Artificial Intelligence";

//     cout << "Name: " << s1.name << endl;
//     cout << "Age: " << s1.age << endl;
//     cout << "Roll No: " << s1.rollNo << endl;
//     cout << "Research Area: " << s1.researchArea << endl;
//     return 0;
// }


// Multiple inheritance

// class Student {
    
//     public:
//         string name;
//         int rollNo;
// };

// class Teacher {
//     public:
//         string subject;
//         double salary;
// };

// class TeachingAssistant : public Student, public Teacher {
    
// };

// int main() {
//     TeachingAssistant ta1;
//     ta1.name = "Prashant";
//     ta1.rollNo = 101;
//     ta1.subject = "Data Structures";
//     ta1.salary = 50000;

//     cout << "Name: " << ta1.name << endl;
//     cout << "Roll No: " << ta1.rollNo << endl;
//     cout << "Subject: " << ta1.subject << endl;
//     cout << "Salary: " << ta1.salary << endl;

//     return 0;
// }


// Hierarchial inheritance

// class Person {
//     public:
//         string name;
//         int age;
// };

// class Student : public Person {
//     public:
//         int rollNo;
// };

// class Teacher : public Person {
//     public:
//         string subject;
//         double salary;
// };

// int main() {
//     Student s1;
//     s1.name = "Prashant";
//     s1.age = 20;
//     s1.rollNo = 101;

//     Teacher t1;
//     t1.name = "John";
//     t1.age = 35;
//     t1.subject = "Data Structures";
//     t1.salary = 50000;

//     cout << "Student Name: " << s1.name << endl;
//     cout << "Student Age: " << s1.age << endl;
//     cout << "Student Roll No: " << s1.rollNo << endl;

//     cout << "Teacher Name: " << t1.name << endl;
//     cout << "Teacher Age: " << t1.age << endl;
//     cout << "Teacher Subject: " << t1.subject << endl;
//     cout << "Teacher Salary: " << t1.salary << endl;

//     return 0;
// }


// Hybrid inheritance
// class Person {
//     public:
//         string name;
//         int age;
// };

// class Student : public Person {
//     public:
//         int rollNo;
// };

// class Teacher : public Person {
//     public:
//         string subject;
//         double salary;
// };

// class TeachingAssistant : public Student, public Teacher {
    
// };

// class GraduateStudent : public Student {
//     public:
//         string researchArea;
// };

// class GraduateTeachingAssistant : public GraduateStudent, public Teacher {
    
// };



// Polymorphism in C++: It is the ability of a function, object or operator to take on multiple forms. There are two types of polymorphism in C++: compile-time polymorphism (also known as static polymorphism) and run-time polymorphism (also known as dynamic polymorphism).

// example of constructor overloading (compile-time polymorphism)
// class Student {
//     public:
//         string name;

//         Student() {
//             cout << "non-parameterized constructor called" << endl;
//         }
        
//         Student(string name) {
//             this->name = name;
//             cout << "Parameterized constructor called for " << name << endl;
//         }
//     };
    
//     int main() {
        
//         Student s1;  // non-parameterized constructor is called here
//         Student s2("Prashant");  // parameterized constructor is called here
//     }


// example of function overloading (compile-time polymorphism)

// class Print {
    
//     public:
//         void display(int x) {
//             cout << "Integer: " << x << endl;
//         }

//         void display(char ch) {
//             cout << "Character: " << ch << endl;
//         }

//         void display(string s) {
//             cout << "String: " << s << endl;
//         }  
// };

// int main() {
//     Print p1;
//     p1.display(10);  // calls display(int)
//     p1.display('A');  // calls display(char)
//     p1.display("Hello");  // calls display(string)
// }


// Operator overloading (compile-time polymorphism)

