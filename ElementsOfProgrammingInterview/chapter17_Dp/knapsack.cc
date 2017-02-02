/*
    Select a subset of items with the max optimum values according 
    a specified weight capacity
*/

#include<iostream>
#include<vector>

using namespace std;

struct Item
{
    int weight, value;
};

int optimumProfit(const vector<Item>&items,int capacity)
{
    vector<int> optimumCap (capacity + 1, 0);
    
    for (const auto& item : items)
    {
        for (int w = item.weight; w <= capacity; ++w)
        {
            optimumCap[w] = max(optimumCap[w], optimumCap[w - item.weight] + item.value);
        }
    }
    
    return optimumCap[capacity];
}

int main()
{
    Item itemA {5,60};
    Item itemB {3,50};
    Item itemC {4,70};
    Item itemD {2,30};
    
    vector<Item> items {itemA,itemB,itemC,itemD};
    
    cout << optimumProfit(items,5) << endl;
    
    return 0 ;
}