/*

Given a string str and array of pairs that indicates which indices in the string can be swapped, 
return the lexicographically largest string that results from doing the allowed swaps.
You can swap indices any number of times.

Example

For str = "abdc" and pairs = [[1, 4], [3, 4]], the output should be
swapLexOrder(str, pairs) = "dbca".

By swapping the given indices, you get the strings: 
"cdba", "cbad", "dbac", "dbca". The lexicographically largest string in this list is "dbca".
*/


#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;



/*
 * [1,4][3,4]
 * 
 * [1,3,4]
 * 
 * str = "abdc"
 * ans = "dbca"
 * 
 * */
string swapLexOrder(string str, vector<vector<int>> pairs) {


 unordered_set<int> visited; // visited idxs;
 
 vector<vector<int>> connectedIdxs;
 
 unordered_map<int, unordered_set<int>> graph;
 
 
 // [1,2], [3,4], [2,3] 
 // find the connected components idx that can be swapped 
 // [1,2,3,4]
 for(auto pair : pairs)
 {
   graph[pair[0]].emplace(pair[1]);
   graph[pair[1]].emplace(pair[0]);  // undirected graph
 }
 
 for (const auto& g : graph)
 {
   vector<int> idxs;
   int v = g.first;

   if(visited.find(v) != visited.end())
     continue;
  else{
     stack<int> q; // connected idxs
     q.emplace(v);
     visited.emplace(v);
   
     // DFS
     while(!q.empty())
     {
       int cur = q.top();
       q.pop();
       idxs.emplace_back(cur);
   
      for(int x : graph[cur])
      {
         if(visited.find(x) == visited.end())
         {
             visited.emplace(x);
             q.emplace(x);
         }
      }
     }
   
     if(idxs.size() != 0)
     {
       sort(idxs.begin(), idxs.end());
       connectedIdxs.emplace_back(idxs);
     }
  }
 }
  
 for (auto vec : connectedIdxs)
 {
   string tmp = "";
   for (int i : vec) // loop through connected Components
   {
     tmp += str[i - 1];
   }

   sort(tmp.begin(),tmp.end(), greater<int>());

   int j = 0;
   
   cout << tmp << endl;
   for (int i : vec)
   {
     //cout << str[i-1];
     str[i- 1] = tmp[j];
     j++;
   }
//cout <<endl;
 }
 
 return str;
}





int main()
{
    string str = "bdca";
vector<vector<int>> pairs {{1,2}, 
                         {2,3}};
 
 cout << swapLexOrder(str,pairs) << endl;
    return 0;
}

