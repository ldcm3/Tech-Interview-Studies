#include<iostream>

using namespace std;

void reverseWordUtil(string &str)
{
    size_t start = 0;
    size_t end = str.length() - 1;
    
    while(start < end)
    {
        swap(str[start], str[end]);
        ++start;
        --end;
    }
}

void reverseWords(string &str)
{
    reverseWordUtil(str);
    string tmp = "";
    size_t startWord = 0;
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (str[i] != ' ')
        {
            tmp += str[i];
        }
        else
        {
            reverseWordUtil(tmp);
            str.replace(startWord,i - startWord, tmp);
            startWord = i + 1;
            tmp = "";
        }
    }

    reverseWordUtil(tmp);
    str.replace(startWord,str.length() - startWord, tmp);
}

int main()
{
    string str = "find you will pain only go you recordings security the into if";
    reverseWords(str);
    cout << str << endl;
    
    return 0;
}