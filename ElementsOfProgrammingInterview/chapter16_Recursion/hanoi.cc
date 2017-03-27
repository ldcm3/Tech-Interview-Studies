/*
    
*/

#include<iostream>
#include<vector>
#include<array>
#include<stack>

using namespace std;

void printSteps (int num_rings_to_move, array<stack<int>, 3>& pegs,
                int from_peg, int to_peg, int use_peg)
{
    if (num_rings_to_move > 0)
    {
        printSteps (num_rings_to_move - 1, pegs, from_peg, use_peg,to_peg);
        pegs[to_peg].push(pegs[from_peg].top());
        pegs[from_peg].pop();
        
        cout << "Move from peg " << from_peg << " to peg " << to_peg << endl;
        
        printSteps (num_rings_to_move - 1, pegs, use_peg, to_peg, from_peg);
    }
}

void computeTowerHanoi(int num_rings)
{
    array<stack<int>, 3> pegs; // 3 == numPegs
    
    // Initialize peg
    for (int i = num_rings; i >=1; --i)
    {
        pegs[0].push(i);
    }
    
    printSteps(num_rings,pegs,0,1,2);
}


int main()
{
    computeTowerHanoi(3);
    return 0;
}