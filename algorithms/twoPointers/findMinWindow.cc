/*
Given a set T of characters and a string S,
find the minimum window in S which will contain all the characters in T in complexity O(n).

eg,
S = “ADOBECODEBANC”
T = “ABC”

Minimum window is “BANC”.
    
*/

/*
    Solution Complexity 
    
    O(n)

*/

#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>

#define INT_MAX 9999
using namespace std;

string findMinWind(const string& str, const vector<char>& letters)
{
    unordered_map<char,int> needToFind;
    unordered_map<char,int> hasFound;
    
    int lenNeedToFind = letters.size();
    int lenHasFound = 0;
    int minLenWindow = INT_MAX;
    int minWinHeader, minWinTail;
    int windowLen;
    int header,tail;
        
    for (char ch : letters)
    {
        needToFind[ch]++;
        hasFound.insert(make_pair(ch,0));
    }
    
    header = 0;
    
    for (int i = 0 ; i < str.size(); ++i)
    {
        char ch = str[i];
        
        if (needToFind.find(ch) == needToFind.end())
            continue;
        else // char in NeedtoFind
        {
            hasFound[ch]++;

            if (hasFound[ch] <= needToFind[ch])
                lenHasFound++;
            
            if (lenHasFound == lenNeedToFind) // this is a possible window
            {
                tail = i;
                // increment header
                while( tail > header)
                {
                    if (needToFind.find(str[header]) == needToFind.end()) // we dont need this letter
                        header++;
                    
                    else if(hasFound[str[header]]  > needToFind[str[header]])
                    {
                        hasFound[str[header]]--;
                        header++;

                    }
                    else
                        break;
                               
                }
                
                windowLen = tail - header + 1;
                if (windowLen < minLenWindow)
                {
                    minLenWindow = windowLen;
                    minWinHeader = header;
                    minWinTail = tail;
                }
                

            }
        }
        
    }
    
    return str.substr(minWinHeader, minLenWindow);
  
}

int main()
{
    vector<char> letters {'A','B','C'};
    string str = "ADOBECODEBANC";
    
    cout << findMinWind(str,letters) << endl;
    return 0;
}