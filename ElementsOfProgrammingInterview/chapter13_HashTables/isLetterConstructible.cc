/*
    Check if a letter can be written from letters from a magazine
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isPossible(const string& letter_text, const string& magazine_text)
{
    unordered_map<char,int> freq_letter;
    
    for (char ch : letter_text)
        freq_letter[ch]++;
    
    for (char ch : magazine_text)
    {
        if(freq_letter.find(ch) != freq_letter.end())
        {
            if(--freq_letter[ch] == 0)
                freq_letter.erase(ch);
                
            if(freq_letter.size() == 0)
                return true;
        }
    }
    
    return false;
}

int main()
{
    cout << isPossible("defxf","dddddeeeefffaaa") << endl;   
    return 0;
}