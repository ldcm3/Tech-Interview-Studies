/*
    CHECK IF A SINGLE LINKED LIST CONTAINS A CYCLE
    
    
    O(n) time and O(1)O(1) space.

The worst case is when we do have a cycle.
First, we notice that when both runners are circling around the cycle fastRunner can never skip over slowRunner.
Suppose fastRunner had just skipped over slowRunner. fastRunner would only be 1 node ahead of slowRunner, since their speeds differ by only 1. So we would have something like this:

  [ ] -> [s] -> [f] 

What would the step right before this "skipping step" look like?
fastRunner would be 2 nodes back, and slowRunner would be 1 node back.
That means they would be at the same node! 
So fastRunner didn't skip over slowRunner! (This is a proof by contradiction.)


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

bool containsCycle(LinkedListNode* root)
{
    
    if(!root)
        return false;
        
    LinkedListNode* slow = root;
    LinkedListNode* fast = root;
    
    while(fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      
      if(fast == slow)
        return true;
    }

      return false;
}

int main()
{
    LinkedListNode* root = new LinkedListNode(1);
    
    LinkedListNode* a = new LinkedListNode(2);
    LinkedListNode* b = new LinkedListNode(3);
    root->next = a;
    a->next =  b;
    root->next->next->next = root;
    
    cout << containsCycle(root) << endl;
    
    return 0;
}
