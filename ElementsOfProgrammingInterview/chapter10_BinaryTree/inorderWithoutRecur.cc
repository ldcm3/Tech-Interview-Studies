/*
    Implement an Inorder Traversal without recursion

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

TreeNode* findPred(TreeNode* root)
{

    if(!root)
        return nullptr;
    
    TreeNode* cur = root->left;
    
    while(cur->right && cur->right != root)
    {
        cur = cur->right;
    }
    
    return cur;
}

void inorder(TreeNode* root)
{
    if (!root)
        return ;
        
    TreeNode* cur = root;
    
    // Morris Traversal
    
    while(cur)
    {
        if(cur->left)
        {
            TreeNode* predecessor = findPred(cur);
            
            if (!predecessor->right) // if there is no cycle
            {
                predecessor->right = cur; // make cur the next node
                cur = cur->left;
            }
            else // predecessor has been already visited
            {
                predecessor->right = nullptr; // delete tmp link
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
        else // there is no left node
        {
            cout << cur->val << " ";
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
    
    inorder(root);
    return 0;
}