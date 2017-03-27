#include<iostream>
#include <vector>
using namespace std;

void generateAllPermutations(string str,size_t idx,vector<string> &permutations)
{
    if(idx == str.length())
    {
        permutations.push_back(str);
        return;
    }
    
    for (size_t i = idx; i < str.length(); ++i)
    {
        swap(str[i],str[idx]);
        generateAllPermutations(str,idx + 1, permutations);
        swap(str[i],str[idx]);
    }
    
    
}
int main()
{
    string str = "1234";
    vector<string> perms;
    
    generateAllPermutations(str,0,perms);
    
    for (string s : perms)
        cout << s << endl;
    return 0;
}