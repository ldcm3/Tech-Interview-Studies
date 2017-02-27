/*

    Multiply two big strings
    
*/
#include<iostream>
#include<vector>
using namespace std;

string multiplyTwoStrings(std::string s1, std::string s2) {

    int carry;
    string ans (s1.size() + s2.size() , '0');

    for(int i = s1.size()- 1; i >=0; --i)
    {
        carry = 0;
        
        for(int j = s2.size() - 1; j >= 0; --j)
        {
            int tmp = (ans[i + j + 1] - '0') + 
                        ((s1[i] - '0')*(s2[j] - '0'))
                        + carry;
            
            ans[i + j + 1] = tmp%10 + '0';
            carry = tmp / 10;
        }
        
        ans[i] += carry;
    }
    
    size_t startpos = ans.find_first_not_of('0');
    if ( string::npos != startpos)
        return ans.substr(startpos);
    else
        return "0";
}

int main()
{
    cout << multiplyTwoStrings("12313513","23124512") << endl;
    return 0;
}