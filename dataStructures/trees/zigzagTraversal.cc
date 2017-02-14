/*
    Given a binary tree, return the zigzag level order traversal of its nodes' values.
    (ie, from left to right, then right to left for the next level and alternate between).

                                3
                               / \
                              9  20
                                /  \
                               15   7
                               
   output: [
               [3],
            [20,9],
            [15,7]
            ]

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    TreeNode *left,*right;
    int val;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

void zigZagTraversal(TreeNode* root)
{
    vector<vector<int>> ans;
    
    stack<TreeNode*> leftToRight;
    stack<TreeNode*> rightToLeft;
    
    if(root)
        leftToRight.emplace(root);

    
    while (!leftToRight.empty() || !rightToLeft.empty())
    {
        vector<int> level;
        
        if(!leftToRight.empty())
        {
              
            while(!leftToRight.empty())
            {
                TreeNode* cur = leftToRight.top();
                leftToRight.pop();
                
                level.emplace_back(cur->val);
                
                if (cur->left)
                    rightToLeft.emplace(cur->left);
                
                if(cur->right)
                    rightToLeft.emplace(cur->right);
        
            }
        }
        else
        {
            while(!rightToLeft.empty())
            {
                TreeNode* cur = rightToLeft.top();
                rightToLeft.pop();
                
                level.emplace_back(cur->val);
                
                // Note : for rightToLeft insert first the right child
                if (cur->right)
                    leftToRight.emplace(cur->right);
                
                if(cur->left)
                    leftToRight.emplace(cur->left);
            }
        }
        
        ans.emplace_back(level);
    }
    
    for (auto vec : ans)
    {
        for (auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    zigZagTraversal(root);
    return 0;
}