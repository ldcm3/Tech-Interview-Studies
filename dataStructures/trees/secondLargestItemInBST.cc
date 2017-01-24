#include <iostream>

using namespace std;

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

BinaryTreeNode* findLargest(BinaryTreeNode* root)
{
    BinaryTreeNode* curNode = root;
    
    while(curNode->right)
    {
        curNode = curNode->right;
    }
    
    return curNode;
}

BinaryTreeNode* findSecondLargest(BinaryTreeNode* root)
{
    
    BinaryTreeNode* curNode = root;
    
    while (1)
    {
        if (curNode->left && !curNode->right)
            return findLargest(curNode->left);
        
        if (curNode->right && !curNode->right->left && !curNode->right->right)
            return curNode;
            
        curNode = curNode->right;
    }
}