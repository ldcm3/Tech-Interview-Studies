#include<iostream>
#include<unordered_map>


using namespace std;

class TrieNode
{
    public:
        unordered_map<char,TrieNode*> nodeChildren;
        
        bool hasChildNode (char ch) const
        {
            return nodeChildren.find(ch) != nodeChildren.cend();
        }
        

        TrieNode* makeChildNode(char ch)
        {
           nodeChildren.insert(make_pair(ch,new TrieNode()));
        }
        
        TrieNode* getChildNode(char ch)
        {
            auto it = nodeChildren.find(ch);
            if (it == nodeChildren.cend())
                return nullptr;
            
            return it->second;
        }
};

class Trie
{
    private: 
        TrieNode* root;
         static constexpr char END_OF_WORD_MARKER = '\0';
        
    public:
        Trie():
            root(new TrieNode())
        {}
        
        ~Trie()
        {
            delete root;
        }
        
       bool checkPresenteAndAdd(const string& str)
       {
           TrieNode* curNode = root;
           bool isNewUrl = false;
           
           for (const char ch : str)
           {
               if (!curNode->hasChildNode(ch))
               {
                   isNewUrl = true;
                   curNode->makeChildNode(ch);
               }
               
               curNode = curNode->getChildNode(ch);
           }
           
            if (!curNode->hasChildNode(END_OF_WORD_MARKER))
            {
                curNode->makeChildNode(END_OF_WORD_MARKER);
                isNewUrl = true;
            } 
            
            return isNewUrl;
       }
};

int main()
{
    
    return 0;
}