/*
    Given an array a composed of distinct elements, 
    find the next larger element for each element of the array in the order in which 
    they appear in the array, and return the results as a new array of the same length. 
    
    If an element does not have a larger element to its right, 
    put -1 in the appropriate cell of the result array.

    Example
    
    For a = [6, 7, 3, 8], the output should be
    nextLarger(a) = [7, 8, 8, -1].


*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

std::vector<int> nextLarger(std::vector<int> a) {
    
    stack<int> s;
    vector<int> ans (a.size());
    
    for (int i = a.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() < a[i])
            s.pop();
        
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
    
        s.push(a[i]);
    }
    
    return ans;
}

int main()
{
    vector<int> test = {6,7,3,8};
    
    vector<int> ans = nextLarger(test);
    
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}