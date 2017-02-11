/*
    Find the kth largest element in array
    
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int findKthLargest(const vector<int>& A, int k)
{
    priority_queue<int, vector<int> ,greater<int>> min_heap;
    
    for (int a : A)
    {
        min_heap.emplace(a);
        
        if(min_heap.size() > k)
            min_heap.pop();
    }
    
    
    return min_heap.top();
    
}

int main()
{
    vector<int> A {3,2,1,5,4};
    
    cout << findKthLargest(A,3) << endl;
    return 0;
}