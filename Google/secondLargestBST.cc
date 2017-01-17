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
        delete right;
        delete left;
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
    BinaryTreeNode* current = root;

    while(current->right)
        current = current->right;

    return current;
}

BinaryTreeNode* findSecondLargestEle(BinaryTreeNode* root)
{
    if(!root->left && !root->right)
        throw "Error";

    BinaryTreeNode* current = root;

    while(true)
    {
        // cuurente is largest and has left subtree
        if (current->left && !current->right)
            return findLargest(current->left);

        // current is parent of largest
        if (current->right &&
            !current->right->left &&
            !current->right->right)
            return current;

        current = current->right;
    }

    return nullptr; // something went wrong;

}


int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(10);
    root->insertRight(15);
    root->right->insertLeft(14);
    
    cout << findSecondLargestEle(root)->value << endl;
    return 0;
}