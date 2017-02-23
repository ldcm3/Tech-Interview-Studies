/*
    Tqkes a perfect binary tree and set eachs other next node
*/

#include<iostream>
#include<vector>

using namespace std;


struct TreeNode{
    TreeNode *left,*right,*next;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr),parent(nullptr) {}
};

void buildRightNode(TreeNode* root)
{
    if(!root)
        return;
    
    if(root->left) // perfect binary tree has pair of children
        root->left-next = root->right;
    
    if(root->next)
        root->right->next = root->next->left;
        
    buildRightNode(root->left);
    buildRightNode(root->right);
    
}

int main()
{
    return 0;
}