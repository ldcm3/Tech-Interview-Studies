/*

    BINARY SEARCH TREE using array implementation
    
*/

#include <iostream>
#include <cstring>

using namespace std;


struct node
{
    int data,Lidx,Ridx; //Left and Right child
};

class BST 
{
    int cap; // capacity
    int size; // current size
    struct node** tree;  //Pointer to pointer or type tree

    public:

        BST(int cap);
        struct node* createNode(int val,int idx);
        void insert (int val);
        void inorder(int rootIdx);
};

BST :: BST (int cap)
{
    this->cap = cap;
    size = 0;
    tree = new node *[cap];  // Declares array of pointers
}

struct node* BST :: createNode(int val, int idx)
{
   struct node*  newNode = new node;
    newNode->data = val;
    newNode->Lidx = 2*idx;
    newNode->Ridx = 2*idx + 1; 
    
    return newNode;
}


void BST :: insert(int val)
{
    if (this->size == 0) // empty tree, initialize the root
    {
        tree[1] = createNode(val,1);
        this->size++;
        return;
    }
        
    int baseIdx = 1;

    while (baseIdx < this->cap)
    {
        if(!tree[baseIdx]) // NULL node, insert element
        {
            tree[baseIdx] = createNode(val, baseIdx);
            this->size++;
            return;
        }
        
        if (val <= tree[baseIdx]->data)  
            baseIdx = tree[baseIdx]->Lidx;
        else if(val > tree[baseIdx]->data)
            baseIdx = tree[baseIdx]->Ridx;
    }
    
}

// utility function to iterate do a inorder traversal
void BST :: inorder(int rootIdx)
{

    if (tree[rootIdx] == NULL)
    {
        return;
    }        
    
    inorder(tree[rootIdx]->Lidx);
    cout << tree[rootIdx]->data << " ";
    inorder(tree[rootIdx]->Ridx);

}

int main()
{
    BST bst(100);
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    
    
    bst.inorder(1);
    return 0;
}
