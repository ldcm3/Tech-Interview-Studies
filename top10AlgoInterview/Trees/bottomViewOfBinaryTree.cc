/*
    Print the bottom view from left to right.
    A node x is there in output if x is the bottommost node at its horizontal distance. 
    Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1,
    and that of right child is horizontal distance of x plus 1.
    
                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14
                  
    Output :  5, 10, 3, 14, 25.
    
                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10    14 
                  
    Output : 5, 10, 4, 14, 25.

*/

#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

struct TreeNode
{
    TreeNode *left,*right;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),right(nullptr) {}
};

struct NodeAndLevel
{
    TreeNode* node;
    int level;
    
    NodeAndLevel(TreeNode* n,int l): node(n), level(l) {}
};

void printBottomView(TreeNode* root)
{
    if(!root)
        return;
    
    map<int,int> verticalLevel;
    
    // Preorder Traversal
    
    // Basically a BFS
    queue<NodeAndLevel*> q;
    q.push(new NodeAndLevel(root,0));
    
    while(!q.empty())
    {
        TreeNode*cur = q.front()->node;
        int level = q.front()->level;
        q.pop();
        
        verticalLevel[level] = cur->val;
        
        if(cur->left)
            q.push(new NodeAndLevel(cur->left,level - 1));
        
        if(cur->right)
            q.push(new NodeAndLevel(cur->right,level + 1));
            
    }
    
    
    for(auto node : verticalLevel)
        cout << node.second << " ";
    
    cout << endl;
    
    
}

int main()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;
}