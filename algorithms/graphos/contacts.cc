#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;


void findGroups(const unordered_map<string, unordered_set<string>>& graph,
                unordered_set<string>& visited, vector<string>& group,
                vector<vector<string>>& ans, const string& contact);


vector<vector<string>> contactGroups(const unordered_map<string,unordered_set<string>>& contacts)
    
{
    unordered_map<string,unordered_set<string>> inversedContacts;
    unordered_map<string, unordered_set<string>> graph;
    
    // Reverse map to <"email"> : <"contacts">
    for (const auto& contact : contacts)
    {
        for (const auto& email : contact.second)
        {
            inversedContacts[email].emplace(contact.first);
        }
    }
    
    // Create edges (undirected) between contacts that have same email
    for (const auto& email : inversedContacts)
    {
        
        auto it = begin(email.second);
        graph[*it];
        
        for (auto it2 = next(it); it2 !=end(email.second); ++it2) {
            
           graph[*it].insert(*it2);
           graph[*it2].insert(*it);
       
        }
    }
   
    vector<vector<string>> ans;
    vector<string> group;
    unordered_set<string> visited;
    
    for (const auto& v : graph)
    {
       if(visited.find(v.first) == visited.end())
       {
           findGroups(graph,visited,group,ans, v.first);

       }
    }
    
    return ans;
    
}

void findGroups(const unordered_map<string, unordered_set<string>>& graph,
                unordered_set<string>& visited, vector<string>& group,
                vector<vector<string>>& ans,  const string& contact)
{
    group.emplace_back(contact);

    visited.emplace(contact);

    auto list = (graph.find(contact))->second;
    
    cout << list.size() << endl;
    
    for (const auto& connectedContact : list)
    {
        if(visited.find(connectedContact) == visited.end())
        {
            findGroups(graph,visited,group,ans,connectedContact);
        }
    }

    
    ans.emplace_back(group);
    group.pop_back();

}

int main()
{
    unordered_set<string> c1 {"@facebook", "@gmail"};
    unordered_set<string> c2 {"@yahoo"};
    unordered_set<string> c3 {"@yahoo", "@gmail"};
    unordered_set<string> c4 {"@newEmail"};
    
    unordered_map<string,unordered_set<string>> contacts;
    contacts["c1"]   = c1;
    contacts["c2"] = c2;
    contacts["c3"] = c3;
   // contacts["c4"] = c4;
    
   vector<vector<string>> ans =  contactGroups(contacts);
   
   for (const auto& v : ans)
   {
       for(const auto& c : v)
       {
           cout << c << " ";
       }
       
       cout << endl;
   }
    
    return 0 ;
    
}