/*
    Find the Kth Largest number in an unsorted array.
    
    Solution : 
    
    - O(nlogk) time
    - O(logk) space
    
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct comparator{
    bool operator()(int a,int b)
    {
        return a > b;
    }
};
int kThLargest(const vector<int>& A, int k)
{
    if(A.size() == 0)
        return 0;
    
    priority_queue <int, vector<int>,comparator> min_heap;
    
    int i = 0;
    
    while(i < k)
        min_heap.push(A[i++]);
        
    for(i; i < A.size(); ++i)
    {
        min_heap.push(A[i]);
        min_heap.pop();
    }
    
    return min_heap.top();
    
}

int main()
{
    vector<int> A {5,4,2,3,1,6};
    
    cout << kThLargest(A,2) << endl;
    return 0;
}