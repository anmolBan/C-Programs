#include<iostream>
#include"TreeNode.h"
#include<queue>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void postOrderTraversal(TreeNode<T> * root){
    for(int i = 0; i < root -> children.size(); i++){
        postOrderTraversal(root -> children[i]);
    }
    cout << root -> data << " ";
    return;
}

template<typename T>
int countLeafNodes(TreeNode<T> * root){
    int leafNodeCount = 0;
    for(int i = 0; i < root -> children.size(); i++){
        if(root -> children[i] -> children.size() == 0){
            leafNodeCount++;
        }
        else{
            leafNodeCount += countLeafNodes(root -> children[i]);
        }
    }
    return leafNodeCount;
}

int largestNode(TreeNode<int> * root){
    int largest = root -> data;
    for(int i = 0; i < root -> children.size(); i++){
        largest = max(largest, largestNode(root -> children[i]));
    }
    return largest;
}

template<typename T>
int depthOfTree(TreeNode<T> * root, int d = 0){
    int depth = 0;
    for(int i = 0; i < root -> children.size(); i++){
        int currDepth = depthOfTree(root -> children[i], d + 1);
        depth = max(depth, currDepth);
    }
    if(d == 0){
        return depth;
    }
    else{
        return depth + 1;
    }
}

template<typename T>
int heightOfTree(TreeNode<T> * root){
    int height = 0;
    for(int i = 0; i < root -> children.size(); i++){
        int currHeight = heightOfTree(root -> children[i]);
        height = max(height, currHeight);
    }
    return height + 1;
}

template<typename T>
int sumOfNodes(TreeNode<T> * root){
    int sum = 0;
    for(int i = 0; i < root -> children.size(); i++){
        sum += sumOfNodes(root -> children[i]);
    }
    sum += root -> data;
    return sum;
}

template<typename T>
int countNodes(TreeNode<T> * root){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    for(int i = 0; i < root -> children.size(); i++){
        count += countNodes(root -> children[i]);
    }
    return count + 1;
}

template<typename T>
void printTreeLevelWise(TreeNode<T> * root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<T>*> * que = new queue<TreeNode<T>*>();
    que -> push(root);
    while(!que -> empty()){
        TreeNode<T> * currNode = que -> front();
        que -> pop();
        cout << currNode -> data << ": ";
        for(int i = 0; i < currNode -> children.size(); i++){
            cout << currNode -> children[i] -> data << ", ";
            que -> push(currNode -> children[i]);
        }
        cout << endl;
    }
}

template<typename T>
TreeNode<T> * takeInputLevelWise(){
    cout << "Enter the value of Root Node" << endl;
    T rootData;
    cin >> rootData;
    TreeNode<T> * root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> * que =  new queue<TreeNode<T>*>();
    que -> push(root);
    while(!que -> empty()){
        TreeNode<T> * currNode = que -> front();
        que -> pop();
        cout << "Enter the number of children of Node: " << currNode -> data << endl;
        int children;
        cin >> children;
        for(int i = 0; i < children; i++){
            T currData;
            cin >> currData;
            TreeNode<T> * newNode = new TreeNode<T>(currData);
            newNode -> data = currData;
            currNode -> children.push_back(newNode);
            que -> push(newNode);
        }
    }
    return root;
}

template<typename T>
TreeNode<T> * takeInput(int i = 0){
    if(i == 0){
        cout << "Enter the value of Root Node" << endl;
    }
    else{
        cout << "Enter the value of Node" << endl;
    }
    T rootData;
    cin >> rootData;
    TreeNode<T> * root = new TreeNode<T>(rootData);
    root -> data = rootData;
    cout << "Enter the number of children of Node: " << rootData << endl;
    int children;
    cin >> children;
    for(int i = 0; i < children; i++){
        root -> children.push_back(takeInput<T>(i + 1));
    }
    return root;
}

template<typename T>
void printTree(TreeNode<T> * root){
    cout << root -> data << ": ";

    for(int i = 0; i < root -> children.size(); i++){
        if(i == root -> children.size() -1){
            cout << root -> children[i] -> data;
        }
        else{
            cout << root -> children[i] -> data << ", ";
        }
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++){
        printTree(root-> children[i]);
    }
}

template<typename T>
bool isPresent(TreeNode<T>*root, T x){
    if(x == root -> data){
        return true;
    }
    for(int i = 0; i < root -> children.size(); i++){
        bool flag = isPresent(root -> children[i], x);
        if(flag){
            return true;
        }
    }
    return false;
}

pair<TreeNode<int>*, int> p1;
pair<TreeNode<int>*, int> maxSumNode(TreeNode<int>* root){
    int thisNodeSum = root -> data;
    pair<TreeNode<int>*, int> p2(NULL, INT_MIN);
    for(int i = 0; i < root -> children.size(); i++){
        thisNodeSum += root -> children[i] -> data;
        pair<TreeNode<int>*, int> p3 = maxSumNode(root -> children[i]);
        if(p3.second > p2.second){
            p2.first = p3.first;
            p2.second = p3.second;
        }
    }
    if(thisNodeSum > p2.second){
        p2.first = root;
        p2.second = thisNodeSum;
    }
    return p2;
}

template<typename T>
bool areIdentical(TreeNode<T>* root1, TreeNode<T>* root2){
    if(root1 -> children.size() != root2 -> children.size()){
        return false;
    }

    for(int i = 0; i < root1 -> children.size(); i++){
        bool flag = areIdentical(root1 -> children[i], root2 -> children[i]);
        if(!flag){
            return false;
        }
    }
    return true;
}

TreeNode<int>* nextLarger(TreeNode<int>* root, int n){
    TreeNode<int>* larger = new TreeNode<int>(INT_MAX);
    for(int i = 0; i < root -> children.size(); i++){
        TreeNode<int>* curr = nextLarger(root -> children[i], n);
        if(curr -> data > n && curr -> data < larger -> data){
            larger = curr;
        }
    }
    if(root -> data > n && root -> data < larger -> data){
        larger = root;
    }
    return larger;
}

pair<TreeNode<int>*, TreeNode<int>*> secondLargestStep(TreeNode<int>*root){
    TreeNode<int>*largest = new TreeNode<int>(INT_MIN);
    TreeNode<int>* secondLargest = new TreeNode<int>(INT_MIN);
    for(int i = 0; i < root -> children.size(); i++){
        pair<TreeNode<int>*, TreeNode<int>*> p = secondLargestStep(root -> children[i]);
        if(p.first -> data > largest -> data){
            secondLargest = largest;
            largest = p.first;
            if(p.second -> data > secondLargest -> data){
                secondLargest = p.second;
            }
        }
        else if(p.first -> data > secondLargest -> data){
            secondLargest = p.first;
        }
    }
    if(root -> data > largest -> data){
        secondLargest = largest;
        largest = root;
    }
    else if(root -> data > secondLargest -> data && root -> data != largest -> data){
        secondLargest = root;
    }
    pair<TreeNode<int>*, TreeNode<int>*> p2;
    p2.first = largest;
    p2.second = secondLargest;
    return p2;
}

TreeNode<int> * secondLargest(TreeNode<int> * root){
    pair<TreeNode<int>*, TreeNode<int>*> p = secondLargestStep(root);
}

void replaceWithDepthValue(TreeNode<int>*root, int depth = 0){
    root -> data = depth;
    for(int i = 0; i < root -> children.size(); i++){
        replaceWithDepthValue(root -> children[i], depth + 1);
    }
    return;

}

int main(){
    TreeNode<int> * root1 = takeInputLevelWise<int>();
    printTreeLevelWise<int>(root1);
    cout << endl;
    replaceWithDepthValue(root1);
    printTreeLevelWise(root1);
}