/*
    
    Being the Earth in a 3D system at coords (0,0,0), find all the k closest 
    stars 

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Star {
    bool operator<(const Star& that) const
    {
        return Distance() < that.Distance();
    }
    
    double Distance() const { return sqrt(x*x + y*y + z*z); }
    
    double x,y,z;
};

void (int k, const vector<Star>& stars)
{
    // max_heap to store the closest k stars seen so far
    priority_queue<Star,vector<Star>, lesser<Start> > max_heap;
    
    for (auto s : stars)
    {
        max_heap.emplace(s);
        
        if(max_heap.size() > k)
            max_heap.pop();
    }
    
    // closest starts
    while(!max_heap.empty())
    {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
}

int main()
{
    return 0;
}