/* 

   Delete a node from a singly-linked list , given only a variable pointing to that node.

    Solution in O(1) space and O(1) time
    
    There are two potential side-effects:

    -   Any references to the input node have now effectively been reassigned to its next_ node
    -   If there are pointers to the input node's original next node, those pointers now point to a "dangling" node


*/


#include <iostream>

using namespace std;

class LinkedListNode
{
    public:
        int value;
        LinkedListNode* next;
        
        LinkedListNode(int val):
            value(val),
            next(nullptr)
            {}
        ~LinkedListNode()
        {
            delete next;
        }
        
};

void printLinkedList(LinkedListNode* head)
{
    LinkedListNode* curNode = head;
    
    while(curNode)
    {
        cout << curNode->value << " ";
        curNode = curNode->next;
    }
    
    cout << endl;
}

void deleteNode(LinkedListNode* nodeToDelete)
{
    LinkedListNode* nextNode = nodeToDelete->next;
    
    if(nextNode)
    {
        nodeToDelete->value = nextNode->value;
        nodeToDelete->next = nextNode->next;
        delete nextNode;
    }
    else
    {
        throw ("ERROR");
    }
}

int main()
{
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    
    a->next = b;
    b->next = c;
    
    printLinkedList(a);
    deleteNode(b);
    printLinkedList(a);
    
    return 0;
}