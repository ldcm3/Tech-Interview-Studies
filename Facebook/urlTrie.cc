/* 

Store all the URLs that a crawler is visiting using a Trie.

Complexity:

The first layer has 26 nodes (and thus 26 characters), one for each possible starting character.
On the second layer, each of those 26 nodes has 26 children, for a total of 26^26 ans so on.

 O(26^n)

*/

#include<iostream>
#include<unordered_map>

using namespace std;


class TrieNode
{
  private:
    unordered_map<char, TrieNode*> nodeChildren;

  public:

    TrieNode():
      nodeChildren(){}

    ~TrieNode()
    {
      for(auto& v : nodeChildren)
      {
        delete v.second;
      }
    }

    bool hasChildNode(char ch) const
    {
      return nodeChildren.find(ch) != nodeChildren.cend();
    }

    void makeChildNode(char ch)
    {
      nodeChildren.insert(make_pair(ch,new TrieNode()));
    }

    TrieNode* getChildNode(char ch)
    {
      if (hasChildNode(ch))
        return nodeChildren.find(ch)->second;
      else
        return nullptr;
    }
  };

  class Trie
  {
    private:
      static constexpr char END_OF_WORD_MARKER = '*';
      TrieNode* rootNode;

    public:
        Trie():
          rootNode(new TrieNode()){};

        ~Trie()
        {
          delete rootNode;
        }

        bool checkPresentAndAdd(const string& word)
        {
          bool isNewWord = false;
          TrieNode* curNode = rootNode;

          for (const char ch : word)
          {
            if (!curNode->hasChildNode(ch))
            {
              isNewWord = true;
              curNode->makeChildNode(ch);
            }
            curNode = curNode->getChildNode(ch);
          }

          if(!curNode->getChildNode(END_OF_WORD_MARKER))
          {
            isNewWord = true;
            curNode->makeChildNode(END_OF_WORD_MARKER);
          }

          return isNewWord;
        }
  };



int main()
{
   Trie urlStorage;
   
   cout << urlStorage.checkPresentAndAdd("www.google.com") << endl;
   cout << urlStorage.checkPresentAndAdd("www.google.com/maps") << endl;
    cout << urlStorage.checkPresentAndAdd("www.google.com") << endl;

    return 0;
}