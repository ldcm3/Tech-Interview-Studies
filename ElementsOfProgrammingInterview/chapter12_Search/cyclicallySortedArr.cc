/*
    Find the position of the smallest element in a cyclically sorted array, 
    assuming all elements are distinct.
    
    {378,478,550,631,103,203,220,234,279,368}
    
    should return 4
*/


#include<iostream>
#include<vector>

using namespace std;

int findCilPos(const vector<int>& A)
{
    int left = 0;
    int right = A.size() - 1;
    int mid;
    
    while(left < right) // all elements are distinct
    {
        mid = left + ((right - left)/2);
       
        if (A[mid] > A[right])
            left = mid + 1;
        else                    // A[mid] < A[right]
            right = mid ;
    }
    
    return left;
}
int main()
{
    return 0;
}