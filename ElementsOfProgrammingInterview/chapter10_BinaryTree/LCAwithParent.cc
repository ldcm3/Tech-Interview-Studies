/*
    Compute Lowest Commom Ancestor when nodes have parent pointers

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

int getDepth(TreeNode* node)
{
    int depth = 0;
    
    while(node->parent)
    {
        depth++;
        node = node->parent;
    }
    
    return depth;
    
}

TreeNode* LCA(TreeNode* root, TreeNode* a, TreeNode* b)
{
    if(!root || !a || !b)
        return nullptr;
        
    int depth1 = getDepth(a);
    int depth2 = getDepth(b);
    
    if (depth2 < depth1)
        swap(a,b);
    
    
    int diff = abs(depth1 - depth2);
    
    while(--diff)
    {
        a = a->parent;
    }
    
    while(a != b)
    {
        a = a->parent;
        b = b->parent;
    
    }
    
    return a;
}

int main()
{
    return 0;
}