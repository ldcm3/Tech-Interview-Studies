#include<iostream>
#include<vector>
#include <cstring>

using namespace std;
/*
    Input : 
	S = [1, 2, 3] 
	N = 4

    Return : 4

    Explanation : The 4 possible ways are
    {1, 1, 1, 1}
    {1, 1, 2}
    {2, 2}
    {1, 3}	
    
    
    0 1 2 3 4     // total for one coins.. two coins.. so on 
----------------    
  | 1 0 0 0 0    
1 | 1 1 1 1 1
2 | 1 1 2 2 3
3 | 1 1 2 3 4   

// coins


*/

int coinChange(vector<int> &coins, int N)
{
    int num_ways [N + 1];
    
    memset(num_ways,0,sizeof(num_ways));
    
    num_ways[0] = 1;
    
    
    for (int i = 0; i < coins.size(); i++) // Possible ways with 1 coin.. 2 coins.. so on...
    {
        for (int j = coins[i]; j <= N; j++) 
        {
            num_ways[j] += num_ways[ j - coins[i] ]; // num_ways = num_ways( N - coin[i] ) + num_ways(N)(for i - 1 coins)
        }
    }
    
    return num_ways[N];
}

int main()
{
    vector<int> coins = {1,2,3};
    int N = 4;
    
    cout << coinChange(coins,N) << endl;
}