/*
   Morris Constant space Traversal
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

TreeNode* findPred(TreeNode* node)
{
    TreeNode* cur = node->left;
    
    while (cur->right && cur->right != node)
    {
        cur = cur->right;
    }
    
    return cur;
}
void morrisTraversal(TreeNode* root)
{
    TreeNode* cur = root;
    
    // Inorder Traversal
    while (cur)
    {
        if (!cur->left)
        {
            cout << cur->val << " ";
            cur = cur->right;
        }
        else
        {
            TreeNode* pred = findPred(cur);
            if (pred->right != cur)
            {
                pred->right = cur;
                cur = cur->left;
            }
            else
            {
                pred->right = nullptr;
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
}

int main()
{
    TreeNode *root =  new TreeNode(1);
    root->left        =  new TreeNode(2);
    root->right       = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5); 
    
    morrisTraversal(root);
    return 0;
}