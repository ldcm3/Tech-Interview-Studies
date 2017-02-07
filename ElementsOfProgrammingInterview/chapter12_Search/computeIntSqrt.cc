/*
    Takes a nonnegative inteer and return the largest int whose
    square is less than or equal to the given number.
*/

#include<iostream>
#include<vector>

using namespace std;

int calculateSqrt(int n)
{
    int left = 0;
    int right = n;
    int mid;
    
    while (left <= right)
    {
        mid = left + ((right - left)/ 2);
        
        if (mid * mid == n)
            return mid;
        else if(mid*mid > n) // not a valid ans
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return left - 1;
    
}

int main()
{
    return 0;
}