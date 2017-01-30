/*
    Given teams A and B , is there a sequence of teams starting with A and
        ending with B such that each team in the sequence has beaten the next team
        in the sequence?

*/

/*
    Time Complexity is O(E), where E is the number of outcomes

*/

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;


struct MatchResult
{
    string winning_team, losing_team;
    
    MatchResult(string A,string B): winning_team(A),losing_team(B) {}
};

bool canTeamABeatTeamB (const string& A, const string& B,
                        const vector<MatchResult>& matches);
                        
bool isReacheableDFS (const unordered_map<string,unordered_set<string>>& graph,
                    const string& cur, const string& dest, unordered_set<string>& visited);


/*
    Graph of teams
    
    The winner goes to the looser 
    
    teamA ----> teamB 
    teamA ----> teamD
    teamB -----> teamD

    [teamA] = [teamB,teamD]
*/

unordered_map<string,unordered_set<string>> buildGraph(
                const vector<MatchResult>& matches)
{
    unordered_map<string, unordered_set<string> > graph;
    
    for (const MatchResult& match  : matches)
    {
        graph[match.winning_team].emplace(match.losing_team);
    }
    
    return graph;
}

bool canTeamABeatTeamB (const string& A, const string& B,
                        const vector<MatchResult>& matches)
{
    unordered_set<string> visited;
    
    unordered_map<string, unordered_set<string>> graph = buildGraph(matches);
    
    return isReacheableDFS(graph,A,B,visited);
}

bool isReacheableDFS (const unordered_map<string,unordered_set<string>>& graph,
                    const string& cur, const string& dest, unordered_set<string>& visited)
{
    
    if (cur == dest)
        return true;
    else if(graph.find(cur) == graph.end()) // if curTeam has won anything
        return false;
        
    visited.emplace(cur);
    
    for (const auto& team : graph.at(cur))
    {
        if (visited.find(team) == visited.end())
            return isReacheableDFS(graph,team,dest,visited);
    }
}


int main()
{
    MatchResult match1("teamA", "teamD");
    MatchResult match2("teamD", "teamE");
    MatchResult match3("teamC", "teamB");
    MatchResult match4("teamE", "teamB");
    
    vector <MatchResult> matches {match1,match2,match3,match4};
    
    cout << canTeamABeatTeamB("teamA","teamB", matches) << endl;
    

    return 0;
}