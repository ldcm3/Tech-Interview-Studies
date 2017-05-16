/*

Given an array of numbers arr, determine whether arr can be divided into two subsets
for which the sum of elements in both subsets is the same.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool subsetSum(std::vector<int> arr) {

    int totalSum = 0;

    for (int i = 0;i < arr.size(); ++i)
        totalSum += arr[i];

    if (totalSum % 2 != 0)
        return false;
    
    int n = totalSum / 2;
    
    sort(arr.begin(),arr.end());
    
    vector<vector<bool> > dp (arr.size() + 1,vector<bool> (n + 1, false));

    // Initialize
    for (int i = 0; i <= arr.size(); ++i)
        dp[i][0] = true;
    
    for(int i = 0; i < arr.size(); ++i)
    {
        for (int j = arr[i]; j <= n; ++j)
        {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
        }
    }
    
    return dp[arr.size()][n];
}

int main()
{
    vector<int> test = {3,5,16,8};
    cout << subsetSum(test) << endl;
    return 0;
}