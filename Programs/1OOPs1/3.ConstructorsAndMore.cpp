#include<iostream>
using namespace std;

class Student{

    public:

    string name;
    int rollno;

    Student(){

    }

    Student(string name, int rollno){
        this -> name = name;
        this -> rollno = rollno;
    }
};

int main(){

    Student *s1 = new Student("Anmol", 7);
    Student s2(*s1);
    Student s3;
    s3 = s2;

    cout << s1 -> name << " " << s2.name << " " << s2.name << " " << endl;

}