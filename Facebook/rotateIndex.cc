/*

Write a function for finding the index of the "rotation point,"

COMPLEXITY:

    O(lgn) time and O(1) space, just like binary search.

We're assuming that our word lengths are bound by some constant
if they were bounded by a non-constant l, each of our string comparisons would cost O(l), 
for a total of O(l*lg(n))

*/


#include <iostream>
#include <vector>
#include <string> 

using namespace std;

bool isLesser(const string A,const string B)
{
  int i = 0;
  int j = 0;

  while(i < A.size() && j < B.size())
  {
    if (A[i] < B[j])
      return true;
    else if(A[i] > B[j])
      return false;

    ++i;
    ++j;
  }

  return A.size() < B.size()? true : false;

}

int rotateIndex(const vector<string> &words)
{
  size_t lowerBound = 0;
  size_t higherbound = words.size() - 1;
  size_t mid;
  

  while(lowerBound < higherbound)
  {
     
      mid = lowerBound + ((higherbound - lowerBound)/ 2);

      if(words[mid] > words[0])
        lowerBound = mid;
      else  
        higherbound = mid ;
        
      // if floor and ceiling have converged
    if (lowerBound + 1 == higherbound) {

    // between floor and ceiling is where we flipped to the beginning
    // so ceiling is alphabetically first
        break;
    }
    
  }

  return higherbound;
}

int main()
{

  const vector<string> words {
    "ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote", // <-- rotates here!
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage",
};

    

  cout << rotateIndex(words) << endl;
  return 0;
}
