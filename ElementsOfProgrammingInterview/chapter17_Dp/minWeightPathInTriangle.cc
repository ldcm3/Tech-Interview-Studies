/*
    A sequence of integer arrays in which the nth array consists of n entries naturally
    corresponds to a triangle of numbers.
    
                2
               4 4
              8 5 6
             4 2 6 2
            1 5 2 3 4
            
    Defines a path in the triangle to be a sequence of adjacent entries
    with minimum weight from top to bottom.
    
    In the example : 2,4,5,2,2 == 15
*/

#include<iostream>
#include <algorithm>
#include<vector>

#define INT_MAX 9999

using namespace std;

int minPathWeight(const vector<vector<int>>& triangle)
{
    if (triangle.empty())
        return 0;
        
    int len = triangle.size();
    
    vector<vector<int>> dp (len, vector<int> (triangle[len-1].size(),INT_MAX));
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1;i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    return *min_element(dp[len-1].begin(), dp[len-1].end());
}

int main()
{
    vector<vector<int>> triangle {
                                    {2},
                                    {4,4},
                                    {8,5,6},
                                    {4,2,6,2},
                                    {1,5,2,3,4}
    };
                                    
    cout << minPathWeight(triangle) << endl;
    return 0;
}