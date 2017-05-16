/*

You have an array a containing 2 * n + 2 positive numbers, 
in which n numbers occur twice and two other numbers occur only once and are distinct. 
Find the two distinct numbers and return them in ascending order.

    Solution:
    
    - Find a^b in the arr
    - Choose an up bit in a^b ( xOr = xOr & ~(xOr - 1) )
    - One of the answers must have this bit up and the other one not (since it is a XOR)
    - Divide the vector in two sets (elements with the selected bit up and elements with the selected bit down)
    - XOR in both sets to find a and b

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> findTheNumbers(const vector<int>& v)
{
    int xOr = 0;
    
    for (int n : v)
        xOr ^= n;
    
    xOr = xOr & ~(xOr - 1);
    
    int ans1 = 0,ans2 = 0;
    
    for (int n : v)
        xOr & n ? ans1 ^= n : ans2 ^= n;
    
    return {ans1 < ans2 ? ans1,ans2 : ans2,ans1};
}

int main()
{
    vector<int> test = {1, 3, 5, 6, 1, 4, 3, 6};
    
    vector<int> ans = findTheNumbers(test);
    
    cout << ans[0] << " " << ans[1] << endl;
    
    return 0;
}