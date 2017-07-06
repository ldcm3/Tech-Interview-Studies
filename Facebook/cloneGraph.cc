/*

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

Nodes are labeled uniquely.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
 
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


UndirectedGraphNode* dfs(unordered_map <int,UndirectedGraphNode*>& visited,
                            UndirectedGraphNode* node)
{
    if (visited.find(node->label) != visited.end())
        return visited[node->label];
        
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
    
    visited.emplace(node->label,newNode);
    
    for (auto n : node->neighbors)
    {
        newNode->neighbors.emplace_back (dfs(visited,n));
    }
    
    return newNode;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    
    if(!node)
        return node;
        
    unordered_map <int,UndirectedGraphNode*> visited;
    return dfs(visited,node);
}


int main()
{
    
    return 0;
}