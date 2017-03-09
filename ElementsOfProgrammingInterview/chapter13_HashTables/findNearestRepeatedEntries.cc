/*
    Find the closest distance between a pair of equal entries.
    
    "No pain no gain"
    
    output: (0,2);
    
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<limits>

using namespace std;

int findNearestRepetition(const vector<string>& paragraph)
{
    unordered_map<string,int> word_latestIdx;
    int nearest_dist = numeric_limits<int> :: max();
    
    for(int i = 0;i < paragraph.size(); ++i)
    {
        auto latest_equal_word = word_latestIdx.find(paragraph[i]);
        
        if(latest_equal_word != word_latestIdx.end())
        {
            nearest_dist = min(nearest_dist,i - latest_equal_word->second);
        }
        
        
        word_latestIdx[paragraph[i]] = i;
    }
    
    return nearest_dist;
}

int main()
{
    
    return 0;
}