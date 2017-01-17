#include<iostream>
#include <stack>


using namespace std;

class myQueue
{
  private: 
    stack<int> q; 
    stack<int> d;

  public:
    void enqueue(int val);
    int dequeue();
};

void myQueue :: enqueue(int val)
{
  q.push(val);
}

int myQueue :: dequeue()
{
  int tmp;
  
  if(d.empty())
  {
    while(!q.empty())
    {
      tmp = q.top();
      q.pop();
      d.push(tmp);
    }
  }

  tmp = d.top();
  d.pop();

  return tmp;
}

int main()
{
    myQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(4);
    cout << queue.dequeue() << endl;


  return 0;
}