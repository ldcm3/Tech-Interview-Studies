/**
 *  
 *  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    For example,
    Given [100, 4, 200, 1, 3, 2],
    The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
    
    Your algorithm should run in O(n) complexity.
 * 
 * 
 * 
 **/ 
 
 
 #include<iostream>
 #include<vector>
 #include<unordered_set>
 
 using namespace std;

 int longestContainedInterval(const vector<int>& A)
 {
     unordered_set<int> entries(A.begin(),A.end());
     
     int max_interval = 0;
     
     while (!entries.empty())
     {
         int x = *entries.begin();
         entries.erase(x);
         
         // finds Lower bound of the largest range containing x
         int lower_bound = x - 1;
         while (entries.count(lower_bound))
        {
            entries.erase(lower_bound);
            --lower_bound;
        }
        
        int upper_bound = x + 1;
        while (entries.count(upper_bound))
        {
            entries.erase(upper_bound);
            ++upper_bound;
        }
        
        max_interval = max(max_interval, upper_bound - lower_bound - 1);
        
        
     }
     
     return max_interval;
 }
 
 int main()
 {
     return 0;
 }