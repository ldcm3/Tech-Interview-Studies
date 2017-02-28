/*

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.


For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


*/

#include<iostream>
#include<vector>

using namespace std;

int trappedWater(const vector<int>& heights)
{
    int i = 0;
    int j = heights.size() - 1;
    
    int level = -1;
    int lower;
    int water = 0;
    
    while(i < j)
    {
        lower = heights[i] < heights[j] ? heights[i++] : heights[j--];
        level = max(lower,level);
        water += (level - lower);
    }
    
    return water;
    
}

int main()
{
    
    vector<int> h  {0,1,0,2,1,0,1,3,2,1,2,1};
    
    cout << trappedWater(h) << endl;
    return 0;
    
}