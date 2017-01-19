#include <iostream>
#include <unordered_map>
#include <unordered_set>


using namespace std;

bool hasPermutationPalindrome(const string& str)
{
    unordered_set<char> letterFreq;

    for (char ch : str)
    {
        if (letterFreq.find(ch) != letterFreq.cend())
            letterFreq.erase(ch);
        else
            letterFreq.insert(ch);
    }
    
    return letterFreq.size() <= 1 ? true : false;
}

int main()
{
    cout << hasPermutationPalindrome("aab") << endl;
    return 0;
}