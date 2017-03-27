/*
    Write a program which returns all distinct nonataccking placements of n 
    queens on a nXn chessboard
*/

#include<iostream>
#include<vector>
#include<array>
#include<stack>

using namespace std;

void solveQueens(int n,int row,vector<int> cur, vector<vector<int>>& res);

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> res; 
    solveQueens(n,0,{}, res);
    
    return res;
    
}

bool isValid (vector<int> board)
{
    int col = board.size() - 1;
    int row = board.back();
    
    for (int i = 0; i < col; ++i)
    {
        int checkRow = board[i];
        
        if (checkRow == row || (col - i) == abs(row - checkRow))
            return false;
    }
    
    return true;
}

void solveQueens(int n,int row,vector<int> cur, vector<vector<int>>& res)
{
    if (n == row)
    {
        res.push_back(cur);
        return ;
    }
    
   for (int col = 0; col < n; ++col)
   {
        cur.push_back(col);
        if (isValid(cur))
            solveQueens(n,row+1,cur,res);
        cur.pop_back();
   }
   
}


int main()
{
    vector<vector<int>> possibleBoards = nQueens(4);
    
    for (auto p : possibleBoards)
    {
        for (auto r : p)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}