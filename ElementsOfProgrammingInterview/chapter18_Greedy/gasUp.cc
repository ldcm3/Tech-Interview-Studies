/*
    A number of cities are arranged on a circular road..
    You need to visit all of them and come back to the starting city.
    A certain amount of gas is available at each city.
    The amount of gas summed up over all cities is equal to the amount of gas required
    to go around the road once.
    
    An Ample city is a city where you can start with an empty tank, refill at it,
    then travel through all the remaining cities without running out of gas at any point.
    
    Find an ample city in a single pass.
*/

#include<iostream>
#include<vector>

using namespace std;

const int kMPG = 20;

size_t findAmpleCity(const vector<int>& gallons,
                    const vector<int>& distances)
{
    int remaining_gallons = 0;
    struct CityAndRemainingGas{
        int city = 0;
        int remaining_gallons = 0;
    };
    
    CityAndRemainingGas lowestRemainingGasPossible;
    
    for(int i = 1; i < gallons.size(); ++i)
    {
        remaining_gallons += gallons[i - 1] - distances[i-1] / kMPG;
        
        if (remaining_gallons < lowestRemainingGasPossible)
        {
            lowestRemainingGasPossible = {i,remaining_gallons};
        }
    }
    
    return lowestRemainingGasPossible.city;
    
}

int main()
{
    
    return 0;
}