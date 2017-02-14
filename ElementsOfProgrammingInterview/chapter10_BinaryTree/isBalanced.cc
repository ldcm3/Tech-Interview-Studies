/*
    A balanced Binary Tree is a tree where the difference between the height
    of its left and right subtrees are at most one.

    Solution Complexity:
    
    Space - O(h);
    Time - O(n);
*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    
    TreeNode(int v): val(v),left(nullptr),right(nullptr){}
};

int checkBalance(TreeNode* root)
{
    if (!root)
        return 0;
    
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);

    if(left == -1 || right == -1 || 
    abs(left-right) > 1)
        return -1;
       
    return max(left,right) + 1;
}

bool isBalanced(TreeNode* root)
{
    return checkBalance(root) != -1 ? true : false;
    
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right =  new TreeNode(3);
    root->left->left =  new TreeNode(4);
   // root->left->left->left =  new TreeNode(5);
    
    cout << isBalanced(root) << endl;
    
    return 0;
}