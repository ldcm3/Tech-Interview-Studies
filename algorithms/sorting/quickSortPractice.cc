#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, size_t low, size_t high)
{
    int pivot = arr[high];
    int wall = (low - 1);
    
    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++wall;
            swap(arr[wall],arr[j]);
        }
    }
    
    swap (arr[wall + 1], arr[high]);
    return (wall + 1);
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low >= high)
        return ;
    
    int pi = partition(arr, low, high);
    
    quickSort(arr,low, pi - 1);
    quickSort(arr,pi + 1,high);
}

int main()
{
    vector<int> unsortedArr {5,2,1,4,3,7};
    quickSort(unsortedArr, 0 , unsortedArr.size() - 1);
    
    for (auto &n : unsortedArr)
        cout << n << " ";
        
    cout << endl;
    return 0;
}