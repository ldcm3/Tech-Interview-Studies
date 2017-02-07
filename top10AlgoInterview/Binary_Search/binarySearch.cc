/*
    Binary search
    
    {2, 3, 4, 10, 40};
    x = 10
    
    Complexity: 
    
    T(n) = T(n/2) + c  per iteration  --->   O(logn)
*/

#include<iostream>
#include<vector>

using namespace std;

int findIdx (const vector<int>& A, int x)
{
    int s = 0; 
    int e = A.size() - 1;
    int mid;

    while(s <= e)
    {
        mid = s + ((e - s)/2);

        if (A[mid] == x)
            return mid;
        else if (A[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;
    }
    
        return -1;
}

int main()
{
    vector<int> A {2,3,4,10,40};
    cout << findIdx(A,10) << endl;
    return 0;
}