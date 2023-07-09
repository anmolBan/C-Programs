#include<iostream>
#include"stack1.h"
#include"DynamicStack.h"
using namespace std;

int main(){
    DStack<int> * s = new DStack<int>();
    for(int i = 1; i <= 15; i++){
        s -> push(i);
    }
    int popi = s -> pop();
    while(popi != -1){
        cout << popi << endl;
        popi = s -> pop();
    }
}