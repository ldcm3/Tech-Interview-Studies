/*


    Given a string s, partition s such that every substring of the partition is a palindrome.

    
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isPal(string s)
{
    int i = 0;
    int j = s.size() - 1;
    
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    
    return true;
}

void helper (vector<string> pal, vector<vector<string> >& ans, int idx, string s)
{
    if (idx >= s.size())
    {
        if (pal.size() != 0)
        {
            ans.push_back(pal);
        }
        
        return;
    }
    
    for (int i = idx; i < s.size(); ++i)
    {
        if (isPal(s.substr(idx,i - idx + 1)))
        {
            pal.push_back(s.substr(idx,i - idx + 1));
            helper (pal,ans,i + 1,s);
            pal.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    
    vector<string> pal;
    vector<vector<string> > ans;
    helper (pal,ans,0,s);
    
    return ans;
}


int main()
{
    
    return 0;
}