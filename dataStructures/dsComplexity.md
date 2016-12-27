## Data Structures Review

 insert/update/delete operations.

### Arrays 
    * Stores data elements based on an sequential, most commonly 0 based, index.
    * Optimal for indexing; bad at searching, inserting, and deleting (except at the end).
    * Are static in size, meaning that they are declared with a fixed size.
    
    * Big O efficiency:

        - Indexing: O(1), Dynamic array: O(1)
        - Search: O(n)
        - Optimized Search: O(log n)
        - Insertion: Linear array: n/a Dynamic array: O(n)
    
### Vector

    *  A vector is a dynamic array, whose size can be increased, where as an array size can not be changed.
    * To avoid incurring the cost of resizing many times, dynamic arrays resize by a large amount, such as doubling in size, and use the reserved space for future expansion.
    * As n elements are inserted, the capacities form a geometric progression. Expanding the array by any constant proportion a ensures that inserting n elements takes O(n) time overall
    * Each insertion takes amortized constant time

### Linked Lists

    * Stores data with nodes that point to other nodes.
    * Nodes, at its most basic it has one datum and one reference (another node).
    * A linked list chains nodes together by pointing one node's reference towards another node.
    * Designed to optimize insertion and deletion, slow at indexing and searching.
    * Stack and Queue (double-linked), commonly implemented with linked lists but can be made from arrays too.
    
    * Big O efficiency
        - Indexing: Linked Lists: O(n)
        - Search: Linked Lists: O(n)
        - Optimized Search: Linked Lists: O(n)
        - Insertion: Linked Lists: O(1)

### Hash Tables
   
    * Stores data with key value pairs.
    * Hash functions return a unique address in memory for that data.
    * Designed to optimize searching, insertion, and deletion.
    * Hash collisions are when a hash function returns the same output for two distinct inputs.

    *Big O efficiency:

        * Indexing: O(1)
        * Search: O(1)
        * Insertion: O(1)
        
### Binary Trees

    * every node has at most two children.
    * There is one left and right child node.
    *Designed to optimize searching and sorting.
    * A degenerate tree is an unbalanced tree, which if entirely one-sided is a essentially a linked list.

    * Big O efficiency:
        - Indexing: Binary Search Tree: O(log n)
        - Search: Binary Search Tree: O(log n)
        - Insertion: Binary Search Tree: O(log n)

