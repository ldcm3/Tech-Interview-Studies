/* 

    BINARY SEARCH TREE  


*/


#include <iostream>

using namespace std;

struct node
{
    struct node *right, *left;
    int data;
};

// A utility function to do inorder traversal of BST
struct node* createNode(int val)
{
    node* newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    
    return newNode;
}

// Insert data in a Binary Search Tree
struct node* insert(struct node* root, int val)
{
    if (!root) // root is NULL
    {
        return createNode(val);
    }
    
    if (val < root->data)
        root->left = insert(root->left,val);
    else if (val > root->data)
        root->right = insert(root->right,val);
        
    // return the (unchanged) node pointer
    return root; 
}

// a utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main ()
{
    
    /* BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
       
    struct node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
 
    return 0;
}