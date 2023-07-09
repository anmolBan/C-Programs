#include<iostream>
#include"BinaryTreeNode.h"
using namespace std;

class BSTClass{
    public:
    BinaryTreeNode<int>*root;

    BSTClass(){
        root = NULL;
    }
    ~BSTClass(){
        delete root;
    }

    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int>* root, int data){
        if(root == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(root -> data < data){
            root -> left = insertHelper(root -> left, data);
            return root;
        }

        if(root -> data > data){
            root -> right = insertHelper(root -> right, data);
            return root;
        }
    }

    void insert(BinaryTreeNode<int>* root, int data){
        insertHelper(root, data);
    }

    BinaryTreeNode<int>* deleteHelper(BinaryTreeNode<int>* root, int data){
        
    }

    void delete(BinaryTreeNode<int>* root, int data){
        deleteHelper(root, data);
    }
};