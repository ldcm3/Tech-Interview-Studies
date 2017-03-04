/*
     Your task is to find a contiguous subarray that has a sum equal to s,
     and return an array containing the two integers that represent its inclusive bounds. 
     If there are several possible answers, return the one with the smallest left bound.
     If there are no answers, return [-1].
    
    The array is not sorted

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> findSubArraySum(const vector<int>& arr, int s)
{
    int count = 0;
    
    for(int i = 0, j = 0; j < arr.size(); ++j)
    {
        count += arr[j];
        
        while(i < j && count > s)
            count -= arr[i++];
        
        if(count == s)
            return {i+1,j+1};
        
    }
    
    return {-1};
}

int main()
{
    
    return 0;
}