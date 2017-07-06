#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void reverseArr(vector<int>& nums)
{
    if (nums.size() == 0)
        return;
        
    k %= nums.size();
    
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(),nums.begin() + k);
    reverse(nums.begin() + k, nums.end);
}

int main()
{
    
    return 0;
}