/*
    fastRunner can never skip over slowRunner. Why is this true?
    
    [ ] -> [s] -> [f]
    
    Suppose fastRunner had just skipped over slowRunner. 
    fastRunner would only be 1 node ahead of slowRunner, 
    since their speeds differ by only 1. 
    That means they would be at the same node at the step before

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
}

bool containsCycle(LinkedListNode* head)
{
    LinkedListNode* slowRunner = head;
    LinkedListNode* fastRunner = head;
    
    while(fastRunner && fastRunner->next)
    {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
        
        if (slowRunner == fastRunner)
            return true;
    }
    
    return false;
}

int main()
{
    return 0 ;
}