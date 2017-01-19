/*
    
Write a function to see if a binary tree  is balanced.
For this problem a tree is balanced if the difference between the depths of any two leaf nodes  is no greater than one.

    
    Solution Complexity
    
    O(n) time and O(n) space ( in the call stack ).
*/

#include<iostream>

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

BinaryTreeNode* isBalancedUtil(BinaryTreeNode* root, int &closestLeaf, int &deepestLeaf, int level)
 {
   if (root == nullptr)
    return nullptr;
    
    BinaryTreeNode* leftNode = isBalancedUtil(root->left,closestLeaf,deepestLeaf,level + 1);
    BinaryTreeNode* rightNode = isBalancedUtil(root->right,closestLeaf,deepestLeaf,level + 1);
    
    if (leftNode  == nullptr &&
       rightNode == nullptr)  // Current node is a Leaf
    {
      closestLeaf = min(closestLeaf, level);
      deepestLeaf = max(deepestLeaf, level);
    }
    
    return root;
 }

bool isBalanced(BinaryTreeNode* root)
{
  int level = 1;
  int deepestLeaf = 0;
  int closestLeaf = 9999;

  isBalancedUtil(root,closestLeaf,deepestLeaf,level);
  
  return deepestLeaf - closestLeaf > 1? false : true;
}

int main()
{
  BinaryTreeNode* root = new BinaryTreeNode(10);
  root->insertLeft(8);
  root->insertRight(25);
  root->left->insertLeft(6);
  //root->left->left->insertRight(10);

  cout << isBalanced(root) << endl;
  return 0;
}
