/*
    Find the length of the longest non decreasing subsequence.
*/

#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int longestNonDecreasingSubSequence(const vector<int>& A)
{
    vector<int> dp(A.size(), 1);
    
    for (int i = 1; i < A.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (A[j] >= A[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(),dp.end());
}

int main()
{
    vector<int> A {0,8,4,12,2,10,6,14,1,9};
    
    cout << longestNonDecreasingSubSequence(A) << endl;
    return 0;
}