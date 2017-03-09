#include<iostream>
#include<vector> 
#include<queue>
#include<set>

using namespace std;

vector<int> solve(int A, int B, int C, int D) {

    set <int> s;
    queue<int> q;
    
    q.push(1);
    vector<int> p = {A,B,C};
    
    while(s.size() < D)
    {
        int cur = q.front();
        q.pop();
        
        for(int &x : p)
        {
            if(s.find(x*cur) == s.end())
            {
                 s.emplace(cur*x);
                 q.push(x*cur);
            }
               
        }
    }
    
    int i = 0;
    vector<int> ans; 
    for(auto r : s)
    {
        ans.push_back(r);
        ++i;
        if(i == D)
            break;
    }
    
    return ans;
}

int main()
{
   vector<int> ans =  solve(2,3,5,5);
   
   for(auto x : ans)
       cout << x << " ";
    
    cout << endl;
    return 0;
}