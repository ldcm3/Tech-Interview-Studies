/*

    - Find shortest path in a weighted directed graph
    - Greedy Strategy (because it always choose the lightest vertex)
    - It might have cycles

    TIME COMPLEXITY
    
    - Using min heap as a priority queue => O ( (V+E) logV)
    
    
*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define INT_MAX 999999

typedef pair<int, int> iPair; // Int Pair

class Graph
{
    int V;  
    list <iPair> *adj; // store vertex and distance pair for every edge
    
    public:
        Graph(int V); // constructor
        void addEdge(int u, int v, int w);
        void shortestPath(int s); // print shortest paths from s
};

Graph :: Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph :: addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[u].push_back(make_pair(u,w));
}

void Graph :: shortestPath(int s)
{
    
    // store vertices that are being preprocessed
    priority_queue < iPair, vector<iPair>, greater<iPair> > q;

    // store distances and initialize all of them as infinite    
    vector<int> dist (V, INT_MAX);
    
    q.push(make_pair(0,s)); // insert source and initialize its dist as 0
                            // elements are sorted by its distance
    dist[s] = 0;
    
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first; // vertex label
            int w = (*i).second; // weight
            
            // if there is shorter path from u to v
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v],v));
            }
        }
    }
    
    // Print shortest distances stored in dist[]
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < dist.size() ; i++)
        cout << i << "\t\t "<< dist[i] << "\n";
}


int main()
{   
    
    
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
    
    return 0;
}