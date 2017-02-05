/*
    Find the length of the longest substring T of a given string 
    (consists of lowercase letters only) such that every character in T
    appears no less than k times.
    
    Input:
    s = "ababbc", k = 2
    
    Output:
    5
    
    The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
    
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestSubStrLen(const string& A, int k)
{
    unordered_map<char,int> lettersCounter;
    
    for (const char& ch : A)
    {
        lettersCounter[ch]++;
    }
    
    int idx = 0;
    
    while(idx < A.size() && 
            lettersCounter[A[idx]] >= k)
    {
        ++idx;
    }
    
    if (idx == A.size())
        return A.size();
        
    int left = longestSubStrLen(A.substr(0,idx),k);
    int right = longestSubStrLen(A.substr(idx + 1),k);
    
    return max(left,right);
}

int main()
{
    string A = "ababbc";
    int k = 2;
    cout << longestSubStrLen(A,k) << endl;
    return 0;
}