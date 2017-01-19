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

LinkedListNode* kthToLastNode(size_t kth, LinkedListNode* head)
{
    LinkedListNode* curNode = head;
    
    size_t listLen = 1;
    
    while(curNode->next)
    {
        ++listLen;
        curNode = curNode->next;
    }
    
    size_t stepsToKth = listLen - kth;
    
    curNode = head;
    
    for (size_t steps = 0; steps < stepsToKth; ++steps)
    {
        curNode = curNode->next;        
    }
    
    return curNode;
}


int main()
{

    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    LinkedListNode* d = new LinkedListNode(4);
    LinkedListNode* e = new LinkedListNode(5);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    
    cout << kthToLastNode(2, a)->value << endl;
        
    
    return 0;
}