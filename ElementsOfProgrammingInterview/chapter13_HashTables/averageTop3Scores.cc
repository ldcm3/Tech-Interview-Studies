/*
    Write a program which takes as input a file containing names and test scores,
    and return the student who has the maximum score averaged across his top three tests.

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<istream>
#include<unordered_map> 

using namespace std;

string highestScoreStudent(ifstream* ifs)
{
    unordered_map <string, priority_queue<int, vector<int>, greater<> > > student_scores;
    
    string name;
    int score;
    
    while(*ifs >> name >> score)
    {
        student_scores[name].emplace(score);
        
        if (student_scores[name].size() > 3)
            student_scores[name].pop();
    }
    
    string top_student = "no such student";
    int curr_top_scores = 0;
    
    for (const auto& scores : student_scores)
    {
        if (scores.second.size() == 3)
        {
            int curr_scores_sum = getTopThree(scores.second);
            
            if (curr_scores_num > curr_top_scores)
            {
                curr_top_scores = curr_scores_sum;
                top_student = scores.first;
            }
        }
    }
    
    return top_student;
}


int getTopThree(priority_queue<int, vector<int>, greater<>> scores)
{
    int sum = 0;
    while (!scores.empty())
    {
        sum += scores.top();
        scores.pop();
    }
    
    return sum;
}
int main()
{
    return 0;
}