/*
    An array is said to be k-increasing-decreasing if elements repeatdly 
    increase up to a certain index after which they decrease, then again increase, 
    a total of k-times.
    
    Ex: {57,131,493,294,221,339,418,452,442,190}
        A 4-increasing-decreasing arr
        
    Design an efficient algo for sorting a k-increasing-decreasing arr
    
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> mergeSortedArrays(const vector<vector<int> >& sorted_arrays);


vector<int> sortKIncAndDecArr(const vector<int>& A)
{
    // Decompose A in sorted_arrays
    vector<vector<int>> sorted_arrays;
    
    typedef enum {INCREASING, DECREASING} SubarrayType;
    
    SubarrayType subarray_type = INCREASING;
    
    int start_idx = 0;
    
    for (int i = 1; i <= A.size(); ++i)
    {
        if (i == A.size() || 
            (A[i - 1] < A[i] && subarray_type == DECREASING) ||
            (A[i - 1] >= A[i] && subarray_type == INCREASING))
        {
            if (subarray_type == INCREASING)
            {
                sorted_arrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
            }
            else
            {
                sorted_arrays.emplace_back(A.crbegin() + A.size() - i,
                                         A.crbegin() + A.size() - start_idx);
            }
            
            start_idx = i;
            subarray_type = (subarray_type == INCREASING? DECREASING : INCREASING);
        }
    }
    
    return mergeSortedArrays(sorted_arrays);
    
}

vector<int> mergeSortedArrays(const vector<vector<int>>& sorted_arrays)
{
    struct IteratorCurAndEnd
    {
        bool operator> (const IteratorCurAndEnd& that) const {
            return *cur > *that.cur;
        }
        
        vector<int> :: const_iterator cur;
        vector<int> :: const_iterator end;
    };
    
    vector<int> ans;
    
    priority_queue<IteratorCurAndEnd, vector<IteratorCurAndEnd>,
                    greater<IteratorCurAndEnd> > min_heap;
                    
    for (const vector<int>& sorted_array : sorted_arrays)
    {
        if (!sorted_array.empty())
        {
            min_heap.emplace(IteratorCurAndEnd{
                sorted_array.cbegin(), sorted_array.cend()});
        }
    }
    
    while (!min_heap.empty())
    {
        auto smallest_array = min_heap.top();
        min_heap.pop();
        
        if (smallest_array.cur != smallest_array.end)
        {
            ans.emplace_back(*smallest_array.cur);
            min_heap.emplace(IteratorCurAndEnd{
                next(smallest_array.cur), smallest_array.end});
        }
    }
    
    return ans;
    
};


int main()
{
    vector<int> A {57,131,493,294,221,339,418,452,442,190};
    
    vector<int> ans = sortKIncAndDecArr(A);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}