#include<iostream>
#include<vector>
#include<stack>

using namespace std;

 
using namespace std;
 
void QuickSort(vector<int>& input, size_t left, size_t right) {
    size_t p = (left + right) / 2;
    int pivot = input[p];
    
    // Move elements smaller than the pivot to the left side
    size_t l = left;
    size_t r = right;
    
    while (l <= r) {
        while (input[l] < pivot)
            ++l;
        while (input[r] > pivot)
            --r;
        if (l <= r) {
            int tmp = input[l];
            input[l] = input[r];
            input[r] = tmp;
            ++l;
            --r;
        }
    }
    
    if (left < r) {
        QuickSort(input, left, r);
    }
    
    if (l < right) {
        QuickSort(input, l, right);
    }
    
}
int main()
{
    
    vector<int> test = {5,2,1,4,3,7};
    QuickSort(test,0,test.size() - 1);

    for (auto x : test)
        cout << x << " ";
    cout << endl;
    
    return 0;
}