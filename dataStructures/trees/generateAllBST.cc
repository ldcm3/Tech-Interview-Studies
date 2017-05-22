/*

 First count of possible BST (Binary Search Trees)s is discussed, then construction of all possible BSTs.

*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    TreeNode *left,*right;
    int val;
    TreeNode(int v): left(nullptr),right(nullptr),val(v) {}
};

int countBST(int n)
{
    vector<int> dp (n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int root = 1; root <= i; ++root)
        {
            dp[i] += dp[root - 1]*dp[i - root];
        }
    }
    
    return dp[n];
    
}

vector<TreeNode*> buildTrees(int start, int end)
{
    if (start > end)
        return {nullptr};
        
    vector<TreeNode*> list;
    
    for (int i = start; i <= end; ++i)
    {
        vector<TreeNode*> leftSub = buildTrees(start, i - 1);
        vector<TreeNode*> rightSub = buildTrees(i + 1, end);
       
        
        for (auto &leftNode : leftSub)
        {
            for (auto &rightNode : rightSub)
            {
                 TreeNode* curRoot = new TreeNode(i);
                 curRoot->left = leftNode;
                 curRoot->right = rightNode;
                 list.emplace_back(curRoot);
            }
        }
    }
    
    return list;
}

vector<TreeNode*> generateAllBST(int n)
{
    if (n == 0)
        return {};
        
    return buildTrees(1,n);
}

int main()
{
    // cout << countBST(10) << endl;
    generateAllBST(3);
    
    return 0;
}