/*

    - Find shortest path in a weighted directed graph
    - Greedy Strategy (because it always choose the lightest vertex)
    - it might have cycles
    
*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list <int> *adj;
    
    public:
        Graph(int V);
        void addEdge(int v, int s);
}

Graph :: Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

int main()
{
    return 0;
}