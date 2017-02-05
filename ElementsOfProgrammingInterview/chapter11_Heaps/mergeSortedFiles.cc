/*
    You are given 500 files, each containing stick trade information for a company.
    Each trade is enconded by a line in a format : TIMESTAMP, COMPANY , TRADE
    
    You have to create a single file containing all the trades from the 500 files, 
    sorted in order of increasing trade times.
    
    The individual files are of the order of 5-100 Megabytes. 
    The combined file will be of the order of 5 Gigabytes.
    
    Write a program that takes as input a set of sorted sequences and compute
    the union of these sequences as a sorted sequence.
    
    input : {3,5,7}, {0,6}, {0,6,28}
    
    output: {0,0,3,5,6,6,7,28}
 
    
    #### Solution ####
    
    k : the number of files
    
    The min-heap will insert and extract using O(logk)
    Hence, we can do the merge in O(nlogk) 
    
    The required space is O(k)

*/

#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>

using namespace std;

struct IteratorCurAndEnd
{
    bool operator>(const IteratorCurAndEnd& that) const {
        return *current > *that.current;
    }
    
    vector<int> :: const_iterator current;
    vector<int> :: const_iterator end;
};


vector<int> mergeSortedArrays(const vector<vector<int>>& sortedArrays)
{
    priority_queue<IteratorCurAndEnd, 
                    vector<IteratorCurAndEnd>, 
                    greater<IteratorCurAndEnd>>
                    min_heap;    
    
    for (const vector<int>& sorted_array : sortedArrays)
    {
        if(!sorted_array.empty())
        {
            min_heap.emplace(
                IteratorCurAndEnd{sorted_array.cbegin(), sorted_array.cend()});
        }
    }
    
    vector<int> result;
    
    while (!min_heap.empty())
    {
        auto smallest_array = min_heap.top();
        min_heap.pop();
        
        if (smallest_array.current != smallest_array.end)
        {
            result.emplace_back(*smallest_array.current);
            min_heap.emplace(IteratorCurAndEnd{next(smallest_array.current),
                                                smallest_array.end});
        }
    }
    
    return result;
}

int main()
{
    return 0;
}