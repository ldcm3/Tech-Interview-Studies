/*

    Find Successor in a Binary Tree where nodes contains parent pointer
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

TreeNode* findSuccessor(TreeNode* node)
{
     TreeNode* cur;
    if (node->right) // Successor is leftMost node in right subtree
    {
        cur = node->right;
        while(cur->left)
            cur = cur->left;
            
        return cur;
    }
    else 
    {
        // Case 1)  node is a left child of its parent
            // Parent is successor
        // Case 2) node is a right child of its parent
            // Parent has been already visited, so successor is first left parent
        cur = node;
        while(cur->parent && cur->parent->left != cur)
            cur = cur->parent;
        
    }
    
    return cur->parent;
    
}
int main()
{
    return 0;
}