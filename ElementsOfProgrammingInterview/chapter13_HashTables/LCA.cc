/*
    Compute LCA
    
    
    Solution using HashTable
    
    - O(D0 + D1) space and time 

*/

#include<iostream>
#include<vector>

using namespace std;

TreeNode* LCA(TreeNode* nodeA, TreeNode* nodeB)
{
    unordered_set<TreeNode*> nodes_on_path;
    
    
    // Alternating moving upwards from the two nodes and storing the nodes visited
    while(nodeA || nodeB)
    {
        if(nodeA)
        {
            // Unordered_set return a pair <iterator,bool(value added or not)>
            if(nodes_on_path.emplace(nodeA).second == false)
                return nodeA;
        }
        
        nodeA = nodeA->parent;
        
        if(nodeB)
        {
            if (nodes_on_path.emplace(nodeB).second == false)
                return nodeB;
        }
        
        nodeB = nodeB->parent;
        
    }
    
    return nullptr;
}

int main()
{
    return 0;
}