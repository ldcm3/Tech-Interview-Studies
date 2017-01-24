/*
    Given a singly linked list, return a random node's value from the linked list.
    Each node must have the same probability of being chosen.

    Follow up:
    What if the linked list is extremely large and its length is unknown to you? 
    Could you solve this efficiently without using extra space?
    
    ----------------------------------------------------------------------------------
    
    The idea is using a simpler version of Reservoir Sampling:
    
    1) first node has 1/1 probability to be chosen 
    2) Second node has 1/2 to be chosen and 1/2 to be not
    3) Third node has 1/3 probability to be chosen and 2/3 to be not == ()
    
    At the end: 
    
    4) so first node has (1 * 1/2 * 2/3) probability to be chosen == 1/3
    5) second Node has   (1/2 * 2 / 3)   probability to be chosen == 1/3
    6) thied Node has   (1 / 3)   probability to be chosen == 1/3
*/

#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int x):
        val(x),
        next(nullptr)
        {}
};

int getRandom(ListNode* head)
{
    int result = head->val;
    
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
    
    if (!head->next)
        return result;
    
    ListNode* curNode = head->next;
    
    int n = 2;
    
    while (curNode)
    {
        if (rand() % n == 0)
            result = curNode->val;
            
        curNode = curNode->next;
        ++n;
    }
    
    return result;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    cout << getRandom(head) << endl;
}
