/*

    Stack implementation using a Linked List.
    
    
    Observations of Linked List X Dynamic Array:
        
        - A dynamic array have a random access and is ocasionally resized
        - When resizing is well planned, the DA may grow more efficient then a 
            LinkedList (that must dynamically allocate memory for each node)
        - an Stack using DA will have usually superior perfomance
        - On the other hand  Linked List Implementation is more convenient for being far less complicate

*/

#include <iostream>

using namespace std;

struct LinkedList
{   
    LinkedList* next;
    int data;
};


class Stack
{
    private:
        LinkedList* head;
        
    public:
        Stack():
            head(new LinkedList)
            {}
        
        bool isEmpty()
        {
            return head == nullptr;
        }
        void push(int val)
        {
            LinkedList* newNode = new LinkedList;
            newNode->data = val;
            
            if (head != nullptr)
                newNode->next = head;
            
            head = newNode;
        }
        
        int pop()
        {
            if (isEmpty())
                return -1;   // some error
                
            LinkedList* tmp = head;
            int tmpData = tmp->data;
            
            head = head->next;
            delete tmp;
            
            return tmpData;
        }
    
};

int main()
{
    Stack root;
    
    root.push(10);
    root.push(20);
    root.push(30);
    
    cout << root.pop() << endl;
    cout << root.pop() << endl;

    return 0;
    
}