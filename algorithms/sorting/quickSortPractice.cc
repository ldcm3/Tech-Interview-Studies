#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, int s, int e)
{
    int pivot = arr[e];
    int wall = s - 1;

    for (int i = s; i < e; ++i)
    {
        if (arr[i] <= pivot)
        {
            ++wall;
            swap(arr[i],arr[wall]);
        }
    }

    swap(arr[wall + 1], arr[e]);

    return wall + 1;
}

void quickSort(vector<int>& arr, int start, int end)
{
    if (end <= start)
        return ;

    int wall = partition(arr,start,end);
    quickSort(arr,start,wall - 1);
    quickSort(arr,wall+1,end);
    
}

int main()
{
    vector<int> unsortedArr {1,2};
    quickSort(unsortedArr, 0 , unsortedArr.size() - 1);
    
    for (auto &n : unsortedArr)
        cout << n << " ";
        
    cout << endl;
    return 0;
}