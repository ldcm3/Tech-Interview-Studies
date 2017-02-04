/*
    Two players take turns at choosing one coin each (from head of a line or end)
    The game ends when all the coins are picked up.
    The player whose coins have the higher total value wins.
    
    Calculate the maximum total value for the starting player.

*/

#include<iostream>
#include<vector>

using namespace std;

// Prototype
int computeMaxHelper(const vector<int>& coins, int s, int e,
                    vector<vector<int>>& maxRevenueForRange);

int maxRevenue(const vector<int>& coins)
{
    vector<vector<int>> maxRevenueForRange(coins.size(),
                                            vector<int>(coins.size(),0));
    
    return computeMaxHelper(coins,0,coins.size()-1, maxRevenueForRange);
}

int computeMaxHelper(const vector<int>& coins, int s, int e,
                    vector<vector<int>>& maxRevenueForRange)
{
    if (s > e)
        return 0; // no coins left
        
    if (maxRevenueForRange[s][e] == 0)
    {
            int maxRevA = coins[s] + min(computeMaxHelper(coins,s + 1,e - 1,maxRevenueForRange),
                                         computeMaxHelper(coins,s + 2, e, maxRevenueForRange));
                                    
            int maxRevB = coins[e] + min(computeMaxHelper(coins,s + 1, e - 1, maxRevenueForRange),
                                          computeMaxHelper(coins,s, e - 2, maxRevenueForRange));
                                          
            maxRevenueForRange[s][e] = max(maxRevA,maxRevB);
    }
    
    return maxRevenueForRange[s][e];
}

int main()
{
    vector<int> coins {10,25,5,1,10,5};
    
    cout << maxRevenue(coins) << endl;
    
    return 0;
}