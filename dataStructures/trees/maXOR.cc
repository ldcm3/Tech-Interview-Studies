/*
    Find the max XOR between two Elements in a vector
    
    Solution Complexity Time : O(n);
*/


#include<iostream>
#include<vector>

using namespace std;


struct TreeNode
{
    TreeNode *left,*right;
    int val;
    
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

TreeNode* nextOrInsert(TreeNode* node, int bit)
{

    if(bit)
    {
        if (node->right)
            return node->right;
        else
        {
            TreeNode* newNode = new TreeNode(1);
            node->right = newNode;
            return newNode;
        }
    }
    else
    {
        if (node->left)
            return node->left;
        else
        {
            TreeNode* newNode = new TreeNode(0);
            node->left = newNode;
            return newNode;
        }
    }
}

void insertTrie(TreeNode* root,int n)
{
    TreeNode* cur = root;
    
    for(int i = 31; i >= 0; --i)
    {
        if (n & (1 << i))
            cur = nextOrInsert(cur,1);
        else
            cur = nextOrInsert(cur,0);
    }
    
}

TreeNode* buildTrie(vector<int>& nums)
{
    TreeNode* root = new TreeNode(-1);

    for (auto &n : nums)
        insertTrie(root,n);
        
    return root;
}

int maXOR(TreeNode* root, int n)
{
    TreeNode* cur = root;
    int ans = 0;
    
    for(int i = 31; i >= 0; --i)
    {
        if (n & (1 << i))
        {
            if(cur->left) // 0
            {
                ans |= (1 << i);
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        else
        {
            if(cur->right) // 1
            {
                ans |= (1 << i);
                cur = cur->right;
            }
            else
                cur = cur->left;
        }
    }
    
    return ans;
}


int findMaximumXOR(vector<int>& nums) {
    
    if (nums.size() == 0)
        return 0;
    
    TreeNode* root = buildTrie(nums);
    
    int ans = 0;
    
    for(int n : nums)
        ans = max(ans,maXOR(root,n));
    
    return ans;
}

int main()
{
    
    vector<int> inp = {3,10,5,25,2,8};
    cout << findMaximumXOR(inp) << endl;
    
    return 0;
}