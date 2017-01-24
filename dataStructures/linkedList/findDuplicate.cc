#include <iostream>
#include <vector>

using namespace std;


unsigned int findDuplicate (const vector<unsigned int>& A)
{
    unsigned int nodeInCycle = A.size();
    
    //  Get inside a cycle    
    for (size_t i = 0; i < A.size(); ++i)
        nodeInCycle = A[nodeInCycle - 1]; // step to next node    
        
    // Find length of the cycle
    unsigned int startPosition = nodeInCycle;
    size_t lenOfCycle = 1;
    
    nodeInCycle = A[nodeInCycle - 1];
    
    while (nodeInCycle != startPosition)
    {
        ++lenOfCycle;
        nodeInCycle =  A[nodeInCycle - 1];
    }
    
    // Find the start of the Cycle
    
    // 1) Walk lenOfCycle steps from head
    
    nodeInCycle = A.size(); // head
    
    for (size_t i = 0; i < lenOfCycle; ++i)
    {
        nodeInCycle = A[nodeInCycle - 1];
    }
    
    unsigned int curNode = A.size(); 
    
    // 2) find beginning of cycle
    
    while(curNode != nodeInCycle)
    {
        curNode = A[curNode- 1];
        nodeInCycle = A[nodeInCycle - 1];
    }
    
    return curNode; 
}


int main()
{
    const vector<unsigned int> vec {3,2,1,1,4}; 
    
    cout << findDuplicate(vec) << endl;
    return 0;
}