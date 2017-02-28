/*


Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 

You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

*/

#include<iostream>
#include<vector>

using namespace std;

int DFS(vector<vector<int>>& dp,const vector<vector<int>>& m,
        int i, int j)
{
    if(dp[i][j] != 0) // it was already visited
        return dp[i][j];
    
    int left=0,right=0,top=0,down=0;
    
    if (i > 0 && m[i-1][j] > m[i][j])
        left = DFS(dp,m,i-1,j);
        
    if (j > 0 && m[i][j-1] > m[i][j])
        left = DFS(dp,m,i,j-1);

    if (i < m.size() - 1 && m[i+1][j] > m[i][j])
        left = DFS(dp,m,i+1,j);
        
    if (j < m[0].size() - 1 && m[i][j + 1] > m[i][j])
        left = DFS(dp,m,i,j+1);
    
    dp[i][j] = max(max(left,right),max(top,down)) + 1;
    return dp[i][j];
    
}
int longestIncreasingPath(const vector<vector<int>>& m)
{
    if(m.size() == 0)
        return 0;
        
    vector<vector<int>> dp(m.size(), vector<int>
                            (m[0].size(), 0));
    int res = -1;
    int curAns;
    
    for(int i = 0; i < m.size(); ++i)
    {
        for(int j = 0; j < m[i].size(); ++j)
        {
            if(dp[i][j] == 0) // not visited yet
                curAns = DFS(dp,m,i,j);
            
            res = max(res,curAns);
        }
    }
    
    return res;
}

int main()
{
    return 0;
}