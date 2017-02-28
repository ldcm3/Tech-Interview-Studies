#include<iostream>
#include<vector>

using namespace std;

int getMaxTrappedWater(const vector<int>& heights)
{
    
    int i = 0; 
    int j = heights.size() - 1;
    int maxWater = 0;
    
    while(i < j)
    {
        int width = j - i;
        int lower = heights[i] < heights[j] ? heights[i++] : heights[j--];
        
        maxWater = max(lower*width, maxWater);
    }
    
    return maxWater;
}

int main()
{
    return 0;
}