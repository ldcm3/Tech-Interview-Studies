/*

    Check if letters in string can be permuted to form a palindrome
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool canFormPalindrome(const string& s)
{
    unordered_set<char> char_freq;
    
    for(char ch : s)
    {
        if(char_freq.find(ch) != char_freq.end())
            char_freq.erase(ch);
        else
            char_freq.insert(ch);
    }
    
    return char_freq.size() <= 1 ? true : false;
    
}


int main()
{
    cout << canFormPalindrome("tet") << endl;
    return 0;
}