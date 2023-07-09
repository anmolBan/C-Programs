#include<iostream>
#include<cstring>
using namespace std;

class Fraction{

    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this -> numerator, this -> denominator);
        for(int i = 1; i <= j; i++){
            if(this -> numerator % i == 0 && this -> denominator % i == 0){
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    Fraction operator+(Fraction const & f2)const{
        int lcm = this -> denominator * f2.denominator;
        int x = lcm / (this -> denominator);
        int y = lcm / (f2.denominator);

        int num = this -> numerator * x + f2.numerator * y;

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    Fraction operator*(Fraction const & f2)const{
        int num = this -> numerator * f2.numerator;
        int deno = this -> denominator * f2.denominator;
        Fraction fNew(num, deno);
        fNew.simplify();
        return fNew;
    }

    Fraction operator/(Fraction const & f2)const{
        int num = this -> numerator * f2.denominator;
        int deno = this -> denominator * f2.numerator;
        Fraction fNew(num, deno);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const & f2)const{
        if(this -> numerator == f2.numerator && this -> denominator == f2.denominator){
            return true;
        }
        else{
            return false;
        }
    }

    // Pre-increment Operator
    Fraction& operator++(){ // Return type of this function is 'Fraction&' because we want to use nesting with this operator and to use nesting we have to return the reference so that the buffer memory does not create a copy.
        this -> numerator = this -> numerator + this -> denominator;
        simplify();

        return *this;
    }

    // Post-increment operator
    Fraction operator++(int){
        Fraction fNew = *this;
        this -> numerator = this -> numerator + this -> denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction & operator+=(Fraction const & f2){
        int lcm = this -> denominator * f2.denominator;
        int x = this -> denominator / lcm;
        int y = f2.denominator / lcm;

        int num = this -> numerator * x + f2.numerator * y;

        this -> numerator = num;
        this -> denominator = lcm;
        simplify();
        return *this;
    }

    void display()const{
        cout << this -> numerator << " / " << this -> denominator << endl;
    }

};

int main(){
    Fraction f1(5, 18);

    Fraction f2 = f1++;
    
    f1.display();
    f2.display();

    // Fraction f2(18, 5);
    
    // Fraction f3 = f1 + f2;
    // f3.display();
    // Fraction f4 = f1 * f2;
    // f4.display();
    // if(f1 == f2){
    //     cout << "true" << endl;
    // }
    // else{
    //     cout << "false" << endl;
    // }
}