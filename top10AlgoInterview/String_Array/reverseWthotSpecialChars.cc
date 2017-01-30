/*
    Reverse an array without affecting special characters
    
    Input:   str = "a,b$c"
    Output:  str = "c,b$a"
    Note that $ and , are not moved anywhere.  
    Only subsequence "abc" is reversed

*/

#include<iostream>

using namespace std;

bool isAlphabet(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}

void reverse(string& str)
{
    size_t lowPointer = 0;
    size_t upperPointer = str.length() - 1;
    
    while (lowPointer < upperPointer)
    {
        if (!isAlphabet(str[lowPointer]))
            ++lowPointer;
        else if(!isAlphabet(str[upperPointer]))
            --upperPointer;
        else
        {
            swap(str[lowPointer],str[upperPointer]);
            ++lowPointer;
            --upperPointer;
        }
    }
}

int main()
{
    string str = "T133e*st";
    
    reverse(str);
    
    cout << str << endl;
    
    return 0;
}