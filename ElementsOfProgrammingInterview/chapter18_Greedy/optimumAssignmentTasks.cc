#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int optimumTasksAssig(vector<int> tasks_duration)
{
    sort(tasks_duration.begin(), tasks_duration.end());
    
    int maxHours = -1;
    
    int i = 0;
    int j = tasks_duration.size() - 1;
    
    while(i < j)
    {
        maxHours = max(maxHours,tasks_duration[i] + tasks_duration[j]);
        ++i;
        --j;
    }
    
    return maxHours;
}

int main()
{
    vector<int> vec {5,2,1,6,4,4};
    cout << optimumTasksAssig(vec) << endl;   
    return 0;
}