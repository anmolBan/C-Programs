/**
 * Here we are going to use initialization list
 * We will declare the 'rollno' to be constant, and as we all know that if we
 declare any variable as constant then we need to initialize it at the same time.
 * So to achieve this we will use initialization list.
 * **/

#include<iostream>
#include<cstring>
using namespace std;

class Student{
    string name;
    int const rollno;

    public:

    Student(string name, int rollno) : rollno(rollno){
        this -> name = name;
    }

    void display(){
        cout << this -> name << " " << this -> rollno << endl;
    }
};

int main(){
    Student s1("Anmol", 7);
    s1.display();
}