#include <iostream>
using namespace std;

class Student{

    string name;
    int rollno;
    int age;

    public:
    Student(){
        cout << "Default constructor has been called." << endl;
    }

    Student(string name){
        cout << "Parameterized Constructor has been called." << endl;
        this -> name = name;
    }

    Student(string name, int rollno, int age){
        cout << "Parameterized constructor has been called." << endl;
        this -> name = name;
        this -> rollno = rollno;
        this -> age = age;
    }
};

int main()
{
    Student s1;
    Student s2("Anmol");
    Student s3("Anmol", 7, 24);
}