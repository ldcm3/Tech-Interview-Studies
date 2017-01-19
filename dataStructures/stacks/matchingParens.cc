/*


*/

#include <iostream>

using namespace std;

int indexOfMatchParen(const string& sentence, size_t openingParens)
{
    size_t openNestedParens = 1;
    size_t idx = openingParens + 1;
    while (openNestedParens > 0 && idx < sentence.length() )
    {
        if (sentence[idx] == '(')
            ++openNestedParens;
        else if(sentence[idx] == ')')
            --openNestedParens;
        
        ++idx;
    }
    
    return (idx - 1);
}

int main()
{
    const string str = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
    cout << indexOfMatchParen(str,10) << endl;
    return 0;
}