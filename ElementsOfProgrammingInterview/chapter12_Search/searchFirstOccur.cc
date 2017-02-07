/*
  Find First occurrence of number in an array  

*/

#include<iostream>
#include<vector>

using namespace std;

int findFirstOccur(const vector<int>& A, int k)
{
    int left = 0;
    int right = A.size() - 1;
    int mid, res;
    
    while(left <= right)
    {
        mid = left + ((right - left)/2) ;
        
        if (A[mid] == k)
        {
            res = mid ; // nothing to the right of mid can be the first occur
            right = mid - 1;
        }
        else if(A[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return res;
    
    
}

int main()
{
    vector<int> A {-14,-10,2,108,108,243,285,285,285,401};
    cout << findFirstOccur(A,285) << endl;
    return 0;
}