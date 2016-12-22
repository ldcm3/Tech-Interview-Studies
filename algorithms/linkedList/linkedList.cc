#include <iostream>

using namespace std;

/*
    Linked Lists
    
*/

struct node 
{
    int data;
    node *next;
};

class LinkedList 
{
    node *head = NULL;
    
    public:
        void AddNode(int value);
        void PrintLinkedList();
        void Reverse();
};

// Add a node to the linked list
void LinkedList::AddNode (int value)
{
    // If there is no data in the List, make it header
    node *newNode, *cur;
    newNode = new node;

    newNode->data = value;
    newNode->next = NULL;
    
    if(!head)
        head = newNode;
    
    // Add node to the end of the list
    else
    {
        cur = head;
        
        while (cur->next)
        {
            cur = cur->next;
        }
        
        cur->next = newNode;
    }
}

void LinkedList::PrintLinkedList()
{
    node *cur = head;
    
    while(cur->next)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
        
    cout <<  cur->data << endl;
}

//Reverse a Linked List
void LinkedList::Reverse()
{
    node *cur,*prev,*after;
    prev = NULL;
    cur = head;
    
    while(cur)
    {
        after = cur->next;
        cur->next = prev;
        prev = cur;
        cur = after;
    }
    
    head = prev;
}

// ======================== MAIN ===============================

int main()
{
    
    LinkedList mylist;

    mylist.AddNode(1);
    mylist.AddNode(2);
    mylist.AddNode(3);
    mylist.AddNode(4);
    mylist.AddNode(5);

    mylist.Reverse();
    
    mylist.PrintLinkedList();
        
    return 0;
}

