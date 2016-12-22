#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    int *parents;

    public:
        Graph(int V);
        void addEdge(int s,int w);
        void shortestPath(int v, int w);
        
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];  
}

void Graph::addEdge(int s,int w)
{
    adj[s].push_back(w);
}

void Graph:: shortestPath(int v, int w)
{
    queue<int> q;
    q.push(v);
    
    bool *visited = new bool[V];
    int parent[V];
    for(int i = 0 ;i < V; i++)
        visited[i] = false;
    
    parent[v] = -1;
    
    visited[v] = true;
    
    int cur;
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        for (auto i = adj[cur].begin(); i != adj[cur].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
                parent[*i] = cur;
            }
        }
    }

    // Shortest Path 
    
	int counter = 1; // Path length
	cur = w;
	vector<int> path; // Keep track of the path
	
	path.push_back(cur);

    // Tracking path 
	while(parent[cur] != v)
	{	
		cur = parent[cur];
		path.push_back(cur);
		counter++;
	}
	
	path.push_back(v);
	
	cout << "Shortest Path is " << counter << endl;
	
	for(int i = path.size() - 1; i >= 0; --i)
	{
		cout << path[i] << " ";
	}
	cout << endl;
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
    
    g.shortestPath(0,3);
    
  
    return 0;
}