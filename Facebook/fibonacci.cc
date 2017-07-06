/*

    Find the nth Fibonacci Number
    
    
    Complexity:
    
    O(n) time
    O(1) space
    
    
*/

#include <iostream>

using namespace std;

int fib(int n)
{
    int prevprev = 0;
    int prev = 1;
    int cur;
    
    for(int i = 2; i <= n; ++i)
    {
        cur = prev + prevprev;
        prevprev = prev;
        prev = cur;
    }
    
    return cur;
}

int main()
{
    cout << fib(5) << endl;
    return 0;
}