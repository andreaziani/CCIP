/*
    Create a binary search tree from a sorted array.
*/
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public: int val;
    public: Node* right;
    public: Node* left;
    public: Node* parent;

    public: Node() {}
    public: Node(int val){
        this->val = val;
    }
};

// Binary search
Node* minimalTree(int array[], int start, int end){
    if(end < start) return NULL;
    
    int m = (end + start) / 2;
    Node* root = new Node(array[m]);
    
    root->left = minimalTree(array, start, m - 1);
    root->right = minimalTree(array, m + 1, end);
    return root;
}

void printTree(Node* root){
    if(root == NULL) return;
    Node* tmp = root;
    queue<Node*> q;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        cout << tmp->val << " ";
        q.pop();
        if(tmp->left != NULL) q.push(tmp->left);
        if(tmp->right != NULL) q.push(tmp->right);
    }

}

int main(){ 
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    Node* root = minimalTree(array, 0, 6);
    printTree(root);
    return 0; 
}