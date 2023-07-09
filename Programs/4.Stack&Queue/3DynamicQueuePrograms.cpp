#include<iostream>
#include"DynamicQueue.h"
using namespace std;

int main(){
    DynamicQueue<int> * queue = new DynamicQueue<int>();
    for(int i = 1; i <= 19; i++){
        queue -> enqueue(i);
    }
    int fronti = queue -> dequeue();
    while(fronti != 0){
        cout << fronti << endl;
        fronti = queue -> dequeue();
    }
}