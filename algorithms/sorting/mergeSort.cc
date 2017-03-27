/*
    O(nLogn) in all 3 cases (worst, average and best) 
    
    O(n) extra space
*/

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr,int l,int m,int r)
{
    vector<int> left (arr.begin() + l, begin(arr) + m + 1);
    vector<int> right (arr.begin() + m + 1, arr.begin() + r + 1);
    
    int idx = l;
    int i = 0, j = 0;
    
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            arr[idx++] = left[i++];
        else
            arr[idx++] = right[j++];
    }
    
    while (i < left.size())
    {
       arr[idx++] = left[i++]; 
    }
    
     while (j < right.size())
    {
       arr[idx++] = right[j++]; 
    }
    
    return;
}

void mergeSort (vector<int>& arr, int l, int r)
{
    if (l >= r)
        return;
    
    int m = l + (r-l)/2;
    
    mergeSort(arr,l,m);
    mergeSort(arr,m + 1,r);
    merge(arr,l,m,r);
}

int main()
{
    vector<int> tess = {5,4,3,2,1};
   
    mergeSort(tess,0,tess.size() -1);
    
    for (int x : tess)
        cout << x << " ";
    cout << endl;
    return 0;
}
