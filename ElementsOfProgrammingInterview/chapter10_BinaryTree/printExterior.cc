/*
    Write a program that computes the exterior of a binary tree

*/

#include<iostream>
#include<vector>

using namespace std;


struct TreeNode{
    TreeNode *left,*right,*parent;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr),parent(nullptr) {}
};

bool isLeaf(TreeNode* node)
{
    return !node->left && !node->right;
}

void printLeftBoundaryAndLeaves(TreeNode* root, bool isBoundary)
{
    if(!root)
        return;
        
    if(isBoundary || isLeaf(root))
        cout << root->val << " ";
    
    printLeftBoundaryAndLeaves(root->left, isBoundary);
    printLeftBoundaryAndLeaves(root->right, isBoundary && !root->left);
}

void printRightBoundaryAndLeaves(TreeNode* root, bool isBoundary)
{
    if(!root)
        return;
    
    printRightBoundaryAndLeaves(root->left, isBoundary && !root->right);
    printRightBoundaryAndLeaves(root->right, isBoundary);
    
    if(isBoundary || isLeaf)
        cout << root->val << " ";
}


void printBoundary(TreeNode* root)
{
    cout << root->val << " ";
    printLeftBoundaryAndLeaves(root->left,true);
    printRightBoundaryAndLeaves(root->right, true);
}

int main()
{

     TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    printBoundary(root);
    return 0;
}