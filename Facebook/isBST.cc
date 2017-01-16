#include<iostream>
#include <limits>  


using namespace std;

class BinaryTreeNode
{
  public:
    int value;
    BinaryTreeNode* right;
    BinaryTreeNode* left;

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

    BinaryTreeNode * insertLeft(int value)
    {
      this->left = new BinaryTreeNode(value);
      return this->left;
    }

    BinaryTreeNode * insertRight(int value)
    {
      this->right = new BinaryTreeNode(value);
      return this->right;
    }
};

bool isBST(BinaryTreeNode* root,const int minEle,const int maxEle)
{
  if(!root)
    return true;

  if(root->value < minEle || root->value > maxEle)
    return false;
  else
    return isBST(root->left, minEle, root->value) && isBST(root->right,root->value,maxEle);

}


int main()
{
    // -> for accessing object member variables and methods via pointer to object
    // . for accessing object member variables and methods via object instance
    
    
    // BinaryTreeNode root(8);
    // root.insertLeft(5);
    // root.insertRight(10);
    // (root.left)->insertLeft(3);
    // (root.left)->insertRight(7);
    // (root.right)->insertLeft(9);
    
    // // Create a pointer to the root
    // BinaryTreeNode* pointerToRoot;
    // pointerToRoot = &root;
    
    
    
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->insertLeft(5);
    root->insertRight(10);
    (root->left)->insertLeft(3);
    (root->left)->insertRight(7);
    (root->right)->insertLeft(9);
    

    cout << isBST(root,numeric_limits<int>::min(),numeric_limits<int>::max()) << endl;
    
    /*
                8
               / \
              5   10
             / \  / \
            3  7  9
    */
    
    
  return 0;
}
