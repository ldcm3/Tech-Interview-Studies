/*

Program to Traverse  a Graph Using BFS

*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V; // number of vertices
    list<int> *adj; // Pointer to an array containing adjancency lists
    void DFSUtil(int v, bool visited[]); // A function used by DFS
    
    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add an edge
        void BFS(int s); // print BFS traversal from a given source
        void DFS(int v); // print DFS traversal from a given source
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list
}

/* ==================================================
                    BFS
   
   - Visit all the nodes reacheable from given S 
   - O (V*E) time complexity
   - Searching level by level (QUEUE)
   - The earlier a vertex is discovered, the earlier it is visited
   
   ================================================= */

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int level[V];
    level[s] = 1;
    
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                level[*i] = level[s] + 1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    

    for (int i =0 ;  i < V; i++)
    {
        if(level[i] == level[s])
            counter++;
    }
    
    
}


/* ==================================================
                    DFS
  - Edge Classification 
  - Cycle Detection 
  - Topological sort
  - Backtracking as necessary
  - O(V + E) time complexity
  - Search to 'dive' right to the end of the first search path 
    before considering any other vertices.
  
  ================================================= */

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    
    
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
            DFSUtil(*i,visited);
    }
}

// DFS traversal for the vertices reacheable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0;i < V; i++)
    {
        visited[i] = false;
    }
    
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

/* ============== MAIN ====================== */

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    
    cout << "Following is Breath First Traversal \n";
    g.BFS(0);
    cout << endl;
    
    // cout << "Following is Depth First Traversal \n";
    // g.DFS(2);
    // cout << endl;
    
    
    return 0;
}