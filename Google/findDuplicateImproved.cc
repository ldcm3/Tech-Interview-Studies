/*
    Write a function which finds an integer that appears more than once in our vector. 
    (If there are multiple duplicates, you only need to find one of them.)
    
    PS: The algo should run in O(n) and O(1) space
*/


#include <iostream>
#include <vector>

using namespace std;

unsigned int findDuplicate(const vector<unsigned int>& A)
{
    const unsigned int n = A.size() - 1;
    
    // If there is at least one duplicate, there is at least one cycle
    // Find Cycle
    unsigned int positionInCycle = n  + 1; // last idx (extra space in vector == head)    

    for (unsigned int i = 0; i < n; ++i)
    {
        positionInCycle = A[positionInCycle - 1];
    }
    
    // Determine Lenght of Cycle
    unsigned int rememberedPositionInCycle = positionInCycle;
    
    positionInCycle = A[positionInCycle - 1]; // one position ahead
    unsigned int cycleLen = 1;
    
    while(positionInCycle != rememberedPositionInCycle)
    {
        positionInCycle = A[positionInCycle - 1];
        ++cycleLen;
    }
    
    // First node of the cycle
    unsigned int pointerStart = n + 1;
    unsigned int pointerAhead = n + 1;
    
    for (int i = 0; i < cycleLen; ++i )
    {
        pointerAhead = A[pointerAhead - 1];
    }
    
    // advance both pointers until first node of cycle
    while (pointerAhead != pointerStart)
    {
        pointerAhead = A[pointerAhead - 1];
        pointerStart = A[pointerStart - 1];
    }
    
    return A[pointerAhead];
}

int main()
{
    
    const vector<unsigned int> vec {3,5,1,2,4,6,2};
    
    cout << findDuplicate(vec) << endl;
    return 0;
}