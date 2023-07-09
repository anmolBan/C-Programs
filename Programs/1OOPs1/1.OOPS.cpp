#include<iostream>
using namespace std;

class Student{

    string name;
    int rollno;
    int age;

    public:
    void setName(string name){
        this -> name = name;
    }

    void setRollno(int rollno){
        this -> rollno = rollno;
    }

    void setAge(int age){
        this -> age = age;
    }

    string getName(){
        return this -> name;
    }

    int getRollno(){
        return this -> rollno;
    }

    int getAge(){
        return this -> age;
    }

};

int main(){

    Student s1;
    s1.setName("Anmol");
    s1.setRollno(7);
    s1.setAge(24);

    cout << s1.getName() << " " << s1.getRollno() << " " << s1.getAge() << endl;

}