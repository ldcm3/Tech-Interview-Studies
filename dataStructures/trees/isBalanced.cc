/* 

Check if binary Tree is Balanced (greates diff between leafs is not > 1 )

*/


#include <iostream>
#include <stack>

using namespace std;

class BinaryTreeNode
{
    public:
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        
        BinaryTreeNode(int val):
            value(val),
            left(nullptr),
            right(nullptr)
            {}
        ~BinaryTreeNode()
        {
            delete left;
            delete right;
        }
        
        BinaryTreeNode* insertLeft(int val)
        {
            this->left = new BinaryTreeNode(val);
            return this->left;
        }
        
        BinaryTreeNode* insertRight(int val)
        {
            this->right = new BinaryTreeNode(val);
            return this->right;
        }
};

bool isBalanced(BinaryTreeNode* root)
{
    size_t minDepth = 0;
    size_t maxDepth = 0;
    bool firstLeafFound = true;
    size_t depth = 1;
    
    // Depth First Search
    
    stack <pair<BinaryTreeNode*, size_t> > dfs;
    dfs.push(make_pair(root,depth));
    
    while(!dfs.empty())
    {
        BinaryTreeNode* curNode = dfs.top().first;
        size_t depth = dfs.top().second;
        dfs.pop();
        
        if (!curNode->left && !curNode->right) // leaf Node
        {
            if (firstLeafFound)
            {
                minDepth = depth;
                maxDepth = depth;
                firstLeafFound = false;
            }
            else
            {
                minDepth = min(minDepth, depth);
                maxDepth = max(maxDepth, depth);
            }
            
            if (maxDepth - minDepth > 1)
                return false;
        }
        else
        {
            if (curNode->left)
                dfs.push(make_pair(curNode->left,depth + 1));
            
            if (curNode->right)
                dfs.push(make_pair(curNode->right,depth + 1));
        }
    }

    return true;
}

    
int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->insertLeft(5);
    root->insertRight(10);
    (root->left)->insertLeft(3);
   //(root->left->left)->insertLeft(9);
    
    cout << isBalanced(root) << endl;
    
    return 0;
}