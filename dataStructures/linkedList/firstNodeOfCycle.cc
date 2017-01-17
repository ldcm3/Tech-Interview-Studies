/*

Find fisrst node of a cycle in a Linked List


Floyd’s Cycle detection algorithm.
1) Detect Loop using Floyd’s Cycle detection algo and get the pointer to a loop node.
2) Count the number of nodes in loop. Let the count be k.
3) Fix one pointer to the head and another to kth node from head.
4) Move both pointers at the same pace, they will meet at loop starting node.

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

LinkedListNode* findElementInLoop(LinkedListNode* root)
{
    LinkedListNode* slowRunner = root;
    LinkedListNode* fastRunner = root;
    
    while (fastRunner != nullptr && fastRunner->next != nullptr)
    {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
        
        if(slowRunner == fastRunner)
            return slowRunner;
    }   
    
    return nullptr;
}

int countNodesInLoop(LinkedListNode* node)
{
     LinkedListNode* cur = node->next;
     int count = 1;
     
     while(cur != node)
     {
         count++;
         cur = cur->next;
     }
     
     return count;
}

LinkedListNode* firstNodeOfLoop(LinkedListNode* root)
{
    LinkedListNode* node = findElementInLoop(root);
    int k = countNodesInLoop(node);
    
    LinkedListNode* cur = root;
    for (int i = 0; i < k; i++)
    {
        cur = cur->next;
    }
    
    while(root != cur)
    {
        cur = cur->next;
        root = root->next;
    }
    
    return root;
    
}

int main()
{
    
    LinkedListNode* head = new LinkedListNode(1);
    LinkedListNode* a = new LinkedListNode(2);
    LinkedListNode* b = new LinkedListNode(3);
    head->next = a;
    a->next =  b;
    head->next->next->next = b;
    
    cout << firstNodeOfLoop(head)->value << endl;
    
    return 0;
}