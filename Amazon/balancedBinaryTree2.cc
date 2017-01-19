/*
    
Write a function to see if a binary tree  is balanced.
For this problem a tree is balanced if the difference between the depths of any two leaf nodes  is no greater than one.

    
    Solution Complexity
    
    O(n) time and O(n) space (using Depth-First Search instead of recursion to avoid stack overflow ).
    
    We use DFS instead of BFS because we want to reach the leaf nodes as soon as possible
        and break the iterative loop in case it is not balanced
*/

#include<iostream>
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
      return left;
    }

    BinaryTreeNode* insertRight(int val)
    {
      this->right = new BinaryTreeNode(val);
      return right;
    }
};

bool isBalanced(BinaryTreeNode* root)
{
    stack <pair <BinaryTreeNode*, size_t>> nodes;
    nodes.push(make_pair(root,0));
    
    size_t minDepth,maxDepth;
    bool isFirstFoundLeaf = true; // flag
    
    while (!nodes.empty())
    {
        BinaryTreeNode* curNode = nodes.top().first;
        size_t depth = nodes.top().second;
        nodes.pop();
        
        if (!curNode->left && !curNode->right) // is a Leaf
        {
            if (isFirstFoundLeaf) // initialize minDepth and maxDepth
            {
                isFirstFoundLeaf = false;
                minDepth = depth;
                maxDepth = depth;
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
                nodes.push(make_pair(curNode->left, depth + 1));
            
            if (curNode->right)
                nodes.push(make_pair(curNode->right,depth + 1));
        }
    }
    
    return true;
}

int main()
{
  BinaryTreeNode* root = new BinaryTreeNode(10);
  root->insertLeft(8);
  root->insertRight(25);
  root->left->insertLeft(6);
  root->left->left->insertRight(10);

  cout << isBalanced(root) << endl;
  return 0;
}
