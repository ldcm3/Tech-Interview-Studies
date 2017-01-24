/*

We have a vector of integers, where:

The integers are in the range 1..n
The vector has a length of n+1
It follows that our vector has at least one integer which appears at least twice.
But it may have several duplicates, and each duplicate may appear more than twice.

*/

#include <iostream>
#include <vector>

using namespace std;


unsigned int findRepeat(const vector<unsigned int>& theVector)
{
    unsigned int floor = 1;
    unsigned int ceiling = theVector.size() - 1;

    while (floor < ceiling)
    {
        unsigned int mid = floor + ((ceiling - floor) / 2);
        unsigned int lowerFloor = floor;
        unsigned int lowerCeiling = mid;
        unsigned int upperFloor = mid + 1;
        unsigned int upperCeiling = ceiling;
        
        unsigned int itemsInLowerRange = 0;
        
        for (auto x : theVector)
        {
            if (x >= lowerFloor && x <= lowerCeiling)
                ++itemsInLowerRange;
        }
        
        unsigned int distinctPossibleIntegersInLowerRange = lowerCeiling - lowerFloor + 1;
        
        if (itemsInLowerRange > distinctPossibleIntegersInLowerRange) // duplicate is in the lowerRange
        {
            ceiling = lowerCeiling;
        }
        else
        {
            floor =  upperFloor;
        }
    
    }
    
    return floor;
}

int main()
{
    const vector<unsigned int> vec {3,1,1,2};
    
    cout << findRepeat(vec) << endl;
    
}