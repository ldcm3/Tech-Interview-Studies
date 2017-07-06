/*
    We have an array arr[0 . . . n-1]. We should be able to
    
1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1

2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

    Consider that number of of query and updates are equal. 


    SOLUTION:
    
        Use a Segmented Tree to make both operations in O(logn) 
        
        nums = [2,4,5,7,8,9]
        
                        35
                        / \
                      6     29
                    /   \   /  \ 
                   2     4  12   17
                            / \  / \
                           5  7  8  9 
                           
        segTree = [35,6,29,2,4,12,17,5,7,8,9]
*/

#include<iostream>
#include<vector>

using namespace std;

class rangeSumQuery{
    
public:
    vector<int> segTree;
    int n;
    
    rangeSumQuery (vector<int>& nums)
    {
        if (nums.size() > 0)
        {
            n = nums.size();
            segTree.reserve (n * 2);
            buildTree(nums, 0, n - 1, 0);
        }
    }
    
    void buildTree (vector<int>& nums,int l, int h, int pos)
    {
        if (l == h)
        {
            segTree[pos] = nums[l];
            return;
        }
        
        int mid = l + (h - l) / 2;
        
        buildTree (nums,l, mid, 2*pos + 1);
        buildTree (nums,mid + 1,h, 2*pos + 2);
        
        segTree[pos] = segTree[2*pos + 1] + segTree[2*pos + 2];
    }
    
    int query (int ql, int qh, int l, int h,int pos)
    {
        if (ql <= l && qh >= h) // completely inside range
            return segTree [pos];
        else if (l > qh || h < ql) // out range
            return 0;
        
        int mid = l + (h - l) / 2;
        
        return query (ql,qh,l,mid,2*pos + 1) + 
               query (ql,qh,mid + 1,h, 2*pos + 2);
        
    }
    
    void updateTree (int l,int h,int pos,int idx,int val)
    {
        if (l == h)
        {
            segTree[pos] = val;
            return;
        }
        
        int mid = l + (h - l) / 2;
        
        if (idx > mid)
            updateTree (mid + 1,h,2*pos + 2,idx,val);
        else if (idx <= mid)
            updateTree (l, mid,2*pos + 1,idx,val);
        
        // Propagate changes
        segTree[pos] = segTree[2*pos + 1] + segTree[2*pos + 2];
    }
    
    int rangeSum (int l,int h)
    {
        return query (l,h,0,n - 1,0);
    }
    
    void update (int idx, int val)
    {
        updateTree (0,n - 1,0,idx,val);
    }
};

int main()
{
    vector<int> nums = {0,9,5,7,3};
    rangeSumQuery sol (nums);
    cout << sol.rangeSum(4,4) << endl;
    cout << sol.rangeSum(2,4) << endl;
    cout << sol.rangeSum(3,3) << endl;
    sol.update(4,5);
    sol.update(1,7);
    sol.update(0,8);
    cout << sol.rangeSum(1,2) << endl;
    sol.update(1,9);
    cout << sol.rangeSum(4,4) << endl;
    sol.update(3,4);

    return 0;
}