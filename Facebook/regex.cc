/*
    Implement regex
    
    - '.' match any character
    - '*' match 0 or more occurences of previous char

*/

#include<iostream>
#include<vector>

using namespace std;

bool regularExpressionMatching(string s, string p)
{
    vector<vector<bool>> dp(s.size() + 1, vector<bool>
                            (p.size() + 1, false));
                    
    
    dp[0][0] = true;
    
    // for empty pattern string all initialization is false
    
    // for empty string we have to check for cases such as a*b*c* which might match empty strs
    for(int i = 0, y = i+1; i < p.size(); ++i, ++y)
    {
        if (p[i] == '*')
            dp[0][y] = dp[0][y - 2];
        // else is false
    }
    
    for (int i = 0, x = 1; i < s.size(); ++i,++x)
    {
        for(int j = 0, y = 1;j < p.size(); ++j,++y)
        {
            if (s[i] == p[j] || p[j] == '.')
            {
                dp[x][y] = dp[x - 1][y - 1];
            }
            else if(p[j] == '*')
            {
                if (p[j - 1] == s[i])
                {
                    dp[x][y] = dp[x][y - 2] || dp[x - 1][y]; // match 0 occurences or 
                                                            //  1 or more characters from str
                }
                else
                    dp[x][y] = dp[x][y-2];
            }
            else
                dp[x][y] = false;
        }
    }
    
    return dp[s.size()][p.size()];

}

int main()
{
    string input = "ab";
    string pattern = ".*..c*";
    
    cout << regularExpressionMatching(input,pattern) << endl;
    return 0;
}