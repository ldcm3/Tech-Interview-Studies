/*

Given a dictionary D and two strings, determine if s produces t, and output the
length of the shoetest production sequence.

- s produces t if there exist a sequence of strings from the dictionary such that
the first string is s and the last is t, and adjancent strings have the same length
and differ exactly one character

D: {bat,cot,dog,dag,dot,cat}, s = cat and t = dog
output: {cat,cot,dot,dog}


    SOLUTION:
    
    
    Time Complexity O(d + d^2)
*/

#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

struct stringWithDistance
{
    string str;
    int dist;
};

int leastStepsToTransform(unordered_set<string> D, const string& s,
                            const string& e)
{
    // BFS    
    queue<stringWithDistance> q;
    q.emplace(stringWithDistance{s,0});
    D.erase(s);
    
    while(!q.empty())
    {
        stringWithDistance cur = q.front();
        q.pop();
        
        if (cur.str == e)
            return cur.dist;  // number of steps to reach 
            
        string curStr = cur.str;
        // Tries all possibles transformations
        for(int i = 0; i < curStr.size(); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                curStr[i] = 'a' + j;
                
                if (D.find(curStr) != D.end())
                {
                    q.emplace(stringWithDistance{curStr,cur.dist + 1});
                    D.erase(cur.str);
                }
            }
            curStr = cur.str;
        }
    }
    
    // Cannot find
    return -1;
    
}

int main()
{
    unordered_set<string> dict {"bat","cot","dog","dag","dot","cat"};
    cout << leastStepsToTransform(dict,"cat","dog") << endl;
    return 0;
}