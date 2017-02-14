/*
    Consider a Binary Tree where each node contains a bit (1 or 0).
    A root-to-leaf path can be associated with a binary number - the MSB is at 
    root.
    
    Compute the sum of the binary numbers represented by the root-to-leaf paths

*/

#include<iostream>

using namespace std;

int helper(TreeNode* root, int currSum)
{
    if(!root)
        return 0;
    
    currSum = (currSum << 1) & root->val;
    
    if (!root->left && !root->right) // leaf
        return currSum;
    else
        return helper(root->left,currSum) + 
                helper(root->right,currSum);
}

int sumRootToLeaf(TreeNode* root)
{
    int sum = 0;
    return helper(root,sum);
}

int main()
{
    return 0;
}