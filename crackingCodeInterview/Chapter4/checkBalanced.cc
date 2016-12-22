#include <iostream>
#include <vector> 

using namespace std;

/*

    Check if a binary tree is balanced (the heights of subtrees never differ by more than one)
    
*/
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

struct node* addNode(int val)
{
    node *newNode = new node;
    newNode->data = val;
    
    return newNode;
}


int isBalanced(node *root, bool &balanced)
{
    if(root == NULL)
        return -1;
        
    int a = isBalanced(root->left, balanced);
    int b= isBalanced(root->right, balanced);
    
    if(abs(a-b) > 1)
        balanced = false;
        
    return max(a,b) + 1;
}


int main () 
{
    node *root  = new node;
    root = addNode(1);
    root->left = addNode(2);
    root->right = addNode(3);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->right->left = addNode(6);
    root->right->right = addNode(7);
    root->right->right->right = addNode(8);
    root->right->right->right->right = addNode(9);


    
    bool balanced = true;
    isBalanced(root,balanced);
    
    balanced? cout << "Is balanced" : cout << "is NOT balanced";
    
    cout << endl; 
    return 0;
    
    
}