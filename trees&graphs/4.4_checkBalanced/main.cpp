/* 
    Implement a function to check if a binary tree is balanced 
*/
#include <stdlib.h>
#include <iostream>
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

/* Search line by line if there is a leaf and update the leaf minHeight and maxHeight. 
    If maxHeight - minHeight > 1 the tree is unbalanced */
bool checkHeight(TreeNode* root){
    if(root == NULL) return true;
    queue<TreeNode*> q;
    q.push(root);
    int n = 1;
    int height = 1;
    int minHeight = INT_MAX;
    int maxHeight = 1;
    while(!q.empty()){
        for(int i = 0; i < n; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            if(curr->left == NULL && curr->right == NULL){ // if the node is a leaf
                minHeight = height < minHeight? height : minHeight; //update minHeight & maxHeight
                maxHeight = height > maxHeight? height : maxHeight;
            }
        }
        height++;
        n = q.size();
    }

    return (maxHeight - minHeight < 2);
}

bool isBalanced(TreeNode* root){
    return checkHeight(root);
}

int main(){ 
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    TreeNode* left = root->left;
    left->left = new TreeNode(7);
    left->right = new TreeNode(8);
    left->left->left = new TreeNode(9);

    cout << isBalanced(root) << endl; //unbalanced

    TreeNode* right = root->right;
    right->left = new TreeNode(7);
    right->right = new TreeNode(7);

    cout << isBalanced(root) << endl; // balanced
    return 0; 
}