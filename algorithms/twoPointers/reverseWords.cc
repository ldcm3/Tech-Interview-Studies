#include<iostream>

using namespace std;


void reverseWords(string& sentence) {
    
   reverse(sentence.begin(), sentence.end());

    size_t s = 0;
    size_t e;

    while((e = sentence.find(' ',s)) != string::npos)
    {
         reverse(sentence.begin() + s, sentence.begin() + e);
        s = e + 1;
    }
    
    reverse(sentence.begin() + s, sentence.end());

    return sentence;

}



int main()
{
    string str = "find you will pain only go you recordings security the into if";
    reverseWords(str);
    cout << str << endl;
    
    return 0;
}