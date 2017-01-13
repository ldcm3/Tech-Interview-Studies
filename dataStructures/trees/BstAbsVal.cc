/*

Given a binary search tree and a target node K. 
The task is to find the node with minimum absolute difference with given target value K.

Solution using lower_bound concept;

*/

#include <iostream>
#include <vector>

using namespace std;

struct node
{
  node *left = nullptr;
  node *right = nullptr;
  int val;
};

struct node* createNode(int data)
{
  node* newNode = new node;
  newNode->val = data;

  return newNode;

}

struct node*  insert (node* root, int data)
{
  if(root == NULL)
  {
    return createNode(data);
  }

  if (data <= root->val)
    root->left = insert(root->left, data);
  else if( data > root->val)
    root->right = insert(root->right, data);

  return root;
}

void lower_util(node* root,int data,int &ans)
{
    if (root == NULL)
        return;
    
    if (data <= root->val)
    {
        ans = root->val;
        lower_util(root->left,data,ans);
    }
    else
        lower_util(root->right,data,ans);
}

int lower_search (node* root, int data)
{
    int ans;
    
    lower_util(root,data,ans);
    
    cout << ans << endl;
    
    return ans;
}

void upper_util(node* root, int data, int &ans)
{
    if(root == NULL)
        return;
        
    if (data < root->val)
    {
        upper_util(root->left,data,ans);
    }
    else
    {
        ans = root->val;
        upper_util(root->right,data,ans);
    }
        
    }
int upper_search (node* root, int data)
{
    int ans;
    upper_util(root,data,ans);
    
    cout << ans << endl;
    
    return ans;
}

void inorder(node* root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
    
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
    
    cout << "Min Absolute is "  << min(abs(upper_search(root,x) - x), abs(lower_search(root,x) - x)) << endl;
    
  return 0;
}
