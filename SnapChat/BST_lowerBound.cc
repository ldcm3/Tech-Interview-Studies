/*

Given a binary search tree, which contains only integers, and may contain duplicated values. And we only know that the tree is a legal binary search tree, that is, left_child <= root <= right_child.

Your mission is to find the lower-bound and upper-bound of a given number key.

The behavior of the functions are similar to std::lower_bound and std::upper_bound.

lowerbound :  first element in the range [first,last) which does not compare less than val.
upperbound : first element in the range [first,last) which compares greater than val.


*/

#include <iostream>
#include <vector>


using namespace std;

struct node
{
    struct node *left,*right;
    int data;
};

node *ans = new node;

struct node* createNode(int val)
{
    node *newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    
    return newNode;
}

struct node* addNode(struct node* root, int val)
{
    if (!root)
    {
        return createNode(val);
    }
    
    if (val <= root->data)
        root->left = addNode(root->left,val);
    else
        root->right = addNode(root->right,val);
}

void lowerBound(struct node* root,int val)
{
    if (root == nullptr)
        return;
        
    if (root->data >= val) 
    {
         ans = root;
        lowerBound(root->left,val);
    }
    else
    {
        lowerBound(root->right,val);
    }
  
}

void upperBound(struct node* root,int val)
{
    if (root == nullptr)
        return;
        
    if (root->data > val)
    {
        ans = root;
        upperBound(root->left,val);
    }
    else
        upperBound(root->right,val);
}


int main()
{
    
    struct node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left  = createNode(2);
    root->left->right  = createNode(2);
    root->right->right  = createNode(8);
    
    /*
                      3
                    /   \
                    2    4
                   / \    \
lower_bound(2) ->  2 2    8 <- upper_bound(4)
*/

    lowerBound(root,4);
    cout << "lowerbound: " <<  ans->data << endl;
    
    upperBound(root,3);
    cout << "upperbound: " <<  ans->data << endl;

    return 0;
}