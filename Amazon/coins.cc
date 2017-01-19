#include<iostream>
#include <vector>

using namespace std;

int numberOfWaysToMakeAmount(const int amount, const vector<int>& coins )
{
    vector<int> numberOfWays;
    numberOfWays.reserve(amount);
    numberOfWays[0] = 1;

    for (size_t i = 0; i < coins.size(); ++i)
    {
        for (size_t value = coins[i]; value <= amount; ++value)
        {
            numberOfWays[value] += numberOfWays[value - coins[i]];
        }
    }

    return numberOfWays[amount];
}

int main()
{
    const int amount = 4;
    const vector<int> coins {1,2,3};

    cout << numberOfWaysToMakeAmount(amount,coins) << endl;
    
    return 0;
}