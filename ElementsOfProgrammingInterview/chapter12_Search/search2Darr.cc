/*
    Giving a 2D sorted array (rows and cols are nondecreasing), implement 
    a function that checks whether a number appears in the array

*/

/*
    Solution : 
    
    - Using a Binary search on each row independently would cost O(mlogn) or O(nlogm)
    - Searching along the entire matrix would cost O(m*n)
    
    
    - Best solution remove at least one col or row per iteration, which means we
    inspect at most m + n - 1 == O(m + n);

*/

#include<iostream>
#include<vector>

using namespace std;

bool searchNum(const vector<vector<int> >& A, int x)
{
    int row = 0;
    int col = A[0].size() - 1;
    
    while(row < A.size() && col >= 0 )
    {
        if (A[row][col] == k)
            return true;
        else if(A[row][col] < x)
            ++row;
        else // A[row][col] > x
            --col;
    }
    
    return false;
}
int main()
{
        
    
    return 0;
}