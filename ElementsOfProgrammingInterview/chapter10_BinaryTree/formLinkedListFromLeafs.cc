/*
    
    Compute a linkedlist from the leaves of a binary Tree.
    Leaves should appear from the left to right.

*/

#include<iostream>
#include<vector>

using namespace std;

struct LinkedNode
{
    LinkedNode* next;
    int val;
    
    LinkedNode(int v): val(v), next(nullptr) {}
};

struct TreeNode{
    TreeNode *left,*right;
    int val;
    
    TreeNode(int v): val(v),left(nullptr),
        right(nullptr){}
};

void formLinkedList(TreeNode* root, LinkedNode*& node)
{
    if(!root)
        return;
        
    // leaf    
    if(!root->left && !root->right)
    {
        node->next = new LinkedNode(root->val);
        node = node->next;
        //cout << root->val << " ";
        return;
    }
    
    formLinkedList(root->left,node);
    formLinkedList(root->right,node);
    
    
}

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    LinkedNode* head = new LinkedNode(0);
    LinkedNode* headTo = head;
    formLinkedList(root,headTo);
       
    LinkedNode* s = head->next;
    
    while(s)
    {
        cout << s->val << " ";
        s = s->next;
    }
    
    cout << endl;
    return 0;
}