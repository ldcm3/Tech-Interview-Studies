/*
    LCA - Find the Lowest Commom Ancestor in a Binary Tree

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
 
TreeNode* findLCA(TreeNode* root, int  a, int b)
{
    if(!root)
        return nullptr;
    
    if (root->val == a || root->val == b)
        return root;
    
    TreeNode* left = findLCA(root->left,a,b);
    TreeNode* right = findLCA(root->right,a,b);
    
    // if both are found, then one key is present in once subtree and other 
    // is present in the another
    // so this is the LCA
    if (left && right) 
        return root;
        
    return left != nullptr ? left : right;
}
 
int main()
{
     // Let us create binary tree given in the above example
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    TreeNode* ans =  (findLCA(root,2,4));
    cout << ans->val << endl;
    return 0;
}