#include<iostream>
#include<vector>

using namespace std;

int findUnique(const vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    
    while(low < high) {
        
        mid = low + (high - low)/2;
        
        if( nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];
        else if(nums[mid] == nums[mid + 1] && mid % 2 == 0)
            low = mid + 1;
        else if(nums[mid] == nums[mid - 1] && mid % 2 == 1)
            low = mid + 1;
        else
            high = mid - 1;
    }      
    
    return nums[low];
}

 

int main()
{
    vector<int> test = {0,1,1,2,2,3,3};
    cout << findUnique(test) << endl;
    return 0;
}