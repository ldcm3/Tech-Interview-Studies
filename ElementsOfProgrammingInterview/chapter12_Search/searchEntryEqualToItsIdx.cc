/*
    Return an index of a number which value is equal its index, 
    in a sorted array with distinct integers

    Example : {-2,0,2,3,6,7,9}
    
    Should return 2 or 3
    
    
    
*/

#include<iostream>
#include<vector>

using namespace std;

int searchEntryEqualToItsIdx(const vector<int>& A)
{
    int left = 0;
    int right = A.size() - 1;
    int mid; 
    
    while(left < right)
    {
        mid = left + (right - left)/2;
        
        if (A[mid] == mid)
            return mid;
        else if(mid > A[mid])
            left = mid + 1;
        else            // A[mid] > mid
            right = mid - 1;
    }
    
    return -1;
    
}

int main()
{
    vector<int> A {-2,0,2,3,6,7,9};
    
    cout << searchEntryEqualToItsIdx(A) << endl;
    return 0;
}