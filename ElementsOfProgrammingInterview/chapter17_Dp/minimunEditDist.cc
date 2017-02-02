/*
    Find minimum number of edits (insert,delete, substituition) to transform 
    a string A into B.
    
    "Saturday" -> "Sundays"
    
    minChanges = 4

*/

#include<iostream>
#include <algorithm>

using namespace std;


int minDis(int A,int B,int C)
{
    return min(min(A,B),C);
}
int minEditChanges(const string& A, const string& B)
{
    vector<vector<int>> distanceBetweenPrefixes(A.size() + 1,
                                                vector<int>(B.size() + 1, 0));
                                                
    // When A or B is emptym, the min number of edits is equal the size of
    // the current string
    
    for (int i = 0;i <= A.size(); ++i)
        distanceBetweenPrefixes[i][0] = i;
    
    for (int j = 0; j <= B.size(); ++j)
        distanceBetweenPrefixes[0][j] = j ;
    
    
    for (int i = 1; i <= A.size(); ++i)
    {
        for (int j = 1; j <= B.size(); ++j)
        {
            if (A[i- 1] == B[j - 1])
                distanceBetweenPrefixes[i][j] = distanceBetweenPrefixes[i-1][j-1];
            else   
                distanceBetweenPrefixes[i][j] += minDis(distanceBetweenPrefixes[i][j-1],  //insert
                                            distanceBetweenPrefixes[i-1][j],                // delete
                                            distanceBetweenPrefixes[i-1][j-1]) + 1;         // substituition
        }
    }
    
    return distanceBetweenPrefixes[A.size()][B.size()];
                                            
}

int main()
{
    
    cout << minEditChanges("Saturday","Sunday") << endl;
    return 0;
}