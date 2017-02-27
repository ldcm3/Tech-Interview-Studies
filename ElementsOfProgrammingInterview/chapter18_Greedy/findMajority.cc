/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.



*/

#include<iostream>
#include<vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    
    int cur = nums[0];
    int cnt = 1;
    
    for(int i = 1; i < nums.size(); ++i)
    {
        if(cnt == 0)
        {
            cur = nums[i];
        }
        
        if (nums[i] == cur)
        {
            ++cnt;
        }
        else
        {
            --cnt;
        }
    }
    
    return cur;
}

int main()
{
    return 0;   
}

