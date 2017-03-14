/*

    Minimum Spanning Tree Kruskal Algorithm
    
    O(E + V) space
    O(Elog(E) + E) time


*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


typedef pair<int,int> iPair;

struct Node
{
    Node* parent;
    int data;
    int rank;
    Node(int v): data(v), parent(this), rank(0)
    {}
};


/** DisJoint Sets **/

class DisjointSets {
    private:
        unordered_map<int,Node*> map;
    
    public:
        
        DisjointSets(vector<pair<int,iPair>> edges)
        {
            for (auto it = edges.begin(); it != edges.end(); ++it)
            {
                makeSet(it->second.first);
            }
        }
        
        void makeSet(int data)
        {
            Node* node = new Node(data);
            map[data] = node;
        }
        
        void merge(int data1,int data2)
        {
            Node* node1 = map[data1];
            Node* node2 = map[data2];
            
            Node* parent1 = findSet(node1);
            Node* parent2 = findSet(node2);
            
            if (parent1 == parent2) // they are part of same set
                return;
            
            if (parent1->rank >= parent2->rank) // higher rank becomes parent of other
            {
                parent1->rank = (parent1->rank == parent2->rank) ? 
                                parent1->rank + 1 : parent1->rank;
                parent2->rank = parent1->rank;
            }
            else
                parent1->rank = parent2->rank;
        }
        
        Node* findSet(Node* node)
        {
            Node* parent = node->parent;
            if (parent == node)
                return parent;
            
            node->parent = findSet(node->parent); // Path Compression 
            
            return node->parent;
        }
        
        int findSetVal(int data)
        {
            Node* node = map[data];
            
            return findSet(node)->data;
        }
};


class Graph {
    int V,E;
    vector<pair<int,iPair>> edges;
    
    Graph(int V,int E)
    {
        this->V = V;
        this->E = E;
    }
    
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w,{u,v}});
    }
    
    // Krusktal Minimum Spanning Tree
    int MST()
    {
        int mst_wt = 0;
        // Sort based on weight
        sort (edges.begin(), edges.end()); 
        
        DisjointSets ds(edges);
        
        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            int u = it->second.first;
            int v = it->second.second;
            
            int set_u = ds.findSetVal(u);
            int set_v= ds.findSetVal(v);
            
            // Check if selected edge is creating a cycle
            // (Cycle is created if u and b belong to the same set)
            if (set_u != set_v)
            {
                cout << u << "-" << v << endl;
                mst_wt += it->first;
                ds.merge(set_u,set_v);
            }
        }
        
        return mst_wt;
    }
};

int main()
{
    return 0;
}