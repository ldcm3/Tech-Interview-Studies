/*
    Given a dictionary and a name, checks wether the name is the concatenation
    of a sequence of dictionary words.
    
    Example:
    
    "amanaplanacanal"
    
    dict : {"a","man","plan","canal"}

    Complexity: O(n^3) being n the length of the string
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool isConcatenation(const unordered_set<string>& dict, 
                    const string& str)
{
    vector<vector<bool>> isPossible (str.size() + 1, 
                                    vector<bool> (str.size() + 1, false));
        
    for (int i = 0;i < str.size(); ++i)
    {
        if (dict.find(str.substr(0,i + 1)) != dict.end())
            isPossible[0][i] = true;
        else
        {
            for (int j = 0; j < i; ++j)
            {
                if(isPossible[0][j] && dict.find(str.substr(j + 1, i - j)) != dict.end())
                {
                    isPossible[j + 1][i] = true;
                    isPossible[0][i] = true;
                    break;
                }
            }
        }
    }
    
    for (int i = 0;i < isPossible.size(); ++i)
    {
        cout << "line: " << i << " ";
        for(int  j = 0; j < isPossible[i].size(); ++j)
        {
            cout << isPossible[i][j];
        }
        cout << endl;
    }
    return isPossible[0][str.size() - 1];
}


int main()
{
    unordered_set <string> dict {"a","man","plan","canal"};
    
    string str = "amanaplanacanal";
    
    cout << isConcatenation(dict,str) << endl;
    
    
    
}