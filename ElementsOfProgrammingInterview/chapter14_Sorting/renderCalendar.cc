/*
    Write a program that takes a set o events and determines the maximum of
    events that take place concurrently
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Event{
    int start,end;
    Event(int s,int e): start(s), end(e) {}
};

struct Endpoint{
    int time;
    bool isStart;
    
    bool operator<(const Endpoint& e) const {
        // If times are equal an endpoint that starts an interval comes first
        return time != e.time? time < e.time : (isStart && !e.isStart);
    }
};

int maxConcurrentlyEvts(vector<Event>& events)
{
    vector<Endpoint> E;
    
    for (const Event& event : events)
    {
        E.emplace_back(Endpoint{event.start,true});
        E.emplace_back(Endpoint{event.end,false});
    }
    
    cout << endl;
    
    sort(E.begin(), E.end());

    int maxConcEvts = 0;
    int maxSoFar = 0;
    
    for (const Endpoint& endpoint : E)
    {
        if (endpoint.isStart)
        {
            ++maxSoFar;
            maxConcEvts = max(maxSoFar,maxConcEvts);
        }
        else
            --maxSoFar;
    }
    
    return maxConcEvts;

}

int main()
{
    vector<Event> input {{1,5},{2,7},{4,5},{6,10},{8,9},{9,17},{11,13},{12,15},{14,15}};
    
    cout << maxConcurrentlyEvts(input) << endl;
    return 0;
}