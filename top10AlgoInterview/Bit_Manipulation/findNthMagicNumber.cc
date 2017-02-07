/*
  Find magic number
  
  A magic number is defined as a number which can be expressed as a power of 5 
  or sum of unique powers of 5. 
  First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….
  
  Solution: 
  
   001, 010, 011, 100, 101, 110 etc, where 001 is 0*pow(5,3) + 0*pow(5,2) + 1*pow(5,1). 

*/

#include<iostream>

using namespace std;

#define INT_SIZE 32

int findKMagicNumber(int k)
{
    int ans = 0;
    int pow = 1;
    
    for(int i = 0; i < INT_SIZE - 1; ++i)
    {
        pow *= 5;
        
        if(k & (1 << i))
            ans +=  pow;
    }

    return ans;
}

int main()
{
    cout << findKMagicNumber(4) << endl;
    return 0;
}