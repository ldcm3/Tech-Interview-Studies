/*

    Find the Intersection of two sorted arrays
    
    A = {2,3,3,5,5,6,7,7,8,12}
    B = {5,5,6,8,8,9,10,10}
    
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> intersection(const vector<int>& arr1, const vector<int>& arr2)
{
    vector<int> ans;
    
    int i = 0, j = 0;
    
    while(i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] == arr2[j] && (i == 0 || arr1[i] != arr1[i-1]))
        {
            ans.emplace_back(arr1[i++]);
            ++j;
        }
        else if (arr1[i] < arr2[j])
            ++i;
        else
            ++j;
    }
    
    return ans;
}

int main()
{
    vector<int> ans = intersection({2,3,3,5,5,6,7,7,8,12},
                                    {5,5,6,8,8,9,10,10});
                                    
    for(int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}