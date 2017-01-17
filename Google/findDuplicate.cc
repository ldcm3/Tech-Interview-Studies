/*
    Write a function which finds an integer that appears more than once in our vector. 
    (If there are multiple duplicates, you only need to find one of them.)
    
    PS: The algo should run in O(nlogn) and O(1) space
*/

#include <iostream>
#include <vector>

using namespace std;

unsigned int findRepeat(const vector<int>& A)
{
    unsigned int floor = 1;
    unsigned int ceiling = A.size() - 1;
    unsigned int mid, lowerRangeFloor, lowerRangeCeiling, upperRangeFloor, upperRangeCeiling;
    
    while (floor < ceiling) // Binary search with the possible answers
    {
        mid = floor + ((ceiling - floor)/2) ;
        lowerRangeFloor = floor;
        lowerRangeCeiling = mid;
        upperRangeFloor = mid + 1;
        upperRangeCeiling = ceiling;

        unsigned int itemsInLowerRange = 0;

       for (unsigned int item : A) {
            // is it in the lower range?
            if (item >= lowerRangeFloor && item <= lowerRangeCeiling) {
                ++itemsInLowerRange;
            }
        }


        unsigned int distinctPossibleIntegersInLowerRange = lowerRangeCeiling - lowerRangeFloor + 1;

        if (itemsInLowerRange > distinctPossibleIntegersInLowerRange) {
            // there must be a duplicate in the lower range
            // so use the same approach iteratively on that range
            floor   = lowerRangeFloor;
            ceiling = lowerRangeCeiling;
        }
        else {
            // there must be a duplicate in the upper range
            // so use the same approach iteratively on that range
            floor   = upperRangeFloor;
            ceiling = upperRangeCeiling;
        }
        
    }

    return floor;
    
}


int main()
{
    
    const vector< int> vec {3,2,1,5,4,6,2};
    
    cout << findRepeat(vec) << endl;
    
    return 0;
}