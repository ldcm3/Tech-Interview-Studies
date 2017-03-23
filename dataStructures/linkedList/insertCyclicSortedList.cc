/*
        Given a node from a cyclic linked list which has been sorted, 
        write a function to insert a value into the list such that it remains a cyclic sorted list. 
        The given node can be any single node in the list.
*/


/*
    1->2->3    node = 2, val = 0
    ^     |
    -------
    
    0->1->2->-3
    ^         |           
    -----------
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node 
{
    Node* next;
    int val;
    Node(int v): val(v),next(nullptr) {}
};

Node* insertToCyclicList(Node* node,int val)
{
    Node* newNode = new Node(val);
    
    if (!node)
    {
        newNode->next = newNode;
        return newNode;
    }
    
    Node* cur = node;
    Node* prev = node;
    cur = cur->next;
    
    // newNode is greater than node->val
    // it might be in the middle of list or be placed at the end
    if (val > node->val)
    {
        while (cur != node && cur->val < val)
        {
            prev = cur;
            cur = cur->next;
        }
        
    }
    
    // newNode is smaller than node->val
    // it might be in the middle of list before node, or be placed at the head
    else
    {
        // Find head
        while (cur->val > prev->val)
        {
            prev = cur;
            cur = cur->next;
        }
        
        while (cur->val < val)
        {
            prev = cur;
            cur = cur->next;
        }
    }
    
    prev->next = newNode;
    newNode->next = cur;
    
    return val < node->val ? newNode : node;
}

void printList(Node* node)
{
    Node* cur = node->next;
    cout << node->val << " ";
    while (cur != node)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    
    cout << endl;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = head;
    
    head = insertToCyclicList(head,0);
    printList(head);
    return 0;
}