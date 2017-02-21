/*
    Given a preOrder Traversal with markers to null children, 
    reconstruct the binary tree.
    
    [1,2,4,null,null,5,null,null,3,6,null,null,7,null,null]

*/

#include<iostream>
#include<vector>
#include<stack>


using namespace std;

struct TreeNode{
    TreeNode *left,*right;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr){}
};

TreeNode* deserialize(const vector<int>& preOrder, int& idx)
{
    if(preOrder[idx] == -1 || idx > preOrder.size()) // null
        return nullptr;
    
    TreeNode* node = new TreeNode(preOrder[idx]);
    
    node->left = deserialize(preOrder, ++idx);
    node->right = deserialize(preOrder,++idx);
   
   
   return node;
}


void preOrderTrav(TreeNode* root)
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
    vector<int> preOrder {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    int idx = 0;
    TreeNode* root = deserialize(preOrder,idx);   
    
    preOrderTrav(root);
    return 0;
}