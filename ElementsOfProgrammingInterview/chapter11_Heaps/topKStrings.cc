/*
    Write a program that takes a sequence of strings presented in "streaming"
    fashion (you cannot backup to read an earlier value).
    
    You must compute the k longest strings in the sequence (its not required 
    to order these strings)
*/

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Comp {
    public:
    bool operator() (const string& a, const string& b) {
        return a.size() >= b.size();
    }
};

vector<string> topK(int k, int nOfStrings)
{
    
    string nextString;
    vector<string> res;
    
    priority_queue<string, vector<string>, Comp> min_heap;
           
            
    while (nOfStrings--)
    {
         cin >> nextString;
         min_heap.emplace(nextString);
         
         if(min_heap.size() > k)
         {
             // remove the shortest string
             min_heap.pop();
         }
    }
    
    while(!min_heap.empty())
    {
        res.emplace_back(min_heap.top());
        min_heap.pop();
        cout << res.back() << " ";
    }
    
    return res;
}

int main()
{   
    topK(3,5);
    return 0;
}