/*
    You are given a log file containing search queries.
    Each query is a string separeted by newlines.
    
    Compute the k string that appears most frequently in the array
    
*/

#include<iostreamm>
#include<vector>
#include<unordered_map>
#include<unordered_set>


using namespace std;

int main()
{
    /*
    
    - Mantain a min-heap of the k most frequent strings
    - Compare the frequency of the subsequent strings with the string at the root
    of the min-heap
    - if the new string freq is greater than the root-str, pop root-str and 
    push the new str to the heap
    
    O(n + mlogk) where n is the number of strings and m the number of distinct strings
    
    */
    return 0;
}