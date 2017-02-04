/*
    Return the number of ways in which you can climb stairs, if you cana advance
    1 to k steps at a time.
*/

#include <iostream>
#include <vector>

using namespace std;

int movesToClimb(int n,int k)
{
    vector<int> dp (n + 1,0);
    
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k && j <= i; ++j)
        {
            dp[i] += dp[i - j];
        }
    }
    
    return dp[n];
}

int main()
{

    cout << movesToClimb(4,2) << endl;
    return 0 ;
    
}