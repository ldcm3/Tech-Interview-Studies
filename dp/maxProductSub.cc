#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

int findMin(int A,int B,int C)
{
    return min(min(A,B),C);
}

int findMax(int A,int B,int C)
{
    return max(max(A,B),C);
}

int maxProduct(const vector<int> &A) {
    
    int len = A.size(); 
    
    int dpmin[len + 1];
    int dpmax[len + 1];
    
    dpmin[0] = A[0];
    dpmax[0] = A[0];
    
    int maxx = A[0];
    
    for(int i =1 ;i < A.size(); i++)
    {
        dpmin[i] = findMin(A[i],A[i]*dpmin[i-1], A[i]*dpmax[i-1]);
        dpmax[i] = findMax(A[i],A[i]*dpmin[i-1], A[i]*dpmax[i-1]);
        
        maxx = max(dpmax[i],maxx);
    }
    
    return maxx;
    
}