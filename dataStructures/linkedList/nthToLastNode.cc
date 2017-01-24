/*
    Find the mth-to-last element of the list.
    When m == 0, the last element of the list is returned.
    
    Observation:
    
    - A very large list on a memory-constrained system might exist mostly
    in paged-out virtual memory(disk). In such a case, each complete traversal,
    of the list would require a large amount of disk access to swap the relevant
    portions of the list in and out of memory. Under these conditions an algorithm
    that made only one complete traversal of the list might be significantly faster
    that an algo that made two traversal to the list, even if they both have time
    complexity O(n).

*/
#include<iostream>

using namespace std;

struct LinkedListNode
{
    LinkedListNode* next;
    int data;
    
    LinkedListNode(int val): data(val), next(nullptr) {}
};

int nthToLastElement(int n, LinkedListNode* root)
{
    if (!root)
        return -1;
    
    LinkedListNode* mNode = root;
    LinkedListNode* curNode = root;
    
    // Create distance n between pointers
    for (int i = 0; i < n; ++i)
    {
        curNode = curNode->next;
        if (!curNode)
            return -1;
    }
    
    // Walk with both pointers until cur reaches end of the list
    
    while(curNode->next)
    {
        curNode = curNode->next;
        mNode = mNode->next;
    }
    
    return mNode->data;
}

int main()
{
    LinkedListNode* root = new LinkedListNode(1);
    root->next = new LinkedListNode(2);
    root->next->next = new LinkedListNode(3);
    
    cout << nthToLastElement(1,root) << endl;    
    return 0;
}