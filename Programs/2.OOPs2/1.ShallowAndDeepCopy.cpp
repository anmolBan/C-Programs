#include<iostream>
using namespace std;

class Student{
    public:
    int *name;
    Student(int n[]){
        this -> name = n;
        cout << name[0] << " Class" << endl;
    }
};

int main(){
    int name[] = {1, 2, 3};
    Student s1(name);

    name[0] = 44;
    cout << name[0] << endl;
    cout << s1.name[0] << endl;
}


/**
 As we can see here in this piece of code that we are able to make chages
 in the name array because '=' creates a shallow copy and it messes the things
 up.
 **/ 