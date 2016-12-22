#include <iostream>
#include <vector>

using namespace std;

/*
    Build a Binary Search Tree from a sort array
    
*/


struct node
{
  node *left;
  node *right;
  int data;
};

node* buildBST(int start,int end,vector<int> &A)
{
   
    if(start > end)
        return NULL;
    
    node *newNode = new node;
    
    int mid = (start + end) / 2;
    
    newNode->data = A[mid];
    
    newNode->left = buildBST(start,mid - 1,A);
    newNode->right = buildBST(mid+1,end,A);
    
    return newNode;
        
}

void inorder(node *root) // Visit in ascending order
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    vector<int> A = {1,2,3,4,5,6,7,8};
    
    node *root = buildBST(0,A.size() - 1,A);
    
    inorder(root);
    
    return 0;
}