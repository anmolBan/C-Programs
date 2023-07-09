#include<iostream>
using namespace std;

class Student{

    string name;
    int rollno;
    static int totalStudent;

    public:
    Student(string name, int rollno){
        this -> name = name;
        this -> rollno = rollno;
        totalStudent++;
    }

    static int getTotalStudents(){
        return totalStudent;
    }
};

int Student :: totalStudent = 0;

int main(){
    Student s1("Anmol", 7), s2("Anuj", 1), s3("Mohit", 3);
    cout << Student :: getTotalStudents() << endl;
}