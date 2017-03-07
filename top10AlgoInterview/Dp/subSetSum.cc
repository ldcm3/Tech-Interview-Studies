/*
Given a set of non-negative integers,
and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

*/

#include<iostream>
#include<vector>

using namespace std;

bool subSetSum(const vector<int>& nums, int sum)
{
    if(nums.size() == 0)
        return false;
    
    vector<bool> dp(sum,false);
    
    dp[0] = true;
    
    for(auto &n : nums)
        dp[n] = true;
    
   
    for(auto &n : nums)
    {
         for(int i = sum; i > 0; --i)
         {
            if(i >= n && dp[i - n])
            {
                dp[i] = true;
            }
        
        }
    }
    
    return dp[sum];
    
}

int main()
{
    vector<int> set = {3, 34, 12, 5, 2};
    cout << subSetSum(set,9) << endl;
    return 0;
}