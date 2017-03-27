/*
    Heap Sort Algorithm for sorting in increasing order:
    1. Build a max heap from the input data.
    2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
    3. Repeat above steps while size of heap is greater than 1.
    
    Heap sort is an in-place algorithm.
    Its typical implementation is not stable, but can be made stable

    Time Complexity of heapify is O(Logn). 
    Time complexity of createAndBuildHeap() is O(n) 
    
    overall time complexity of Heap Sort is O(nLogn).
*/

#include<vector>
#include<iostream>

using namespace std;

void heapify (vector<int>& arr,int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i)
    {
        swap (arr[i],arr[largest]);
        heapify (arr,n,largest);
    }
}


void heapsort(vector<int>& arr, int n)
{
    // Build Heap
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(arr,n,i);
        
    for (int i = n - 1; i >= 0; --i)
    {
        swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
    }
}

int main()
{
    vector<int> test = {1,2,3,4,5};
    
    heapsort(test,5);
    
    for (int x : test)
        cout << x << " ";
        
    cout << endl;
    return 0;
}