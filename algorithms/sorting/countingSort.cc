#include<iostream>
#include <vector>

using namespace std;

vector<size_t> sortedScores (const vector<int>& unsortedScores, const int highestPossibleScore)
{
    vector<size_t> countScores(highestPossibleScore + 1);
    vector<size_t> sortedScores(unsortedScores.size());
    
    for (int score: unsortedScores)
        ++sortedScores[score];
    
    size_t currentSortedIdx = 0;
    
    for (size_t i = 0; i < countScores.size(); ++i)
    {
        for (size_t j = 0; j < countScores[i]; ++j)
        {
            sortedScores[currentSortedIdx] = i;
            ++currentSortedIdx;
        }
    }
    
    return sortedScores;
    
}

int main()
{
    return 0;
}