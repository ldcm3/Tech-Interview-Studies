/*

Given a binary search tree and a target node K. 
The task is to find the node with minimum absolute difference with given target value K.

Solution using Min Diff variable passed by address

*/

#include <iostream>
#include <vector>

using namespace std;

struct node
{
    node* left = nullptr;
    node* right = nullptr;
    int data;
};

struct node* createNode(int val)
{
    node* newNode = new node;
    newNode->data = val;
    return newNode;
}

struct node* insert(node* root,int val)
{
    if (root == nullptr)
        return createNode(val);
        
    if (val <= root->data)
        root->left = insert(root->left,val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}

void minDiffUtil(node* root,int val,int &minDiffValue)
{
    if(root == nullptr)
        return;
    
    if (root->data == val)
    {    
        minDiffValue = 0;
        return;
    }
    
    minDiffValue = min(minDiffValue, abs(root->data - val));
    
    if (val < root->data)
        minDiffUtil(root->left,val,minDiffValue);
    else
        minDiffUtil(root->right,val,minDiffValue);
    
}

int minDiff(node* root,int val)
{
    int minDiffValue = 999999; // INT_MAX
    
    minDiffUtil(root,val,minDiffValue);
    
    return minDiffValue;
}

int main()
{

  struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    //inorder(root);
    //cout << "lower bound is" << endl;
    int x;
    cin >> x;
    
    cout << "Min Absolute is "  << minDiff(root,x) << endl;
    
  return 0;
}
