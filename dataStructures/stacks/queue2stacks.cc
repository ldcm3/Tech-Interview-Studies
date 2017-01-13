/*

The worst case for a single item, which is the case where it is enqueued and then later dequeued.
The item enters inStack_ (costing 1 push),
then later moves to outStack_ (costing 1 pop and 1 push),
then later comes off outStack_ to get returned (costing 1 pop).

Each of these 4 pushes and pops is O(1) time
So our total cost per item is O(1).
Our m enqueue and dequeue operations put m or fewer items into the system, giving a total runtime of O(m)

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue
{
  stack <int> deq_s,enq_s;

  public:
    void enqueue(int val);
    int dequeue();
};

void MyQueue :: enqueue(int val)
{
  enq_s.push(val);
}

int MyQueue :: dequeue()
{
  int tmp;
  if (deq_s.empty())
  {
    while(!enq_s.empty())
    {
        tmp = enq_s.top();
        enq_s.pop();
        deq_s.push(tmp);
    }
  }
    
    if(deq_s.empty())
        return -1; // return some error
        
        
  tmp = deq_s.top();
  deq_s.pop();

  return tmp;
  
}


int main()
{
    MyQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
  
    queue.enqueue(4);
         
    cout << queue.dequeue() << endl;


    
  return 0;
}
