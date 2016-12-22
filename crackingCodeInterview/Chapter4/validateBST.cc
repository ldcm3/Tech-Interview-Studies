#include <iostream>
 
using namespace std;

/*
    Implement a function to check if a binary tree is a BST
*/

struct node 
{
    int data;
    struct node *left = NULL;
    struct node *right = NULL;
};

struct node* createNode(int val)
{
    node *newNode = new node;
    newNode->data = val;
    
    return newNode;
}

bool isBST(node *root, int min_val, int max_val)
{
    // In-Order traversal
    if(!root)
        return 1;
    
    if (root->data < min_val || root->data > max_val)
        return false;
        
        
    return isBST(root->left, min_val,root->data - 1) &&
           isBST(root->right, root->data + 1, max_val);
  
}

int main ()
{
     struct node *root = createNode(4);
  root->left        = createNode(2);
  root->right       = createNode(5);
  root->left->left  = createNode(1);
  root->left->right = createNode(3); 
 
  if(isBST(root,-999, 999))
    printf("Is BST");
  else
    printf("Not a BST");
     
    return 0;
}