#include<iostream>
#include"LLNode.h"
using namespace std;

int main(){
    Node<int>*head = new Node<int>(10);
    Node<int>*head2 = new Node<int>(20);
    Node<int>*head3 = new Node<int>(30);
    Node<int>*head4 = new Node<int>(40);
    Node<int>*head5 = new Node<int>(50);



    head -> next = head2;
    head2 -> next = head3;
    head3 -> next = head4;
    head4 -> next = head5;

    delete head;
}