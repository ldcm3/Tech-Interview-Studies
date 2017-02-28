#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int maxRectangle(const vector<int>& h)
{
    if(h.size() == 0)
        return 0;
        
    int top;
    int largestArea = -1;
    int len = h.size();
    stack<int> s; // save indexes of highest pillars
    s.push(0);
    
    for(int i = 1; i < len; ++i)
    {
        while(!s.empty() && h[i] <= h[s.top()])
        {
            top = s.top();
            s.pop();
            
            int width = s.empty() ? i : (i - s.top() - 1);
            largestArea = max(largestArea, h[top]*width);
        }
        
       if(s.empty() || h[i] > h[s.top()])
            s.push(i);
    }
    
     while(!s.empty())
    {
        top = s.top();
        s.pop();
        
        int width = s.empty() ? len : (len - s.top() - 1);
        largestArea = max(largestArea, h[top]*width);
    }
    
    return largestArea;
}

int main()
{
    return 0;
}