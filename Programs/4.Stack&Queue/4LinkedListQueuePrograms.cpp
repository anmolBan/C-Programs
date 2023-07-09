#include<iostream>
#include"QueueUsingLL.h"
using namespace std;

int main(){
    LLQueue<int> * queue = new LLQueue<int>();
    for(int i = 1; i <= 11; i++){
        queue -> enqueue(i);
    }
    while(queue -> getSize() != 0){
        cout << queue -> dequeue() << endl;
    }
}