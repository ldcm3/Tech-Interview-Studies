/*
    A binary tree is symmetric if you can drawn a vertical line through the root
    and then the left subtree is the mirror of the right subtree.
    
                314
                / \
               6   6
              /     \
             2       2
              \     /
               3   3

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
 
bool helper(TreeNode* a, TreeNode* b)
{
    if (!a && !b)
        return true;
    
    else if(a && b)
    {
        return a->val == b->val &&
        isSymmetric(a->left,b->right) &&
        isSymmetric(a->right, b->left);
    }
    
    // one subtree is empty, and the other is not
    return false;
}

bool isSymmetric(TreeNode* root)
{
    if (!root)
        return true;
    
    else if(root->right && root->left )
        return root->right->val == root->left->val &&
                isSymmetric(root->left) && isSymmetric(root->right);
    
}


int main()
{
    
    return 0;
}