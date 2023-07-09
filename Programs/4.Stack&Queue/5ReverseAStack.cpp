#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> * s1, stack<int> * s2){
    if(s1 -> empty()){
        return;
    }

    int topi = s1 -> top();
    s1 -> pop();
    reverseStack(s1, s2);
    while(s1 -> empty() != true){
        s2 -> push(s1->top());
        s1 -> pop();
    }
    s1 -> push(topi);
    while(s2 -> empty() != true){
        s1 -> push(s2->top());
        s2 -> pop();
    }
    return;
}

int main(){
    stack<int> * s1 = new stack<int>();
    stack<int> * s2 = new stack<int>();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int curr;
        cin >> curr;
        s1 -> push(curr);
    }

    reverseStack(s1, s2);

    while(s1 -> empty() != true){
        cout << s1 -> top() << " ";
        s1 -> pop();
    }
}