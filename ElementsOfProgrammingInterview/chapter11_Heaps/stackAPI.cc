/*
    Implement a stack API using a heap

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ValueWithRank
{
    int value , rank;
    
    bool operator<(const ValueWithRank& that) const
    {
        return rank < that.rank;
    }
};


class Stack {
    
    private:
        int timestamp = 0;
        priority_queue<ValueWithRank, vector<ValueWithRank> > max_heap;
        
    public:
        void push(int x)
        {
            max_heap.emplace(ValueWithRank{x,timestamp});
            ++timestamp;
        }
        
        int peek() const
        {
            return max_heap.top().value;   
        }
        
        int pop()
        {
            int val; 
            
            if (!max_heap.empty())
            {
                val = max_heap.top().value;
                max_heap.pop();
            }
            
            return val;
           
        }
    
};


int main()
{
    
    
    return 0;
}