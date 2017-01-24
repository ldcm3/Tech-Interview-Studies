/*
    Implement InsertAfter and Delete maitaining a tail pointer in the Linked List
    
    Be careful with special cases!
*/

#include<iostream>

using namespace std;

struct LinkedListNode
{
    LinkedListNode* next;
    int data;
};

class LinkedList
{
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
    public:
        LinkedList():
            head(nullptr),
            tail(nullptr) {}
        ~LinkedList()
        {
            delete head;
            delete tail;
        }
        
        void insert(int val)
        {
            LinkedListNode* newNode = new LinkedListNode;
            newNode->data = val;
            newNode->next = nullptr;
            
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        bool insertAfter(int val, int newVal)
        {
            if (!head)
                return 0;
            
            LinkedListNode* newNode = new LinkedListNode;
            newNode->data = newVal;
            
            LinkedListNode* curNode = head;
        
            while(curNode)
            {
                if(curNode->data == val)
                {
                    if (curNode == tail) // insertint at end of the list
                    {
                        tail->next = newNode;
                        tail = tail->next;
                    }
                    else
                    {
                        newNode->next = curNode->next;
                        curNode->next = newNode;
                    }
                    
                     return 1;   // everything ok
                }
                
                curNode = curNode->next;
            }
            
            return -1; // value not found
        }
        
        bool deleteNode(int val)
        {
            
            if (!head) 
                return -1;
            
            LinkedListNode* curNode = head;
            LinkedListNode* nodeToDelete = head;  
            
            if (head->data == val) // delete the head
            {
                nodeToDelete = head;
                head = head->next;
                
                if (!head)  // if only one element in the list before delete head
                {
                    tail = nullptr;
                }
                
                delete nodeToDelete;
                return 1;
            }
            else
                nodeToDelete = curNode->next;
            
            while(nodeToDelete) // 10
            {
                  
                if (nodeToDelete->data == val) // 10 true
                {
                    curNode->next = nodeToDelete->next; // curnode->next = 3
                    
                    if (curNode->next == nullptr) // is tail
                        tail = curNode;
                    delete nodeToDelete;
                    return 1;
                }
                
                curNode = nodeToDelete; // 2
                nodeToDelete = nodeToDelete->next; // 10
            }
            
            return -1;
        }
        
        void print()
        {
            LinkedListNode* curNode = head;
            
            while(curNode)
            {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            
            cout << endl;
        }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    
    list.insertAfter(2,10);
    
   // list.deleteNode(1);
     list.print();
   list.deleteNode(10);
   list.deleteNode(1);

    
    list.print();
    
    return 0;
}