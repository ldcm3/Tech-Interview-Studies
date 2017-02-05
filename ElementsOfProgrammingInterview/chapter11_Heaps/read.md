A heap ( also knows as a priority queue) is a specialized complete binary tree where the keys must satisfy the 
heap property - the key at each node is at least as great as the keys stored
at its children.

A heap can be implemented as an array where children of the node at index i 
are at indices 2i + 1 and 2i + 2.

Tips: 

     - Use a heap when you care about the largest and smallest elements
     - a Heap is a good choice whem you need to compute the k largest (use a min-heap)
        and the k smallest (use a max-heap)

## Complexity

    - Insertion : O(logn)
    - Lookup for the max(or min) element: O(1)
    - Delete the max(or min) element : O(logn)
    - Searching for arbitraty keys : O(n)