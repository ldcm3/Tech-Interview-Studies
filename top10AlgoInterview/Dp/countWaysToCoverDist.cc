/*
    Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

*/

#include<iostream>
#include<vector>

using namespace std;

int cntCoverDist(int k)
{
    vector<int> dp (k + 1, 0);
    
    dp[0] = 1;
    
    for (int i = 0;  i <= k; ++i)
    {
        for(int j = 1; j <= 3; ++j)     // k=3  [1,1,2,4]
        {                
            if (j <= i)
                dp[i] += dp[i - j];
        }
    }
    
    return dp[k];
}

int main()
{
    cout << cntCoverDist(3) << endl;
    return 0;
}