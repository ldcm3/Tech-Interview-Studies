#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;



class Solution {
public:
    unordered_map<string,vector<string> > dp;
    
    vector<string> combine (string word, vector<string> prev)
    {
        for (int i = 0; i < prev.size(); ++i)
        {
            prev[i] += " " + word;
        }
        
        return prev;
    }
    
    vector<string> helper(string s, unordered_set<string>& dic) {
        if (dp.count(s))
            return dp[s];
        
        vector<string> res;
        
        if (dic.count(s))
            res.push_back(s);
        
        for (int i = 1; i < s.size(); ++i)
        {
            string word = s.substr(i);
            if (dic.count(word))
            {
                string rem = s.substr(0,i);
                vector<string> prev = combine(word,helper(rem,dic));
                res.insert(res.end(),prev.begin(), prev.end());
            }
        }
        
        dp[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& dic) {
        unordered_set<string> ss;
        for (string str : dic)
            ss.emplace(str);
        
        return helper(s,ss);
    }

};

int main()
{
    
    return 0;
}