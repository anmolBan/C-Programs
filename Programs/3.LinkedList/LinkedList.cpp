#include<iostream>
#include"Node.h"
using namespace std;

Node * takeInput(){
    int curr;
    cin >> curr;
    Node * head = NULL;
    Node * prev = NULL;
    while(curr != -1){
        Node * newNode = new Node(curr);
        if(head == NULL){
            head = newNode;
            prev = newNode;
        }
        else{
            prev -> next = newNode;
            prev = newNode;
        }
        cin >> curr;
    }
    return head;
}

void printLL(Node * head){
    int count = 0;
    while(head != NULL && count <= 500){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

void printRecursiveLL(Node * head){
    if(head == NULL){
        cout << endl;
        return;
    }
    cout << head -> data << " ";
    printRecursiveLL(head -> next);
    return;
}

int getLength(Node * head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head -> next;
    }
    return length;
}

void printIthNode(Node * head, int i){
    int length = getLength(head);
    if(i < 0 || i >= length){
        return;
    }

    while(i != 0){
        head = head -> next;
        i--;
    }
    cout << head -> data << endl;
    return;
}

Node * insertNodeAtIth(Node * head, int element, int i){
    int length = getLength(head);
    if(i < 0 || i > length){
        return head;
    }
    Node * curr = head;
    Node * prev = NULL;
    Node * newNode = new Node(element);
    while(i != 0){
        prev = curr;
        curr = curr -> next;
        i--;
    }
    if(prev == NULL){
        newNode -> next = curr;
        head = newNode;
        return head;
    }
    prev -> next = newNode;
    newNode -> next = curr;
    return head;
}

Node * step_insertNodeAtIthRecursive(Node * head, int element, int i){
    if(i == 0){
        Node * newNode = new Node(element);
        newNode -> next = head;
        return newNode;
    }
    Node * curr = step_insertNodeAtIthRecursive(head -> next, element, --i);
    head -> next = curr;
    return head;
}

Node * insertNodeAtIthRecursive(Node * head, int element, int i){
    int length = getLength(head);
    if(i < 0 || i > length){
        return head;
    }
    return step_insertNodeAtIthRecursive(head, element, i);
}

Node * deleteFromIth(Node * head, int i){
    int length = getLength(head);
    if(i < 0 || i >= length){
        return head;
    }
    Node * curr = head;
    Node * prev = NULL;
    while(i != 0){
        prev = curr;
        curr = curr -> next;
        i--;
    }
    if(prev == NULL){
        head = head -> next;
        return head;
    }
    prev -> next = curr -> next;
    return head;
}

Node * step_deleteFromIthRecursive(Node * head, int i){
    if(i == 0){
        head = head -> next;
        return head;
    }
    Node * curr = step_deleteFromIthRecursive(head -> next, --i);
    head -> next = curr;
    return head;
}

Node * deleteFromIthRecursive(Node * head, int i){
    int length = getLength(head);
    if(i < 0 || i >= length){
        return head;
    }
    return step_deleteFromIthRecursive(head, i);
}

int findNode(Node * head, int data, int i = 0){
    if(head == NULL){
        return -1;
    }
    if(head -> data == data){
        return i;
    }
    return findNode(head -> next, data, i++);
}

Node * appendLastNToFirst(Node * head, int n){
    int length = getLength(head);
    int rem = length - n;
    Node * prev = NULL;
    Node * curr = head;
    for(int i = 0; i < rem; i++){
        prev = curr;
        curr = curr -> next;
    }
    if(prev == NULL){
        return head;
    }
    prev -> next = NULL;
    Node * newHead = curr;
    while(curr != NULL){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = head;
    return newHead;
}

Node * removeDuplicates(Node * head){
    Node * prev = head;
    Node * curr = head -> next;
    while(curr != NULL){
        if(curr -> data != prev -> data){
            prev -> next = curr;
            prev = curr;
        }
        curr = curr -> next;
    }
    prev -> next = curr;
    return head;
}

void printReverseLinkedList(Node * head){
    if(head == NULL){
        return;
    }
    printReverseLinkedList(head -> next);
    cout << head -> data << " ";
}

Node * findMidpoint(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node * reverseLinkedList(Node * head){
    if(head == NULL){
        return head;
    }
    if(head -> next == NULL){
        return head;
    }
    Node * currHead = reverseLinkedList(head -> next);
    Node * tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return currHead;
}

Node * reverseLLIterative(Node * head){
    Node * temp = NULL;
    Node * tail = NULL;
    Node * revHead = NULL;
    while(head != NULL){
        if(temp == NULL){
            temp = head;
            head = head -> next;
            temp -> next = NULL;
            revHead = temp;
        }
        else{
            temp = head;
            head = head -> next;
            temp -> next = revHead;
            revHead = temp;
        }
    }
    return revHead;
}

bool checkPalindrome(Node * head){
    if(head == NULL){
        return true;
    }
    Node * slow = head;
    Node * fast = head;
    Node * prev = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
    }
    prev -> next = NULL;
    slow = reverseLinkedList(slow);
    while(head != NULL && slow != NULL){
        if(head -> data == slow -> data){
            head = head -> next;
            slow = slow -> next;
        }
        else{
            return false;
        }
    }
    return true;
}

Node * mergeTwoLL(Node * head1, Node * head2){
    Node * newHead = NULL;
    Node * curr = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data <= head2 -> data){
            if(newHead == NULL){
                newHead = head1;
                curr = head1;
                head1 = head1 -> next;
            }
            else{
                curr -> next = head1;
                curr = head1;
                head1 = head1 -> next;
            }
        }
        else{
            if(newHead == NULL){
                newHead = head2;
                curr = head2;
                head2 = head2 -> next;
            }
            else{
                curr -> next = head2;
                curr = head2;
                head2 = head2 -> next;
            }
        }
    }
    while(head1 != NULL){
        if(newHead == NULL){
            newHead = head1;
            curr = head1;
            head1 = head1 -> next;
        }
        else{
            curr -> next = head1;
            curr = head1;
            head1 = head1 -> next;
        }
    }
    while(head2 != NULL){
        if(newHead == NULL){
            newHead = head2;
            curr = head2;
            head2 = head2 -> next;
        }
        else{
            curr -> next = head2;
            curr = head2;
            head2 = head2 -> next;
        }
    }
    return newHead;
}

Node * evenAfterOdd(Node * head){
    Node * evenHead = NULL;
    Node * evenPrev = NULL;
    Node * oddHead = NULL;
    Node * oddPrev = NULL;
    while(head != NULL){
        if(head -> data % 2 == 0){
            if(evenHead == NULL){
                evenHead = head;
                evenPrev = head;
                head = head -> next;
                evenPrev -> next = NULL;
            }
            else{
                evenPrev -> next = head;
                evenPrev = evenPrev -> next;
                head = head -> next;
                evenPrev -> next = NULL;
            }
        }
        else{
            if(oddHead == NULL){
                oddHead = head;
                oddPrev = head;
                head = head -> next;
                oddPrev -> next = NULL;
            }
            else{
                oddPrev -> next = head;
                oddPrev = oddPrev -> next;
                head = head -> next;
                oddPrev -> next = NULL;
            }
        }
    }
    if(oddPrev == NULL){
        return evenHead;
    }
    oddPrev -> next = evenHead;
    return oddHead;
}

Node * skipMdeleteN(Node * head, int m, int n){
    int length = getLength(head);
    if(m >= length){
        return head;
    }
    Node * newHead = NULL;
    Node * prev = NULL;
    int i = 0;
    while(i < length){
        for(int j = 0; j < m && i < length; j++, i++){
            if(newHead == NULL){
                newHead = head;
                prev = head;
                head = head -> next;
                prev -> next = NULL;
            }
            else{
                prev -> next = head;
                prev = prev -> next;
                head = head -> next;
                prev -> next = NULL;
            }
        }
        for(int j = 0; j < n && i < length; j++, i++){
            head = head -> next;
        }
    }
    return newHead;
}

Node * swapNodes(Node * head, int i, int j){
    if(i == j){
        return head;
    }
    if(i > j){
        int temp = i;
        i = j;
        j = temp;
    }
    int curr_i = i, curr_j = j;
    Node * prev = head;
    Node * curr = head;
    Node * p1 = NULL;
    Node * c1 = NULL;
    Node * p2 = NULL;
    Node * c2 = NULL;
    while(curr != NULL){
        if(curr_i == 0){
            p1 = prev;
            c1 = curr;
        }
        if(curr_j == 0){
            p2 = prev;
            c2 = curr;
        }
        curr_i--;
        curr_j--;
        prev = curr;
        curr = curr -> next;
    }
    if(j - i > 2){
        Node * temp = c1 -> next;
        p1 -> next = c2;
        p2 -> next = c1;
        c1 -> next = c2 -> next;
        c2 -> next = temp;
        if(i == 0){
            head = c2;
        }
        return head;
    }
    p1 -> next = c2;
    p2 -> next = c1;
    c1 -> next = c2 -> next;
    c2 -> next = p2;
    if(i == 0){
        head = c2;
    }
    return head;
}

Node * kReverse(Node * head, int k){
    if(k == 0){
        return head;
    }
    Node * newHead = NULL;
    Node * curr = head;
    while(k != 0){
        if(k == 1){
            Node * temp = curr;
            curr = curr -> next;
            temp -> next = NULL;
            k--;
        }
        else{
            k--;
            curr = curr -> next;
        }
    }
    newHead = curr;
    head = reverseLinkedList(head);
    curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = newHead;
    return head;

}

int main(){
    Node * head = takeInput();
    printLL(head);
    head = kReverse(head, 0);
    printLL(head);
}