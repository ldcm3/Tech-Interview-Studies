/*

*/

#include<iostream>
#include<vector>

using namespace std;

struct Interval{
    int left,right;
    
    bool operator<(const Interval& i) const {
        return left < i.left;
    }
};

vector<Interval> addAndMergeIntervals(const vector<Interval>& disjoint_intervals,
                                        Interval new_interval)
{
    disjoint_intervals.push_back(new_interval);
    sort(disjoint_intervals.begin(), disjoint_intervals.end());
    vector<Interval> ans;
    
    auto curInterval = disjoint_intervals[0];
    
    for (size_t i = 1; i < disjoint_intervals.size(); ++i)
    {
        if (disjoint_intervals[i].left <= curInterval.right)
            curInterval.end = max(curInterval.right,disjoint_intervals.right);
        else
        {
            ans.push_back(curInterval);
            curInterval = disjoint_intervals[i];
        }
    }
    
    ans.push_back(curInterval);
    
    return ans;
    
}

int main()
{
    return 0;
}