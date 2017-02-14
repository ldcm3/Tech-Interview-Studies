/*
    Check if there exist a path root-to-leaf that sum is equal required

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


bool checkPath(TreeNode* root, int sum)
{
    if(!root)
        return false;
    
    if(!root->left && !root->right)
        return sum - root->val == 0;
    else
        return checkPath(root->left,sum - root->val) ||
                checkPath(root->right,sum - root->val);
}

int main()
{
    return 0;
}