/*
    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
    vertex u comes before v in the ordering. 
    
    Topological Sorting for a graph is not possible if the graph is not a DAG.
    
    

*/

#include<iostream>
#include<unordered_set>
#include<list>
#include<stack>

using namespace std;

class Graph
{
    private:
        int V;
        list<int> *adj;
        stack<int> topS;
        
    public:
      
        Graph(int V);
        void addEdge(int s, int v);
        void topologicalSort();
        void topologicalSortUtil(int v,unordered_set<int>& visited);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph :: addEdge (int s, int v)
{
    adj[s].push_back(v);    
}

void Graph :: topologicalSort()
{
    unordered_set <int> visited;
    
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited.find(i) == visited.end())
        topologicalSortUtil(i, visited);
    
    while (!topS.empty())
    {
        cout << topS.top() << " ";
        topS.pop();
    }
}

void Graph :: topologicalSortUtil(int v, unordered_set<int> & visited)
{
    visited.insert(v);
    
    for(auto it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (visited.find(*it) == visited.end()) // not visited so far
            topologicalSortUtil(*it,visited);
    }

    topS.push(v);
}


using namespace std;

int main()
{
     Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is Topological Sort ---<<< \n";
    g.topologicalSort();
    cout << endl;
    
    return 0;
}