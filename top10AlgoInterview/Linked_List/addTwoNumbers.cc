/*
    Add two numbers represented by linked lists
*/

#include<iostream>
#include<vector>

using namespace std;

struct LinkedNode
{
    LinkedNode* next;
    int val;
    
    LinkedNode(int v): val(v), next(nullptr) {}
};

void swapPointer(LinkedNode*& a, LinkedNode*& b)
{
    LinkedNode* tmp = a;
    a = b;
    b = tmp;
}

void printL(LinkedNode* head)
{
    LinkedNode* cur = head;
    
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    
    cout << endl;

}

int getSize(LinkedNode* a)
{
    int count = 0;
    
    LinkedNode* cur = a;
    
    while(cur)
    {
        cur = cur->next;
        ++count;
    }
    
    return count;
    
}

int sumSameSize(LinkedNode* a, LinkedNode* b, LinkedNode*& res)
{
    if(!a && !b)
        return 0;
    
    res = new LinkedNode(0);
    
    int c = sumSameSize(a->next,b->next,res->next);
    
    int tmp = a->val + b->val + c; 
    
    res->val = tmp % 10;
    
    return tmp / 10;
}

int sumCarryAndRemain(LinkedNode* a,int diff,int carry, LinkedNode*& res)
{
    if(diff == 0)
        return carry;
    
    res = new LinkedNode(0);
    int c = sumCarryAndRemain(a->next,--diff,carry,res->next);
    
    int tmp = c + a->val;
    res->val = tmp % 10;
    
    return tmp / 10;
}

LinkedNode* join (LinkedNode* resHeader,LinkedNode* secondPartResHeader)
{
    LinkedNode* cur = resHeader;
    
    while(cur->next)
        cur = cur->next;
    
    cur->next = secondPartResHeader->next;
    
    return resHeader;
}

LinkedNode* sum(LinkedNode* a, LinkedNode* b)
{
    // both lists empty
    if(!a && !b)
        return nullptr;
    // First list is empty
    else if(!a)
        return b;
    // Second list is empty
    else if(!b)
        return a;
        
    int sizeA = getSize(a);
    int sizeB = getSize(b);
    
    LinkedNode* resHeader = new LinkedNode(-1);
    int carry = 0;
    
    if(sizeA == sizeB)
        carry = sumSameSize(a,b,resHeader->next);
    else
    {
       
        if(sizeB > sizeA)
            swapPointer(a,b);
         
        int diff = abs(sizeA - sizeB);
        
        LinkedNode* cur;
        // move the diff number of nodes
        for(cur = a; diff--; cur=cur->next);
        
        LinkedNode* secondPartResHeader = new LinkedNode(-1);
        
        carry = sumSameSize(cur,b,secondPartResHeader->next);
        
        diff = abs(sizeA - sizeB);
        carry = sumCarryAndRemain(a,diff,carry,resHeader->next);
        
        resHeader = join(resHeader,secondPartResHeader);
    }
    
    // if it is still remaining a carry, append it to the head
    LinkedNode* carryNode = new LinkedNode(1);
    
    carryNode->next = resHeader->next;
    
    return carry != 0 ? carryNode :
                        carryNode->next;
}



int main()
{
    LinkedNode* aHead = new LinkedNode(1);
    aHead->next = new LinkedNode(2);
    // aHead->next->next = new LinkedNode(3);
    
    LinkedNode* bHead = new LinkedNode(8);
    bHead->next = new LinkedNode(8);
    // bHead->next->next = new LinkedNode(3);

    LinkedNode* res = sum(aHead,bHead);
    
    printL(res);
    
    return 0;
}
