#include <stdlib.h>
#include <iostream>
#include <vector>
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

// 1) 
void copyBST(TreeNode* root, vector<int> &array){
    if(root == NULL) return;
    copyBST(root->left, array);
    //cout << root->val << " ";
    array.push_back(root->val);
    copyBST(root->right, array);
}
// copy the bst in an array and see if it's sorted
bool validateBST_array(TreeNode* root){
    vector<int> array;
    int index = 0;
    copyBST(root, array);
    for(int i = 1; i < array.size(); i++){
        //cout << array[i] << " ";
        if(array[i] <= array[i - 1]) return false;
    }
    return true;
}

// 2)
// The array is actually not necessary, we just need to compare the current element with the last printed 
bool validateBST_inOrder(TreeNode* root, int &lastPrinted){
    if(root == NULL) return true;
    
    if(!validateBST_inOrder(root->left, lastPrinted)) return false; // recurse left

    if(lastPrinted != INT_MIN && root->val <= lastPrinted) return false; // check current
    
    lastPrinted = root->val; // update current

    if(!validateBST_inOrder(root->right, lastPrinted)) return false; // recurse right

    return true;
}

// 3)
bool checkBST(TreeNode* root, int min, int max){
    if(root == NULL) return true;

    if((min != NULL && root->val <= min) || (max != NULL && root->val > max)) return false;

    if(!checkBST(root->left, min, root->val) || !checkBST(root->right, root->val, max)) return false;

    return true;
}

bool validateBST(TreeNode* root){
    return checkBST(root, NULL, NULL);
}



int main(){ 
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    TreeNode* left = root->left;
    left->left = new TreeNode(5);
    left->right = new TreeNode(15); 
    int lastprinted = INT_MIN;
    cout << validateBST_inOrder(root, lastprinted) << endl;
    cout << validateBST_array(root) << endl; // true
    cout << validateBST(root) << endl;
    left->right = new TreeNode(7);
    lastprinted = INT_MIN;
    cout << validateBST_array(root) << endl; // false
    cout << validateBST_inOrder(root, lastprinted) << endl;
    cout << validateBST(root) << endl;
    return 0; 
}