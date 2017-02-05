/*
    Given a max-heap, represented as an array A, design an algo that computes
    the k largest elements stored without modifying the structure.
    
    Complexity: 
    
    O(klogk) time and O(k) space, being k the number of largest elements we are 
    looking for.
    
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std; 
 
class HeapEntry
{
    public:
         int idx,value;
        
};

class Comp{
    public:
       bool operator() (const HeapEntry& a, const HeapEntry& b)
        {
            return a.value < b.value;
        }
};

vector<int> kLargestInBinaryHeap(const vector<int>& A, int k)
{
    if (k <= 0)
        return {};
    
   
    priority_queue<HeapEntry, vector<HeapEntry>, Comp  > candidate_max_heap;
                                
    // largest element in A is at index 0
    candidate_max_heap.emplace(HeapEntry{0,A[0]});
    
    vector<int> result;

    
    for (int i = 0; i < k; ++i)
    {
        int candidate_idx = candidate_max_heap.top().idx;
        int candidate_value = candidate_max_heap.top().value;
        candidate_max_heap.pop();
        
        result.emplace_back(candidate_value);
        
        int left = 2*candidate_idx + 1;
        int right = 2*candidate_idx + 2;
        
        if (left < A.size())
        {
            candidate_max_heap.emplace(HeapEntry{
                left, A[left]
            });
            
        }
        
        if (right < A.size())
        {
            candidate_max_heap.emplace(HeapEntry{
                right, A[right]
            });
        }
    }
                                
    
    return result;
}

int main()
{
    vector<int> maxHeap {561,314,401,28,156,359,271,11,3};
    
    vector<int> ans = kLargestInBinaryHeap(maxHeap,4);
    
    for (auto x : ans)
    {
        cout << x << " ";
    }
    
    cout << endl;
    
    return 0;
}