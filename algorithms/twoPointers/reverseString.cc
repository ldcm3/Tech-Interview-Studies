/* 

    Reverse string in-Place

*/

#include <iostream>

using namespace std;

void reverseStr(string& str)
{
    size_t startIdx = 0;
    size_t endIdx = str.length() - 1;
    
    while(startIdx < endIdx)
    {
        swap(str[startIdx],str[endIdx]);
        ++startIdx;
        --endIdx;
    }
    
}

int main()
{
    return 0;
}