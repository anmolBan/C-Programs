#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
#include <bits/stdc++.h>
#include"Node.h"
#include<vector>
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
bool searchInBST(BinaryTreeNode<T> * root, T x){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == x){
        return true;
    }

    if(root -> data < x){
        return searchInBST(root -> right, x);
    }
    
    return searchInBST(root -> left, x);
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root == NULL){
        return;
    }
    if(k2 < root -> data){
        elementsInRangeK1K2(root -> left, k1, k2);
        
    }
    else if(k1 > root -> data){
        elementsInRangeK1K2(root -> right, k1, k2);
        
    }
    else if(root -> data >= k1 && root -> data <= k2){
        elementsInRangeK1K2(root -> left, k1, k2);
        cout << root -> data << " ";
        elementsInRangeK1K2(root -> right, k1, k2);
    }
}

pair<bool, pair<int, int>> isBSTStep(BinaryTreeNode<int>* root){
	if(root == NULL){
		bool boolean = true;
		int min = INT_MAX;
		int max = INT_MIN;
		pair<int,int> p1;
		p1.first = min;
		p1.second = max;

		pair <bool, pair<int,int>> p2;
		p2.first = boolean;
		p2.second = p1;
		return p2;
	}

	pair<bool, pair<int, int>> p1 = isBSTStep(root -> left);
	pair<bool, pair<int, int>> p2 = isBSTStep(root -> right);
	
	int minimum = min(root -> data, min(p1.second.first, p2.second.first));
	int maximum = max(root -> data, max(p1.second.second, p2.second.second));
	bool isBSTFinal = (root -> data > p1.second.second) && (root -> data < p2.second.first) && (p1.first) && (p2.first);

	pair<int, int> p3;
	p3.first = minimum;
	p3.second = maximum;
	
	pair<bool, pair<int,int>> p4;
	p4.first = isBSTFinal;
	p4.second = p3;
	return p4;
}

bool isBST(BinaryTreeNode<int> *root) {
	pair< bool, pair<int, int>> p = isBSTStep(root);
	return p.first;
}

bool isBST2(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root -> data <= min || root -> data > max){
        return false;
    }

    bool ans = isBST2(root -> left, min, root -> data - 1);
    if(!ans){
        return false;
    }
    return isBST2(root -> right, root -> data, max);
}

BinaryTreeNode<int>*constructTreeStep(int * input, int start, int end){
	if(start > end){
		return NULL;
	}

	int mid = (start + end)/2;
	int rootData =  input[mid];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> * rootLeft = constructTreeStep(input, start, mid - 1);
	BinaryTreeNode<int> * rootRight =  constructTreeStep(input, mid + 1, end);
	root -> left = rootLeft;
	root -> right = rootRight;
	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTreeStep(input, 0, n - 1);
}

pair<Node<int>*, Node<int>*> constructLinkedListStep(BinaryTreeNode<int>* root, Node<int>* head, Node<int>*prev){

	if(root == NULL){
		pair<Node<int>*, Node<int>*> p;
		p.first = head;
		p.second = prev;
		return p;
	}

	pair<Node<int>*, Node<int>*> p1 = constructLinkedListStep(root -> left, head, prev);

	if(p1.first == NULL){
		Node<int> * currNode = new Node<int>(root -> data);
		p1.first = currNode;
		p1.second = currNode;
	}
	else{
		Node<int> * currNode = new Node<int>(root -> data);
		p1.second -> next = currNode;
		p1.second = p1.second -> next;
	}
	
	return constructLinkedListStep(root -> right, p1.first, p1.second);

}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedListStep(root, NULL, NULL).first;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	
	if(root == NULL){
		return new vector<int>();
	}

	if(root -> data == data){
		vector<int> * arr = new vector<int>();
		arr -> push_back(root -> data);
		return arr;
	}

	if(root -> data > data){
		vector<int>* arr = getPath(root -> left, data);
		if(!arr -> empty()){
			arr -> push_back(root -> data);
		}
		return arr;
	}

	else if(root -> data < data){
		vector<int>* arr = getPath(root -> right, data);
		if(!arr -> empty()){
			arr -> push_back(root -> data);
		}
		return arr;
	}
}

int main(){
    BinaryTreeNode<int>* root = takeInput<int>();
    printLevelWise(root);
    cout << searchInBST<int>(root, 5) << endl;
}