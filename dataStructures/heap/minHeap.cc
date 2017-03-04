/*

    Build a priority queue using array
    
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class minHeap
{
    private: 
        vector<int> arr;
        int cap;
        int heap_size;
        
    public:
        // Constructor
        minHeap(int c)
        {
            cap = c;
            heap_size = 0;
            arr.reserve(c);
        }
        
        int parent(int i)
        {
            return (i-1)/2;
        }
        
        int left(int i) return (2*i + 1);
        
        int right(int i) return (2*i + 2);
        
        // extract Root == minimum Element
        int extractMin()
        {
            if(heap_size <= 0)
                return INT_MAX;
            else if(heap_size == 1)
            {
                heap_size--;
                return arr[0];
            }
            else
            {
                int root = arr[0];
                arr[0] = arr[heap_size - 1];
                heap_size--;
                MinHeapfy(0);
                
                return root;
            }
        }
}

int main()
{
    return 0;
}