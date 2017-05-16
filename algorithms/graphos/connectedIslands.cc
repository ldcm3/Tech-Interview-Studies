#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> iPair;

struct Node
{
    Node* parent;
    int data;
    int rank;
    Node(int v): data(v),parent(this),rank(0)
    {}
};

class DisjointSet {
    private:
        unordered_map<int,Node*> map;
    public:
    
        DisjointSet(int A)
        {
            for (int i = 1; i <= A; ++i)
                makeSet(i);
        }
    
        void makeSet(int data)
        {
            Node* node = new Node(data);
            map[data] = node;
        }
        
        void unionSet(int data1, int data2)
        {
            Node* node1 = map[data1];
            Node* node2 = map[data2];
            
            Node* parent1 = findSet(node1);
            Node* parent2 = findSet(node2);
            
            if (parent1 == parent2) // They are already part of the same set
                return;
            
            // Higher rank node will be the representative
            if (parent1->rank >= parent2->rank)
            {
                if (parent1->rank == parent2->rank)
                    ++parent1->rank;
    
                parent2->parent = parent1;
            }
            else
            {
                parent1->parent = parent2;
            }
        }
        
        
        Node* findSet(Node* node)
        {
            Node* parent = node->parent;
            
            if (parent == node)
                return parent;
            
            node->parent = findSet(node->parent);
            return node->parent;
        }
        
        int findSetInt(int data)
        {
            Node* node = map[data];
            Node* rep = findSet(node);
            
            return rep->data;
        }
        
};

bool MySort(pair<int,iPair> a, pair<int,iPair>  b)
{
    return a.first < b.first;
}

int solve(int A, vector<vector<int> > &B) {

    vector<pair<int,iPair> > g; // u, v, w
    
    // Build Graph
    for (auto &edge : B)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        
        g.push_back({w,{u,v}});
        g.push_back({w,{v,u}});
    }
    
    sort (g.begin(), g.end(), MySort);
    
    DisjointSet ds(A);
    
    int shortestDist = 0;
    
    for (auto it = g.begin(); it != g.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;
        
        int set_u = ds.findSetInt(u);
        int set_v = ds.findSetInt(v);
        
        if (set_u != set_v)
        {
            shortestDist += w;
            ds.unionSet(set_u,set_v);
        }
        
    }
 
    return shortestDist;
}


int main()
{
    //vector<vector<int> > test = {{1,2,1},{2,3,2},{3,4,4},{1,4,3}};
    vector<vector<int> > test = {{1,2,5}};
    cout << solve(2,test) << endl;
    return 0;
}
