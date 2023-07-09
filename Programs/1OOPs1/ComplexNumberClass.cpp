#include<iostream>
using namespace std;

class ComplexNumber{

    int real;
    int imaginary;

    public:
    ComplexNumber(int real, int imaginary){
        this -> real = real;
        this -> imaginary = imaginary;
    }

    void add(ComplexNumber const & c2){
        this -> real = this -> real + c2.real;
        this -> imaginary = this -> imaginary + c2.imaginary;
    }

    void multiply(ComplexNumber const & c2){
        int locReal = (this -> real * c2.real) + (-1 * (this -> imaginary * c2.imaginary));
        int locImaginary = (this -> real * c2.imaginary) + (this -> imaginary * c2.real);
        this -> real = locReal;
        this -> imaginary = locImaginary;
    }

    void print(){
        cout << this -> real << " + " << this -> imaginary << "i" << endl; 
    }
};

int main(){
    
    ComplexNumber c1(8, 5);
    ComplexNumber c2(5, 1);

    c1.add(c2);
    c1.print();
    c2.print();
}