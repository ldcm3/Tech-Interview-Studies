/*
    Write a program that takes as input a very long sequence of numbers and
    prints the numbers in sorted order. Each number it at most k away from its
    correctly sorted position.
    
    Example:
    
    input: {3,-1,2,6,4,5,8} k = 2
    
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void sortApproximatelySortedData(const vector<int>& A,int k)
{
    priority_queue<int,vector<int>, greater<int> > min_heap;
    
    // Add the first k elements into the heap
    int i ;
    for (i = 0 ; i < A.size() && i < k; ++i)
    {
        min_heap.emplace(A[i]);
    }
    
    // for every new element, add it to the heap and extract smallest
    while(i < A.size())
    {
        min_heap.emplace(A[i]);
        cout << min_heap.top() << " ";
        ++i;
        min_heap.pop();
    }
    
    while(!min_heap.empty())
    {
        cout << min_heap.top() <<  " ";
        min_heap.pop();
    }
    
}

int main()
{
    vector<int> A {3,-1,2,6,4,5,8} ;
    sortApproximatelySortedData(A,3);
    return 0 ;
}