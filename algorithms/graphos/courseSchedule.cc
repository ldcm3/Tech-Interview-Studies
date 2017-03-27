/*

    There are a total of n courses you have to take, labeled from 0 to n - 1.

    Some courses may have prerequisites, for example to take course 0 you have
    to first take course 1, which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool helper (int node,vector<int>& status, unordered_map<int,vector<int> >& g)
{
    status[node] = 1; // current being visited
    
    for (auto it = g[node].begin(); it != g[node].end(); ++it)
    {
        int nextNode = *it;
        
        if (status[nextNode] == 1) // Found cycle
            return false;
        else if (status[nextNode] == 0 && !helper(nextNode,status,g))
            return false;            
    }
    
    status[node] = 2; // finished
    
    return true;
}


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    
    unordered_map<int,vector<int> > g;
    vector<int> status (numCourses + 1, 0); // 0 : not visited
                                        // 1 : current being visited
                                        // 2 : finished
    
    for (auto p : prerequisites)
        g[p.second].emplace_back(p.first);
    
    // DFS 
    for (auto it : g)
    {
        int node = it.first;
        
        if (status[node] == 0) // Not visited
        {
            if (!helper(node,status,g))
                return false;
        }
    }
    
    return true;
}

int main()
{
    vector<pair<int,int> > pre = {{1,2}};
    
    cout << canFinish(2,pre) << endl;
    
    return 0;
}