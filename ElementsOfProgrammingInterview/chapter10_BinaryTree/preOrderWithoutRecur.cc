/*
    Implement an Preorder Traversal without recursion

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    TreeNode *left,*right,*parent;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr),parent(nullptr) {}
};

void preOrder(TreeNode* root)
{
    if(!root)
        return;
        
    stack<TreeNode*> s;
    
    TreeNode* cur = root;
    
    
    while(cur || !s.empty())
    {
        if(cur)
        {
            cout << cur->val << " ";
            s.emplace(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
    
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
    
    preOrder(root);
    return 0;
}