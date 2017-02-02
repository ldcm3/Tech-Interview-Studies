/*
    Given an array of integers, we have to find two elements whose XOR is maximum.
    
    Given a Y, find maximum XOR of Y with all numbers that have been inserted till now
    
    OBS:  under the assumption that integers take fixed number of bits to store
*/

#include<iostream>
#define INT_SIZE 32
using namespace std;

class TrieNode
{
    public:
        int bit; // 0 or 1
        TrieNode* left; // point to 0
        TrieNode* right; // point to 1
        
        TrieNode(int b):
            bit(b),
            left(nullptr),
            right(nullptr)
            {}
        
        ~TrieNode()
        {
            delete left;
            delete right;
        }
        
};

class Trie
{
    public:
        TrieNode* root; // root node
        
        Trie():
            root(new TrieNode(-1))
            {}
        ~Trie()
        {
            delete root;
        }
        
        void insert(int number)
        {
            TrieNode* cur = root;
            
            // Start from MSB, insert all bits into trie
            for (int i = INT_SIZE - 1; i>=0; --i)
            {
                bool val = number & (1 << i);
                
                if (val) // bit is 1
                {// check if a bit 0 is possible in this position
                        cur->right = new TrieNode(1);
                        
                    cur = cur->right;
                }
                else // bit is 0
                {
                    if(!cur->left)
                        cur->left = new TrieNode(0);
                    
                    cur = cur->left;
                }
            }
        }
        
        int maxXOR(int n)
        {
            TrieNode* cur = root;
            int ans = 0;
            
            // If current bit is b try to find !b in the Trie for max XOR
            for(int i = INT_SIZE - 1; i >= 0; --i)
            {
                int val =  n & (1 << i);

                if (val) // bit == 1
                {
                    if(cur->left) // check if a bit 0 is possible at this pos
                        cur = cur->left;
                    else
                        cur = cur->right;
                }
                else // bit == 0
                {
                    if // check if a bit 1 is possible at this position 
                        cur = cur->right;
                    else
                        cur = cur->left;
                }
                ans += (val^ (cur->bit << i));
            }
            
            cout << ans;
        }
};


int main()
{
    Trie* root = new Trie();
    root->insert(5);
    root->insert(3);
    root->insert(9);

    root->maxXOR(3);
    cout << endl;
    return 0;
}