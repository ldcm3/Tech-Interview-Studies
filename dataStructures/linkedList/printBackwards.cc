/*

    Print a single linked list backwards without modifying the list and
    using less than O(n) space.
    
*/

#include<iostream>
#include<vector>

using namespace std;

struct LinkedNode{
    int val;
    LinkedNode* next;
    
    LinkedNode(int v): val(v), next(nullptr) {}
};

void printBackwards(LinkedNode* head)
{
    if(head == nullptr)
        return ;
    
    printBackwards(head->next);
    
    cout << head->val << " ";
    
    
}

int main()
{
    
    LinkedNode* head = new LinkedNode(1);
    head->next = new LinkedNode(2);
    head->next->next = new LinkedNode(3);
    
    printBackwards(head);
    
    return 0;
}