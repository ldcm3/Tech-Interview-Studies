/*
    O(nLogn) in all 3 cases (worst, average and best) 
    
    O(n) extra space
*/

#include<iostream>
#include<vector>

using namespace std;

int merge (vector<int>& arr,int l, int m, int r)
{
    
    vector<int> left (arr.begin() + l, arr.begin() + m + 1);
    vector<int> right  (arr.begin() + m + 1, arr.begin() + r + 1);
   
    int idx = l;
    int i = 0,j = 0;
    int cntInv = 0;
    
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            arr[idx++] = left[i++];
        else // inversion
        {
            cntInv += left.size() - i;
            arr[idx++] = right[j++];
        }
    }
    
    while (i < left.size())
        arr[idx++] = left[i++];
    
    while (j < right.size())
        arr[idx++] = right[j++];
        
    return cntInv;
    
}


int mergeSort(vector<int>& arr, int l, int r)
{
    if (l >= r)
        return 0;
    
    int mid = (l + r) / 2;
    int cntInv = 0;
    
    cntInv += mergeSort(arr,l,mid);
    cntInv += mergeSort(arr,mid + 1,r);
    cntInv += merge (arr,l,mid,r);
    
    return cntInv;
}

int main()
{
    // vector<int> tess = {5,4,3,2,1};
    // vector<int> tess = {2,4,1,3,5};
    vector<int> tess = {1, 20, 6, 4, 5};
    
    int cntInv = mergeSort(tess,0,tess.size() -1);
    
    for (int x : tess)
        cout << x << " ";
    cout << endl;
    
    cout << "Cnt Inv " << cntInv << endl;
    return 0;
    
}