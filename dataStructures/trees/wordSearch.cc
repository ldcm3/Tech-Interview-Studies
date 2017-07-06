
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TrieNode{
    char ch;
    unordered_map<char,TrieNode> children;
    
    TrieNode(char c): ch(c) {};
};

void insertTrie(TrieNode node, string word)
{
    for (char ch : word)
    {
        if (node.children.find(ch) == node.children.end())
        {
            TrieNode child = new TrieNode(ch);
            node.children[ch] = child;
            node = child;
        }
        node = node.children[ch];
    }
    
    if (node.children.find('*') == node.children.end())
    {
        TrieNode child = new TrieNode('*');
        node.children['*'] = child;
        node = child;
    }
    
}

vector<string> ans; 

void dfs (int i , int j,vector<vector<bool> >& check,vector<vector<char>>& board,TrieNode node, string curWord)
{
    if (check[i][j])
        return ;
    
    char ch = board[i][j];
    check[i][j] = true; // mark visited;
    
    if (node.children.find(ch) != node.children.end())
    {
        node = node.children[ch];
        curWord += ch;
        if (node.children.find('*') != node.children.end())
        {
            ans.push_back(curWord);
        }
        
        if (i + 1 < board.size())
            dfs(i + 1, j, check,board,node,curWord);
        
        if (j + 1 < board[0].size())
            dfs(i,j+1,check,board,node,curWord);
        
        if (i - 1 >= 0)
            dfs(i - 1, j, check, board, node, curWord);
        
        if (j - 1 >= 0)
            dfs(i,j - 1, check,board,node,curWord);
    }
    
    return;
    
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    
    TrieNode root = new TrieNode('#');
    
    for (string word : words)
    {
        insertTrie(root,word);
    }
    
    vector<vector<bool> > (board.size(), vector<bool> (board[0].size(), false));
    
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            vector<vector<bool> > check (board.size(), vector<bool> (board[0].size(), false));
            dfs(i,j,check,board,root,"");
        }
    }
    
    return ans;
}


int main()
{
    
    return 0;
}