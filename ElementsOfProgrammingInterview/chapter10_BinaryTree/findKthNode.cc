/*
    Find the Kth node in a Inorder Traversal of a Binary Tree.
    
    Assume that each node stores the number of nodes in the subtree rooted at 
    that node
    
    Solution Complexity
    O(h)

*/

#include<iostream>

using namespace std;

TreeNode* findKthNode(TreeNode* root, int k )
{
    if (!root)
        return nullptr;
    else if(k == 1)
        return root;
    
    // if num of nodes in left Subtree is lesser than k - 1 (include root)
    // kth is in the right subtree
    if(root->left && root->left->numOfNodes < k - 1)
        return findKthNode(root->right,k - root->left->numOfNodes - 1);
    // kth is in the left subtree
    else
        return findKthNode(root->left,k - 1);
        
int main()
{
    return 0;
}