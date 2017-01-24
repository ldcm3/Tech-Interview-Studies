/* 

    Check if Binary Tree is a Binary Search Tree
    
*/

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode * insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode * insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

bool isBST(BinaryTreeNode* node,
            const int lowerBound = numeric_limits<int>::min()
            const int upperBound = numeric_limits<int>::max())
{
    if (node == nullptr)
        return true;
    
    if (node->value_ > upperBound || node->value_ < lowerBound)
        return false;
    
    return  isBST(node->left,lowerBound,node->value_) &&
            isBST(node->right,node->value,upperBound);
}