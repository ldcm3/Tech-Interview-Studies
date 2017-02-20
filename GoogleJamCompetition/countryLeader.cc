#include<iostream>
#include<vector>
#include<fstream>
#include <unordered_set>
using namespace std;
 
ifstream in ("input.txt");
ofstream out ("output.txt");

int countDiffLett(const string &str)
{
    unordered_set<char> dic;
    int cnt = 0;   
    for(char ch : str)
    {
        if(ch == ' ')
            continue;
            
        if (dic.find(ch) == dic.end())
        {
            dic.emplace(ch);
            ++cnt;
        }
        
    }
    
    return cnt;
}

int main()
{
    int testCases;
    in >> testCases;
    
    for(int i = 1; i <= testCases; ++i)
    {
        int numWords;
        string word, strCur;
        int differentLetter = 0;
        int maxCur = 0;
        
        in >> numWords;
        
        in.ignore();
        
        while(numWords--)
        {
            getline(in,word);
            cout << word << endl;
            
            int differentLetter = countDiffLett(word);
            
            if (differentLetter > maxCur)
            {
                maxCur = differentLetter;
                strCur = word;
            }
            else if (differentLetter == maxCur)
            {
                strCur = min(word,strCur);
            }
            
        }
       
        cout << "processing ..." << endl; 
        out << "Case #" << i << ": " << strCur << endl;
       
    }
    return 0;
}