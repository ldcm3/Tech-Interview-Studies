/*
Given two binary strings a and b, add them together and return the resulting string.

Example

For a = "1000" and b = "111", the output should be
addBinaryStrings(a, b) = "1111";
For a = "1" and b = "1", the output should be
addBinaryStrings(a, b) = "10".

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string addBinaryStrings(string a, string b)
{
    string ans;
    int carry = 0;
    
    reverse(a.begin(),a.end());
    reverse(b.begin(), b.end());
    
    while(a.size() < b.size())
        a += '0';
    while(b.size() < a.size())
        b += '0';
        
    for(size_t i = 0; i < a.size(); ++i)
    {
        int tmp = (a[i] - '0') + (b[i] - '0') + carry;
        ans += (tmp % 2)  + '0';
        carry = tmp / 2;
    }
    
    if(carry)
        ans += '1';
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}


int main()
{
    string a = "1111100";
    string b = "0000111";
    
    cout << addBinaryStrings(a,b) << endl;
    return 0;
}