/*

    Count the total number of ways to traverse an a 2D array (m*n) from top left
    to bottom-right.
    
    All moves must either go to right or down.
    
*/

#include<iostream>
#include<vector>

using namespace std;

int countTraverseMat(int m, int n)
{
    vector<vector<int>> mat (m + 1, vector<int>(n + 1,0));
    
    mat[0][1] = 1; // starting point;
    
    for(int i = 1; i <= m; ++i) 
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        } 
    }
    
    return mat[m][n];
}

int main()
{
    cout << countTraverseMat(3,4) << endl;
    return 0;
}