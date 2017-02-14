/*  
    Morris Inorder Traversal
    
    It is an Binary Tree inorder traversal stackless.
    
    Complexity:
        
        O(1) space
        O(n) time
*/

#include<iostream>
#include<vector>

using namespace std;

struct BSTNode{
    int val;
    BSTNode *left;
    BSTNode *right;
    
    BSTNode(): left(nullptr), right(nullptr) {}
    
    BSTNode(int v): val(v),left(nullptr), right(nullptr) {}
};

void visit(BSTNode* node)
{
    cout << node->val <<  " ";
}

BSTNode* findPredecessor(BSTNode* root)
{
    BSTNode* cur = root->left;
    
    while(cur->right && cur->right != root)
    {
        cur = cur->right;
    }
    
    return cur;
}

void morrisInorder(BSTNode* root)
{
    BSTNode* cur = root;
    BSTNode* predecessor = nullptr;
    
    while(cur)
    {
        if (!cur->left)
        {
            visit(cur);
            cur = cur->right;
        }
        else
        {
            predecessor = findPredecessor(cur);
            
            if (!predecessor->right)
            {
                predecessor->right = cur; // set recursive link 
                cur = cur->left;
            }
            else    // predecessor has already been visited
            {
                predecessor->right = nullptr; // restore node
                visit(cur);
                cur = cur->right;
            }
        }
    }
}



int main()
{
    BSTNode *root = new BSTNode(10);
    root->left        = new BSTNode(5);
    root->right       = new BSTNode(6);
    root->left->left  = new BSTNode(-2);
    root->left->right = new BSTNode(6); 
 
    morrisInorder(root);
    return 0;
}