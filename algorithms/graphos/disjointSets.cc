/*
    DISJOINT SETS   
    
    Mantains a collection of disjoint sets.
    
    Each set is identified by a "representative node"

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node
{
    Node* parent;
    int data;
    int rank;
    
    // Constructor
    Node(int d): data(d), parent(this), rank(0) {}
};

class DisjointSet
{
    private:
        unordered_map<int,Node*> map;
    
    public:
        
        // Create a set with only one element        
        void makeSet(int data)
        {
            Node* node = new Node(data);
            map[data] = node;
        }
        
        // Merge two different sets
        void unionSets(int data1,int data2)
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
        
        // Return representative of a set, and apply path compression on the way
        Node* findSet(Node* node)
        {
            if (node == node->parent) // representative of set
                return node->parent;
            
            node->parent = findSet(node->parent); // Path compression
            return node->parent;
        }
        
        void printSet(int data)
        {
            Node* node = map[data];
            cout << findSet(node)->data << endl;
            
        }
};

int main()
{
    DisjointSet disj;

    disj.makeSet(1);
    disj.makeSet(2);
    disj.makeSet(3);
    disj.makeSet(4);
    disj.makeSet(5);
    disj.makeSet(6);
    disj.makeSet(7);
  
    disj.unionSets(1,2);    
    disj.unionSets(2,3);    
    disj.unionSets(4,5);    
    disj.unionSets(6,7);    
    disj.unionSets(5,6);  
    disj.unionSets(3,7);  

    
    disj.printSet(1);
    disj.printSet(2);
    disj.printSet(3);
    disj.printSet(4);
    disj.printSet(5);
    disj.printSet(6);
    disj.printSet(7);
    
    return 0;
}