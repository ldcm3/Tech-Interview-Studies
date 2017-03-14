/*
    Find maximal rectangle area in matrix


*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int maximalRectangle(vector<string>& matrix) {

    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
        
    vector<int> h (matrix[0].size(), 0);
    stack<int> s;
    int maximalRect = 0;
    
    for (auto &line : matrix)
    {
        int curMaxArea = 0;
        
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == '1')
                ++h[i];
            else
                h[i] = 0;
            
            // Largest Area so Far
            while (!s.empty() && h[i] < h[s.top()])
            {
                int top = h[s.top()];
                s.pop();
                
                int width = s.empty()? i : i - s.top() - 1;
                curMaxArea = max (curMaxArea, width * top );
            }
            
            
            s.push(i);
        }
        
        while (!s.empty())
        {
            int top = h[s.top()];
            s.pop();
            
            int width = s.empty()? line.size() : line.size() - s.top() - 1;
            curMaxArea = max (curMaxArea, width * top );
        }
        
        maximalRect = max(maximalRect, curMaxArea);
    }
    
    return maximalRect;
}

int main()
{
    
    vector<string> matrix { "10100","10111","11111","10010"};
    
    cout << maximalRectangle(matrix) << endl;
    return 0;
}