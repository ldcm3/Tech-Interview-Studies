/*
  Compute the running median of a sequence
  
  Complexity:
  
  O(logn)
  
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void computeMedian(const vector<int>& A)
{
    // store larger half seen so far
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // store larger smaller seen so far
    priority_queue<int,vector<int>> max_heap;
    
    for (auto x : A)
    {
        // first element to be added
        if (min_heap.empty())
        {
            min_heap.emplace(x);
        }
        else
        {
            if (x >= min_heap.top())
                min_heap.emplace(x);
            else
                max_heap.emplace(x);
        }
        
        if (min_heap.size() > max_heap.size() + 1)
        {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
        else if(max_heap.size() > min_heap.size())
        {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
        
        cout << (min_heap.size() == max_heap.size() ? 
                0.5 * (min_heap.top() + max_heap.top()) : 
                min_heap.top()) << " ";
    }
}

int main()
{
    vector<int> A {1,0,3,5,2,0,1};
    
    computeMedian(A);
    cout << endl;
    return 0;
}