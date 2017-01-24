/*
     4
   /   \
  2     7
 / \   / \
1   3 6   9


     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

// Recursive Solution -> O(n) time and O(h) space

void invertBinaryTree(BinaryTreeNode* root)
{
    if (root == nullptr)
        return;
    
    root->left =  invertBinaryTree(root->left)
    root->right = invertBinaryTree(root->right);
    
    BinaryTreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
}

// Iterative Solution  -> O(n) and O(n) space  -> might avoid overflow in the call stack
// top->bottom solution 
void invertBinaryTree(BinaryTreeNode* root)
{
    queue <BinaryTreeNode* > myqueue;
    myqueue.push(root);
    
    while (!myqueue.empty())
    {
        BinaryTreeNode* tmp = myqueue.top();
        myqueue.pop();
        BinaryTreeNode* leftNode = tmp->left;
        tmp->right = tmp->left;
        tmp->left = leftNode;
        
        if (tmp->left)
            myqueue.push(tmp->left);
        if (tmp->right)
            myqueue.push(tmp->right);
    
    }
    
}

int main()
{
    
    return 0;    
}