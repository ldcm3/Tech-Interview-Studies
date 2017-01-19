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
    LinkedListNode* cur = head;

        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

LinkedListNode* reverseLinkedList(LinkedListNode* head)
{
    LinkedListNode* currentNode = head;
    LinkedListNode* prev = nullptr;
    LinkedListNode* nextNode = nullptr;
    
    while (currentNode)
    {
        nextNode = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = nextNode;
    }
    
    return prev;
}

int main()
{
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    
    cout << "Linked List is: ";
    printLinkedList(head);
    
    LinkedListNode* newHead =  reverseLinkedList(head);

    cout << "Reverse Linked List is: ";
    printLinkedList(newHead);
    
    return 0;   
}