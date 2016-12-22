#include<iostream>
#include<vector>
#include <cstring>
#include <list>
#include <queue>

using namespace std;

/*
    Find out whether there is a route between two nodes
    
    BFS: 
        - useful to find shortest paht
    DFS:
        - simpler to implement
        - may traverse adjancent node very deeply before going onto the immediates nerighbours
*/


class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int V);
        void addEdge(int v,int w);
        bool BFS(int v,int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);    
}

bool Graph::BFS(int v,int s)
{
    queue <int> q;
    bool *visited = new bool[V];
    
    for(int i =0 ;i < V; i++)
        visited[i] = false;
        
    visited[v] = true;
    
    q.push(v);
    
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                if(*i == s)
                    return true;
                    
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    
    return false;
    
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    
    cout << g.BFS(0,3) << endl;
    
    return 0;
}