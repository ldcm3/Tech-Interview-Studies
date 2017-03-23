/*
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
    
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    
*/

#include<iostream>
#include<vector>

struct TreeNode
{
    TreeNode *right,*left;
    int val;
    
    TreeNode(int v): right(nullptr),left(nullptr),val(v)
    {}
};

bool helper(TreeNode* a, TreeNode* b)
{
    if (!a && !b)
        return true;
    
    if (!a || !b || a->val != b->val)
        return false;
    
    return helper(a->left,b->right) &&
            helper(a->right, b->left);
}

int isSymmetric(TreeNode* A) {
      
     
    return A == nullptr || helper(A->left,A->right);
}

int main()
{
    return 0;
}