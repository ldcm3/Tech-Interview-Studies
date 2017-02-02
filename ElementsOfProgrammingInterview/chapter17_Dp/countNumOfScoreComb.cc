/*

    Take a score, and individual score values and return the number 
    of possible combinations of plays that resul in the finalScore
    
*/

#include<iostream>
#include<vector>

using namespace std;

int numOfPossibleComb(const int& finalScore, const vector<int>& individualValues)
{
    vector<int> numOfCombinationsForScore (finalScore + 1, 0);
        
    numOfCombinationsForScore[0] = 1; // one way to reach 0
    
    for (const int& score : individualValues)
    {
        for (int i = score; i <= finalScore; ++i)
        {
            numOfCombinationsForScore[i] += numOfCombinationsForScore[i - score];
        }
    }
    
    return numOfCombinationsForScore[finalScore];    
}

int main()
{
    vector<int> A {2,3,7};
    cout << numOfPossibleComb(12,A) << endl;
    return 0;
}