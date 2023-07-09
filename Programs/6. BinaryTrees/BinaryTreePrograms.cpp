#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
#include <bits/stdc++.h>
#include<vector>
#include"LLNode.h"
using namespace std;

template<typename T>
void printLevelWise(BinaryTreeNode<T>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<T>*> * que = new queue<BinaryTreeNode<int>*>();
    que -> push(root);
    while(!que -> empty()){
        BinaryTreeNode<T> * currNode = que -> front();
        que -> pop();
        cout << currNode -> data << ": ";
        if(currNode -> left != NULL){
            cout << currNode -> left -> data << ", ";
            que -> push(currNode -> left);
        }
        if(currNode -> right != NULL){
            cout << currNode -> right -> data;
            que -> push(currNode -> right);
        }
        cout << endl;
    }
}

template<typename T>
BinaryTreeNode<T> * takeInput(){
    cout << "Enter the value of Root Node:" << endl;
    int rootData;
    cin >> rootData;
    BinaryTreeNode<T> * root = new BinaryTreeNode<T>(rootData);
    queue<BinaryTreeNode<T>*> * que = new queue<BinaryTreeNode<T>*>();
    que -> push(root);
    while(!que -> empty()){
        BinaryTreeNode<T>* currNode = que -> front();
        que->pop();
        cout << "Enter the value of left child of Node: " << currNode ->data << endl;
        T left;
        cin >> left;
        cout << "Enter the value of right child of Node: " << currNode -> data << endl;
        T right;
        cin >> right;
        if(left != -1){
            BinaryTreeNode<T>* leftChild = new BinaryTreeNode<T>(left);
            currNode -> left = leftChild;
            que -> push(leftChild);
        }
        if(right != -1){
            BinaryTreeNode<T>* rightChild = new BinaryTreeNode<T>(right);
            currNode -> right = rightChild;
            que -> push(rightChild);
        }
    }
    return root;
}

template<typename T>
int countNodes(BinaryTreeNode<T> * root){
    if(root == NULL){
        return 0;
    }
    int count = 1;
    count += countNodes(root -> left);
    count += countNodes(root -> right);
    return count;
}

template<typename T>
bool findNode(BinaryTreeNode<T> * root, T x){
    if(root == NULL){
        return false;
    }
    if(root -> data == x){
        return true;
    }
    bool ans = findNode(root -> left, x);
    if(ans){
        return true;
    }
    return findNode(root -> right, x);
}

template<typename T>
int height(BinaryTreeNode<T>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

template<typename T>
BinaryTreeNode<T>* mirror(BinaryTreeNode<T> * root){
    if(root == NULL){
        return root;
    }
    mirror(root -> left);
    mirror(root -> right);
    BinaryTreeNode<T> * temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    return root;
}

template<typename T>
void preOrderTraversal(BinaryTreeNode<T> * root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

template<typename T>
void postOrderTraversal(BinaryTreeNode<T> * root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

pair<int, int> findDiameterStep(BinaryTreeNode<int>*root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> p1 = findDiameterStep(root -> left);
    pair<int, int> p2 = findDiameterStep(root -> right);
    pair<int, int> p3;
    p3.first = max(p1.first, p1.second) + max(p2.first, p2.second);
    p3.second = max(p1.second, p2.second) + 1;
    return p3;
}

int findDiameter(BinaryTreeNode<int>*root){
    pair<int, int> p = findDiameterStep(root);
    return p.first;
}

pair<int, int> minMax(BinaryTreeNode<int>*root){
    if(root == NULL){
        pair<int, int>p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int, int> p1 = minMax(root -> left);
    pair<int, int> p2 = minMax(root -> right);
    pair<int, int> p3;
    p3.first = min(min(p1.first, p2.first), root -> data);
    p3.second = max(max(p1.second, p2.second), root -> data);
    return p3;
}

int sumOfNodes(BinaryTreeNode<int>*root){
    if(root == NULL){
        return 0;
    }
    int sum = root -> data;
    sum += sumOfNodes(root -> left);
    sum += sumOfNodes(root -> right);
    return sum;
}

pair<bool, int> isBalancedStep(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<bool, int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool, int> p1 = isBalancedStep(root -> left);
    pair<bool, int> p2 = isBalancedStep(root -> right);
    if(!p1.first || !p2.first){
        pair<bool, int> p3;
        p3.first = false;
        return p3;
    }
    if(max(p1.second, p2.second) - min(p1.second, p2.second) > 1){
        pair<bool, int> p3;
        p3.first = false;
        return p3;
    }
    pair<bool, int> p3;
    p3.first = true;
    p3.second = max(p1.second, p2.second) + 1;
    return p3;
}

bool isBalanced(BinaryTreeNode<int>* root){
    return isBalancedStep(root).first;
}

void levelOrderTraversal(BinaryTreeNode<int>*root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>* que = new queue<BinaryTreeNode<int>*>();
    que->push(root);
    que->push(new BinaryTreeNode<int>(-1));
    while(!que -> empty()){
        BinaryTreeNode<int>* currNode = que -> front();
        que -> pop();
        if(currNode -> data == -1){
            if(que -> empty()){
                continue;
            }
            que -> push(currNode);
            cout << endl;
        }
        else{
            cout << currNode -> data << " ";
            if(currNode -> left != NULL){
                que -> push(currNode -> left);
            }
            if(currNode -> right != NULL){
                que -> push(currNode -> right);
            }
        }
    }
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*>arr;
    if(root == NULL){
        return arr;
    }
    queue<BinaryTreeNode<int>*>*que = new queue<BinaryTreeNode<int>*>();
    que->push(root);
    que->push(new BinaryTreeNode<int>(-1));
    Node<int>* head = NULL;
    Node<int>* prev = NULL;
    while(!que -> empty()){
        BinaryTreeNode<int>*currNode = que->front();
        que->pop();
        if(currNode -> data == -1){
            if(que->empty()){
                break;
            }
            que->push(currNode);
            head = NULL;
            prev = NULL;
        }
        else{
        	Node<int>* curr = new Node<int>(currNode -> data);
        	if(head == NULL){
        	    head = curr;
        	    prev = curr;
        	    arr.push_back(head);
        	}
        	else{
        	    prev -> next = curr;
        	    prev = curr;
        	}
        	if(currNode -> left != NULL){
        	    que->push(currNode->left);
        	}
        	if(currNode -> right != NULL){
        	    que->push(currNode->right);
        	}
        }
    }
    return arr;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int>*> * s1 = new stack<BinaryTreeNode<int>*>();
    stack<BinaryTreeNode<int>*> * s2 = new stack<BinaryTreeNode<int>*>();
    s1 -> push(root);
    int i = 1;
    while(!s1 -> empty() || !s2 -> empty()){
        if(i % 2 != 0){
            BinaryTreeNode<int>* currNode = s1 -> top();
            s1 -> pop();
            cout << currNode -> data << " ";
            if(currNode -> left != NULL){
                s2 -> push(currNode -> left);
            }
            if(currNode -> right != NULL){
                s2 -> push(currNode -> right);
            }
            if(s1 -> empty()){
                cout << endl;
                i++;
            }
        }
        else{
            BinaryTreeNode<int>* currNode = s2 -> top();
            s2 -> pop();
            cout << currNode -> data << " ";
            if(currNode -> right != NULL){
                s1 -> push(currNode -> right);
            }
            if(currNode -> left != NULL){
                s1 -> push(currNode -> left);
            }
            if(s2 -> empty()){
                cout << endl;
                i++;
            }
        }
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput<int>();
    printLevelWise(root);
    cout << endl;
    levelOrderTraversal(root);
}