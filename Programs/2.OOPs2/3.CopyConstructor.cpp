#include<iostream>
#include<cstring>
using namespace std;

class Student{
    
    char * name;
    int rollno;

    public:
    Student(char * name, int rollno){
        this -> rollno = rollno;

        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    // Copy constructor
    Student(Student const & s){
        this -> rollno = s.rollno;

        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
    }

    void display(){
        cout << name << " " << rollno << endl;
    }

};

int main(){
    Student s1("Anmol", 7);
    Student s2(s1);
    s1.display();
    s2.display();
}