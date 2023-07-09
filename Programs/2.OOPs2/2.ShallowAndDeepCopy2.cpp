#include<iostream>
#include<cstring>
using namespace std;

class Student{
    char * name;
    int rollno;

    public:
    Student(char *name, int rollno){
        this -> rollno = rollno;

        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    void display(){
        cout << name << " " << rollno << endl;
    }
};

int main(){
    char name[] = "Anmol";
    int rollno = 7;

    Student s1(name, rollno);
    s1.display();
    name[0] = 'b';
    s1.display();

}