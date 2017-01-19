#include <iostream> 
#include <vector>
#include <limits>

using namespace std;

int getMaxProfit(const vector<int>& stocks)
{
    int greaterStockSoFar = numeric_limits<int> :: min();
    int betterProfit = numeric_limits<int> :: min();
    
    for (int i = stocks.size() - 1; i >= 0; --i) // size_t is a unsigned and does not allow negative
    {
        greaterStockSoFar = max(stocks[i],greaterStockSoFar);
        betterProfit = max(betterProfit, greaterStockSoFar - stocks[i]);
    }
    
    return betterProfit;
}

int main()
{
    const vector<int> stocks {10, 7, 5, 8, 11, 9};
    
    cout << getMaxProfit(stocks) << endl;
    return 0;
}