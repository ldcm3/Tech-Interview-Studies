/*

Suppose you have a line of n people in which the k-th person is described by a pair (h,t) 

where h is the height of the k-th person and t is the number of people in front of k who have a height 

greater or equal than h . Write an algorithm to reconstruct the line.

For example, if the line is composed by the following people:

[(7, 0),(4, 4),(7,1), (5, 0), (6,1), (5, 2)]

The original line should be:

[(5,0), (7,0), (5,2), (6,1), (4,4),(7,1)]

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct People{
    int h;
    int t;
    
    People(int height,int taller): h(height), t(taller) {}
};

class mySort{
    public:
    bool operator()(People a,People b) const
    {
        return a.h > b.h;
    }
};


class mySortBySeen{
    public:
    bool operator()(People a,People b) const
    {
        return a.t < b.t;
    }
};


vector<People> reconstructLine (vector<People>& line)
{
    sort (line.begin(), line.end(), mySortBySeen());
    sort (line.begin(), line.end(), mySort());

    vector<People>ret;
    ret.reserve(line.size());
    for (auto it = line.begin(); it != line.end() ; it++){
		ret.insert(ret.begin() + it->t, *it);
	}
	
	return ret;
}

int main()
{
    vector<People> test = {People(7, 0),People(4, 4),People(7,1), People(5, 0), People(6,1),People (5, 2)};
    vector<People> ans = reconstructLine(test);
    
    for (auto p : ans)
    {
        cout << "(" << p.h << " " << p.t << ") ";
    }
    cout << endl;
    return 0;
}