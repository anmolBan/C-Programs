#include<iostream>
using namespace std;
class Fraction{

    int numerator;
    int denominator;

    public:

    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void setNumerator(int numerator){
        this -> numerator  = numerator;
    }

    void setDenominator(int denominator){
        this -> denominator = denominator;
    }

    int getNumerator() const{ //Marked 'const' because this function isn't making chages in the class properties
        return this -> numerator;
    }

    int getDenominator() const{ //Marked 'const' because this function isn't making chages in the class properties
        return this -> denominator;
    }

    void print() const{ //Marked 'const' because this function isn't making chages in the class properties
        cout << numerator << "/" << denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this -> numerator, this -> denominator);
        for(int i = 1; i <= j; i++){
            if((this -> numerator) % i == 0 && (this -> denominator % i) == 0){
                gcd = i;
            }
        }
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    void add(Fraction const & f2){
        int lcm = this -> denominator * f2.denominator;
        int x = lcm / (this -> denominator);
        int y = lcm / (f2.denominator);
        
        int num = (this -> numerator) * x + (f2.numerator) * y;

        this -> numerator = num;
        this -> denominator = lcm;

        simplify();
    }

    void multiply(Fraction const & f2){
        this -> numerator = this -> numerator * f2.numerator;
        this -> denominator = this -> denominator * f2.denominator;

        simplify();
    }

    void divide(Fraction const & f2){
        this -> numerator = this -> numerator * f2.denominator;
        this -> denominator = this -> denominator * f2.numerator;
        simplify();
    }
};

int main(){
    Fraction f1(5, 18);
    Fraction f2(18, 5);
    f1.multiply(f2);
    f1.print();
}