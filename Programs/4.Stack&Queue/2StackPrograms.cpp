#include<iostream>
#include"LLStack.h"
using namespace std;

int main(){
    LLStack<int> * s = new LLStack<int>();
    for(int i = 1; i <= 10; i++){
        s -> push(i);
    }
    int popi = s -> pop();
    while(popi != 0){
        cout << popi << endl;
        popi = s -> pop();
    }
}