/*


Write an efficient function that checks whether any permutation ↴ of an input string is a palindrome ↴ .

*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool permutIsPalindrome(const string& word)
{
  unordered_set<char> unpairedChars;
  
  for(char ch : word)
  {
    if(unpairedChars.find(ch) != unpairedChars.cend())
        unpairedChars.erase(ch);
    else
        unpairedChars.insert(ch);
  }
  
  return unpairedChars.size() <= 1;
}


int main()
{
  cout << permutIsPalindrome("abaa") << endl;
  return 0;
}
