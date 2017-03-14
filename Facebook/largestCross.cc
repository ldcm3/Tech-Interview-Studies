/*

    Find size of the largest ‘+’ formed by all ones in a binary matrix
    
*/

#include<iostream>
#include<vector>

using namespace std;

int largestCross(vector<vector<char>> matrix)
{
   
    int len = matrix.size();
    int rowLen = rowLen;
    
    vector<vector<int>> right (len, vector<int> (rowLen, 0));
    vector<vector<int>> left (len,  vector<int> (rowLen, 0)); 
    vector<vector<int>> bottom (len, vector<int>(rowLen, 0)); 
    vector<vector<int>> up   (len, vector<int>  (rowLen, 0));
   
    int ans = 0;
    int largest;

    for (int i = 0; i < len; ++i)
    {
        for (int j = 0 ;j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == '1')
            {
                if (i > 0)
                    bottom[i][j] = bottom[i-1][j] + 1;
                else
                    bottom[i][j] = 1;
                
                if (j > 0)
                    right[i][j] = right[i][j-1] + 1;
                else
                    right[i][j] = 1;
            }
        }
    }

    for (int i = len - 1; i >= 0; --i)
    {
        for (int j = matrix[i].size() - 1 ;j >= 0; --j)
        {
            if (matrix[i][j] == '1')
            {
                if (i < len - 1)
                    up[i][j] = up[i+1][j] + 1;
                else
                    up[i][j] = 1;

                if (j < matrix[i].size() - 1)
                    left[i][j] = left[i][j+1] + 1;
                else
                    left[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < len; ++i)
    {
        for (int j = 0 ;j < matrix[i].size(); ++j)
        {
            largest = min(min(left[i][j],right[i][j]),
                          min(bottom[i][j],up[i][j]));
            ans = max(largest,ans);
        }
    }

    return ans - 1;
}

int main()
{
    return 0;
}