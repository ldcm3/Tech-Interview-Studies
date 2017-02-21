#include<iostream>

using namespace std;

struct TreeNode{
    TreeNode *left,*right,*parent;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr),parent(nullptr) {}
};


TreeNode* findPredecessor(TreeNode* node)
{
    TreeNode* cur = node->left;
    
    while(cur->right && cur->right != node)
        cur = cur->right;
    
    return cur;
}

void morrisInorder(TreeNode* root)
{
    TreeNode* cur = root;
    
    while(cur)
    {
        if (!cur->left)
        {
            cout << cur->val << " ";
            cur = cur->right;
        }
        else
        {
            TreeNode* pred = findPredecessor(cur);
            
            if (pred->right) // has been already visited
            {
                pred->right = nullptr;
                cout << cur->val << " ";

                cur = cur->right;
            }
            else
            {
                pred->right = cur;
                cur = cur->left;
            }
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
    
    morrisInorder(root);
    cout << endl;
    return 0;
}