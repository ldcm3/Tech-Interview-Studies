/*
    Merge K sorted Linked List


    Solution Complexity 
    
    O(nlogk)
    
*/

#include<vector>
#include<queue>
#include<iostream>

#define INT_MAX 999999

using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    
    ListNode(int x): val(x),next(nullptr){}
};

class Greater
{
public:
    bool operator()(ListNode* a, ListNode* b) const
    {
        return a->val > b->val;
    }
};

ListNode* sortKLinkedList (const vector<ListNode*>& lists)
{
    priority_queue<ListNode*, vector<ListNode*>, Greater> min_heap;
  
    for (auto listRoot : lists)
    {
        if (listRoot)
            min_heap.emplace(listRoot);
    }
    
    ListNode* header = new ListNode(INT_MAX);
    ListNode* cur = header->next;
    
    while(!min_heap.empty())
    {
        cur->next = min_heap.top();
        min_heap.pop();
        cur = cur->next;
        
        if(cur->next)
            min_heap.emplace(cur->next);
    }
    
    return header->next;
}
int main()
{
    
    return 0;
}