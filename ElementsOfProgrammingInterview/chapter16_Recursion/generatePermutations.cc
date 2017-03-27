/*
    Generate Permutations of distinct numbers
    
    Time Complexity 
    
    O(n X !n) since there are !n permutations and we spend O(n) time to 
    store each one
*/

#include<iostream>
#include<vector>

using namespace std;

void helper (vector<int> A, int idx , vector<vector<int> >& res)
{
    if (idx == A.size())
    {
        res.emplace_back(A);
        return;
    }
    
    for (int i = idx; i < A.size(); ++i)
    {
        swap(A[idx],A[i]);
        helper(A,idx + 1,res);
        swap(A[idx],A[i]);
    }
    
}

vector<vector<int>> permutations(vector<int> A)
{
    vector<vector<int> > res;
    helper(A,0,res);
    
    return res;
}

int main()
{
    vector<vector<int> > res = permutations({1,2,3});
    
    for (auto v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}