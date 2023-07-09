#include<iostream>
#include"Queue.h"
using namespace std;

int main(){
    int capacity;
    cout << "Enter Capacity" << endl;
    cin >> capacity;
    Queue<int> * queue = new Queue<int>(10);
    queue->enqueue(10);
    queue->enqueue(20);
    cout << queue -> getSize() << endl;
    cout << queue -> isEmpty() << endl;
    cout << queue -> front() << endl;
    cout << queue -> dequeue() << endl;
    cout << queue -> dequeue() << endl;
    cout << queue -> dequeue() << endl;
    cout << queue -> getSize() << endl;
}