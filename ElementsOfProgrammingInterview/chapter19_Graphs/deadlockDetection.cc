/*
    Build a deadlock detection algorithm, that takes as input a 
    directed graph and checks if the graph contains a cycle.

    -------------------------------------------------------------
    
    Solution: 
    
    Run DFS, keep track of first discovered vertex (gray)..
    When find a edge from a gray vertex back to a gray vertex, there is a cycle.
    
    Time Complexity for DFS is O(|V| + |E|) and
                               O(|V|) space

*/

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;


struct GraphVertex
{
    enum Color {white,gray,black} color = white;
    vector<GraphVertex*> edges;
};

bool hasCycle(GraphVertex* cur);

bool isDeadLocked(vector<GraphVertex>& G)
{
    return any_of(begin(G), end(    G), [](GraphVertex& v){
        return v.color == GraphVertex :: white && hasCycle(&v); // only white nodes are reacheable
    });
    
}

bool hasCycle(GraphVertex* cur)
{
    if (cur->color == GraphVertex::gray) // Visiting a gray node means a cycle
        return true;
        
    cur->color = GraphVertex :: gray;
    
    for (GraphVertex* next : cur->edges)
    {
        if(next->color != GraphVertex::black)
        {
            if (hasCycle(next))
                return true;
        }
    }
    
    cur->color = GraphVertex::black;
    return false;
}


int main()
{
    return 0;
}

