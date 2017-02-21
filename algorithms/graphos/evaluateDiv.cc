/*
    Equations are given in the format A / B = k, where A and B are variables represented as strings, 
    and k is a real number (floating point number).
    Given some queries, return the answers. If the answer does not exist, return -1.0.

    Example:
    Given a / b = 2.0, b / c = 3.0. 
    queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
    return [6.0, 0.5, -1.0, 1.0, -1.0 ].

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;
struct ValueNode{
    string str;
    double val;
    
    ValueNode(string s, double d): str(s), val(d) {}
};

bool dfs(string start,string end,double curAns,unordered_set<string>& visited,
        unordered_map<string,unordered_set<ValueNode*>>graph,double& ans)
{
               
    visited.emplace(start);
    
    if(start == end)
    {
        ans = curAns;
        return true;
    }
    
    auto iter = graph.find(start);
        
    for(auto node : iter->second)
    {
        if(visited.find(node->str) == visited.end())
        {
           if(dfs(node->str,end,curAns*node->val,visited,
                    graph, ans))
                return true;
        }
    }
    
    return false;
    
} 

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    
    unordered_map<string,unordered_set<ValueNode*>> graph;
    
    for(int i = 0 ;i < equations.size(); ++i)
    {
        graph[equations[i].first].emplace(new ValueNode(equations[i].second, values[i]));
        graph[equations[i].second].emplace(new ValueNode(equations[i].first, (1.0/values[i])));
    }
    
    vector<double> ans;
    
    for(auto p : queries)
    {
        if(graph.find(p.first) == graph.end() ||
            graph.find(p.second) == graph.end())
            ans.emplace_back(-1.0);
        else if(p.first == p.second)
             ans.emplace_back(1.0);
        else
        {
            // DFS
            double res;
            double curAns = 1.0;
            unordered_set<string> visited;
            
            if(!dfs(p.first,p.second,curAns,visited,graph,res))
                ans.emplace_back(-1.0);
            else
                ans.emplace_back(res);
        }
    }
    
    return ans;
    
}


int main()
{
    
    return 0;
}