/*
    Maximal set of vertices such that for every pair of vertices u and v, 
    u and v are reachable from each other
    
    Complexity:
        O(E+V) time
        O(V) space
    
    Algo:
    
    1) DFS to find set vertices ascending sorted by finishing time
    2) Generate transpose of G (G with reversed edges)
    3) DFS to G transposed using the decreasing set to find the strongly connected components

*/

#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;


class Graph
{
    private:
        int V;
        list<int> *adj;
        
    public:
        
        Graph(int v):
            V(v),
            adj(new list<int>[v])
            {}
        
        void addEdge(int s, int v)
        {
            adj[s].push_back(v);
        }
        
        vector<vector<int> > stronglyConnectedComponents()
        {
            vector<bool> visited(V,false);
            vector< vector<int> > connectedComponents;
            vector<int> group;
            stack<int> finishedVertices;
            
            for (int i = 0; i < V; ++i)
            {
                if (!visited[i])
                    computeFinishingTime(i,visited,finishedVertices);
            }
            
            // restauring visited vectors
            for (int i = 0; i < V; ++i)
                visited[i] = false;
            
            Graph gTransposed = getTranspose();
            
            while (!finishedVertices.empty())
            {
                int tmp = finishedVertices.top();
                finishedVertices.pop();
                
                if (!visited[tmp])
                    gTransposed.getConnectedGroups(tmp,visited,group);
                
                connectedComponents.push_back(group);
                group.clear();
            }
            
            return connectedComponents;
        }
        
        void computeFinishingTime(int s, vector<bool> &visited, stack<int> &finishedVertices)
        {
            visited[s] = true;
            
            for (auto it = adj[s].begin(); it != adj[s].end(); ++it)
            {
                if (!visited[*it])
                    computeFinishingTime(*it,visited,finishedVertices);
            }
            
            finishedVertices.push(s);
        }
    
        void getConnectedGroups(int s, vector<bool> &visited, vector<int> &group)
        {
            visited[s] = true;
            
            for (auto it = adj[s].begin(); it != adj[s].end(); ++it)
            {
                if (!visited[*it])
                    getConnectedGroups(*it,visited,group);
            }
            
            group.push_back(s);
        }
        
        Graph getTranspose()
        {
            Graph g(V);
            
            for (int v = 0; v < V; ++v)
            {
                for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
                {
                    g.adj[*it].push_back(v);
                }
            }
            
            return g;
        }
    
};




int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    
    /*
              3------>4
             / \
              |
        1 --> 0 --> 2
        /\          |
        |           |
        ------------    
    */
 
    cout << "Following are strongly connected components in "
            "given graph \n";
   
    vector<vector<int>> groups = g.stronglyConnectedComponents();
    
    for (auto g : groups )
    {
        for (auto v : g)
        {
            cout << v << " ";
        }
        
        cout << endl;
    }
    
    
    return 0;
}