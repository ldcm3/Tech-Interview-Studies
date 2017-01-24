
#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeSortedListNodes(ListNode* headA, ListNode* headB)
{
    ListNode* dumpy_head = new ListNode(-1);
    ListNode* curNode = dumpy_head;
    
    while (headA && headB)
    {
        if (headA->val <= headB->val)
        {
            curNode->next = headA;
            headA = headA->next;
        }
        else
        {
            curNode->next = headB;
            headB = headB->next;
        }
        
        curNode = curNode->next;
    }
    
    if (headA)
        curNode->next = headA;
    if (headB)
        curNode->next = headB;
        
    return dumpy_head->next;
    
}

// return second half head pointer
ListNode* partition(ListNode* head)
{
    int len = 0;
    ListNode* curNode = head;
    
    while(curNode)
    {
        curNode = curNode->next;
        ++len;
    }
    
    ListNode* dumpy_head = new ListNode(-1);
    dumpy_head->next = head;
    
    for (int i = 0; i < len/2; ++i)
    {
        dumpy_head = dumpy_head->next;        
    }
    
    ListNode* secondHalf = dumpy_head->next;
    dumpy_head->next = nullptr;
    
    return secondHalf;
}

ListNode* sortListNode(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // only call partition if list is at least greater than 1
    ListNode* secondHalf = partition(head);    
       
    return mergeSortedListNodes(sortListNode(head),sortListNode(secondHalf));
}

    
int main()
{
    ListNode* head = new ListNode(9);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    ListNode* curNode = sortListNode(head);

    while(curNode)
    {
        cout << curNode->val << " ";
        curNode = curNode->next;
    }
    
    cout << endl;
    
    return 0;
}