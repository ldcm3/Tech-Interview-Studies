#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, size_t low, size_t high)
{
   int pivot = arr[high];
   size_t wall = low - 1;
   
   for(size_t i = low; i < high ; ++i)
   {
       if (arr[i] <= pivot)
       {
            swap(arr[i],arr[wall]);
            ++wall;

       }
   }
   
   swap(arr[wall],arr[high]);
   return wall ;
    
}

void quickSort(vector<int>& arr, size_t low, size_t high)
{
    if (low < high)
    {
        size_t wall = partition(arr,low,high);
        quickSort(arr,low,wall - 1);
        quickSort(arr,wall + 1,high);
    }
}

int main()
{
    // vector<int> unsortedArr {3,2,7,1,2,4,3};
    vector<int> unsortedArr = {5,2,1,4,3,7};

    quickSort(unsortedArr, 0 , unsortedArr.size() - 1);
    
    for (auto &n : unsortedArr)
        cout << n << " ";
        
    cout << endl;
    return 0;
}