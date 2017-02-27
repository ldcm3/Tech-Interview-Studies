#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool hasTwoSum(vector<int> A, int s)
{
    int i = 0 ;
    int j = A.size() - 1;
    
    while(i < j)
    {
        int sum = A[i] + A[j];
        if(sum == s)
            return true;
        else if(sum > s)
            --j;
        else
            ++i;
    }
    
    return false;
}

bool has3Sum(vector<int> A, int s)
{
    sort(A.begin(), A.end());
    
    for(int a : A)
    {
        if(hasTwoSum(A, s - a))
            return true;
    }
    
    return false;
}

int main()
{
    return 0;
}