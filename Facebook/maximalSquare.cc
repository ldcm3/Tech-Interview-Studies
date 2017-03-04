

#include<iostream>
#include<vector>

using namespace std;


int customMin(int a, int b, int c)
{
    return min(a,min(b,c));
}
int maximalSquareArea(const vector<vector<int>>& m)
{
    if(m.size() == 0 )
        return 0;
        
    vector<vector<int>> dp (m.size() + 1, vector<int>
                            (m[0].size() + 1, 0));
    
    int largestWidth = -1;
    
    for(int i = 0, x = i + 1 ;i < m.size(); ++i)
    {
        for (int j = 0, y = j + 1 ; j < m[i].size(); ++j)
        {
            if(m[i][j] != 0)
            {
                dp[x][y] = 1 + customMin(dp[x-1][y],        
                                        dp[x][y-1],
                                        dp[x-1][y-1]);        
            }
            
            largestWidth = max(largestWidth,dp[x][y]);
        }
    }
    
    return largestWidth*largestWidth;
}


int main()
{
    return 0;
}