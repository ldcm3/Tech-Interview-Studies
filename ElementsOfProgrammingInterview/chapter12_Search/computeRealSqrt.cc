/*
    Implement a function which takes as input a floating point value and
    returns its square root

*/

// Time Complexity O(log(x/s)) where s is the tolerance


#include<iostream>
#include<vector>

using namespace std;

double findSqrt(double k)
{
    
    double left;
    double right;
    double mid;
    
    if (k < 1.0)
        left = k, right = 1.0;
    else // x >= 1.0
        left = 1.0, right = k;
        

    while(right - left > 0.000001)
    {
        mid = left + (0.5 *(right- left));
        
        if (mid*mid > k)
            right = mid;
        else
            left = mid;
    }
    
    return mid;
}

int main()
{
    cout << findSqrt(6.0) << endl;
    return 0;
}