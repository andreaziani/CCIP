/*
    Given a binary tree design an algorithm which creates a linked list of all the nodes at each depth
*/
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class TreeNode{
    public: int val;
    public: TreeNode* right;
    public: TreeNode* left;

    public: TreeNode() {}
    public: TreeNode(int val){
        this->val = val;
        right = NULL;
        left = NULL;
    }
};

// Modified BFS
vector<list<TreeNode*> > listOfDepth(TreeNode* root){
    vector<list<TreeNode*> > listsOfDepth;
    queue<TreeNode*> q;
    q.push(root);
    int n = 1; // elements in queue
    while(!q.empty()){
        list<TreeNode*> list;
        for(int i = 0; i < n; i++){ // a row of the tree
            TreeNode* curr = q.front(); q.pop();
            cout << curr->val << " ";
            list.push_back(curr);
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
        cout << endl;
        listsOfDepth.push_back(list);
        n = q.size();
    }
    return listsOfDepth;
}

// Modified DFS
void createLevelLinkedList(TreeNode* root,  vector<list<TreeNode*> > lists, int level){
    if(root == NULL) return;
    
    list<TreeNode*> l;
    if(l.size() == level){
        lists.push_back(l);
    } else{
        l = lists[level];
    }
    l.push_back(root);

    createLevelLinkedList(root->left, lists, level + 1);
    createLevelLinkedList(root->right, lists, level + 1);
}

// use a modified DFS
vector<list<TreeNode*> > listOfDepth_DFS(TreeNode* root){
    vector<list<TreeNode*> > lists;
    createLevelLinkedList(root, lists, 0);
    return lists;
}

int main(){ 
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    TreeNode* tmp = root;
    tmp = tmp->left;
    tmp->left = new TreeNode(4);
    tmp->right = new TreeNode(0);

    listOfDepth(root);
    return 0;     
}