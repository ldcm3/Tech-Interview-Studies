#include <iostream>
#include <list> 
#include <vector>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
    public:
        Graph(int V);
        void addEdge(int u,int v);
        void DFS(int u);
        void DFSUtil(vector<int> &visited,int u);
};

Graph :: Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v)
{
    adj[u].push_back(v);    
}


void Graph :: DFS (int u)
{
    vector<int> visited;
    
    for (int i = 0; i < V; i++)
        visited.push_back(-1); // not visited
    
    DFSUtil(visited,u);
   
}

void Graph :: DFSUtil(vector<int> &visited,int u)
{
    visited[u] = 1; // visited u;
    
    cout << u << " "; // print traversal
    
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int tmp = *i;
        
        if (visited[tmp] == -1)
            DFSUtil(visited,tmp);
    }
}

int main()
{
    
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    g.addEdge(7, 6);
    g.addEdge(6, 8);
    
    cout << "Following is Depth First Traversal \n";
    g.DFS(0);
    cout << endl;

    return 0;
}