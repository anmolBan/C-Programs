#include<iostream>
using namespace std;

class Student{
    string name;
    int rollno;

    public:
    Student(){
        cout << "Constructor called" << endl;
    }

    ~Student(){
        cout << "Destructor called" << endl;
    }


};

int main(){
    Student s1;
    Student s2;
    Student *s3 = new Student();
    delete s3;

}