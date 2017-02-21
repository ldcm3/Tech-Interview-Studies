#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode{
    TreeNode *left,*right;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),right(nullptr) {}
};

TreeNode* reconstruct(const vector<int>& inorder, const vector<int>& preOrder,
                        int startP, int endP, int startI, int endI,
                        const unordered_map<int, int>& node_to_inorder)
{
    // condition to stop recursion 
    if (startP > endP || startI > endI )                                          
        return nullptr;                                     
                                                                
    TreeNode* curNode = new TreeNode(preOrder[startP]);            
    
    int nodeIdx = node_to_inorder.find(preOrder[startP])->second;
    
    int nodesLeftSubtree =  nodeIdx -  startI;
    
    curNode->left = reconstruct(inorder, preOrder, startP + 1,endP,
                            startI, nodeIdx - 1, node_to_inorder);
    
    curNode->right = reconstruct(inorder,preOrder,startP + nodesLeftSubtree + 1,endP,
                                nodeIdx + 1, endI, node_to_inorder);
                                
    
    return curNode;
    

}

/*

    PRINT FUNCTIONS    

*/

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

void inorderTrav(TreeNode* root)
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
    vector<int> inorder {6,2,1,5,8,3,4,9,7};
    vector<int> preOrder {8,2,6,5,1,3,4,7,9};
    
    unordered_map<int,int> node_to_inorder;
    for(int i = 0 ;i < inorder.size(); ++i)
    {
        node_to_inorder[inorder[i]] = i;
    }
    
    
    TreeNode* root = reconstruct(inorder,preOrder,0,preOrder.size() - 1,
                                0, inorder.size() - 1,node_to_inorder);
    inorderTrav(root);
    cout << endl;
    preOrderTrav(root);
    return 0;
}