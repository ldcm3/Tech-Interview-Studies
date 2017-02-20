/*
 Given a sequence, find the length of the longest palindromic subsequence in it. 
 For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as
 “BABCBAB” is the longest palindromic subseuqnce in it. 
 “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, 
 but not the longest ones.   
 
 Obs: Longest subsequence is different from longest substring
 
*/

#include<iostream>
#include<vector>

using namespace std;

int longestPal(const string& str)
{
    vector<vector<int>> dp (str.size() + 1,
                            vector<int> (str.size() + 1, 1));
                            
    for (int len = 2; len <= str.size(); ++len)
    {
        for (int i = 0; i < str.size() - len + 1; i++)
        {
            int j = i + len - 1;
            
            if (str[i] == str[j])
            {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
                dp[i][j] = max (dp[i][j - 1],
                                    dp[i + 1][j]);
        }
    }
    
    return dp[0][str.size() - 1];
}

int main()
{
    cout << longestPal("eeegeeksforskeeggeeks") << endl;
    return 0;
}

// eeegeeksforskeeggeeks