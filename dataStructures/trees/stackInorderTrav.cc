/*
    Inorder TRaversal using Stack
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

void inorderStackTraversal(TreeNode* root)
{
    TreeNode* cur = root;
    stack<TreeNode*> s;
    
    while(!s.empty() || cur)
    {
        if(cur)
        {
            s.emplace(cur);
            cur = cur->left;
        }
        else
        {
            cout << s.top()->val << " ";
            cur = s.top()->right;
            s.pop();
        }
    }
    cout << endl;
}
int main()
{
    TreeNode *root =  new TreeNode(1);
    root->left        =  new TreeNode(2);
    root->right       = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5); 
    
    inorderStackTraversal(root);
    return 0;
}