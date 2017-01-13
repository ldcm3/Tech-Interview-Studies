/* 

    Implementation of c++ Binary Search lower_bound 
    
    
    template< class ForwardIt, class T >
    ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );

    Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.

*/

#include<iostream>
#include<vector>

using namespace std;

int lowerBound(int start,int end, int value, vector<int> &vec)
{
    
    int mid;
    int ans = -1;
    
    while (start < end)
    {
        mid = start + ((end - start) / 2); // avoid overflow
        
        if (vec[mid] > value)
        {
            ans = vec[mid];
            end = mid ;   
        }
        else
            start = mid + 1;
        
        mid = start + ((end - start) / 2);
    }
    
    return ans;
    
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    
    cout << lowerBound(0,vec.size() - 1, 10,vec) << endl;
    
    return 0;
}