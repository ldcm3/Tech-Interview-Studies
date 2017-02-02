/*
    Find the maximum sum over all the subarrays of a given array of ints;   
    
    Ex:
    
    [904,40,523,12,-335,-385,-124,481,-31]
    
    maxSum = 1479

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMaxSumSubArray(const vector<int>& A)
{
    int minSum = 0;
    int maxSum = 0;
    int sum = 0;
    
    for (const int& num : A)
    {
        sum += num;
        
        minSum = min(minSum,sum);
        maxSum = max(maxSum,sum - minSum);
    }
    
    return maxSum;
}

int main()
{
    const vector<int> A {904,40,523,12,-335,-385,-124,481,-31};
    
    cout << findMaxSumSubArray(A) << endl;
    return 0;
}