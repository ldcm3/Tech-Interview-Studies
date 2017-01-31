/*
    Replace all White entries in a matrix that cannot reach the boundary with Black
    
    Example:
    
    {
     {B,B,B,B},
     {W,B,W,B},
     {B,W,W,B},
     {B,B,B,B}
    }
     
    Should be encoded to:
    
    {
     {B,B,B,B},
     {W,B,B,B},
     {B,B,B,B},
     {B,B,B,B}
    }
    

*/

#include<iostream>
#include<deque>
#include<vector>
#include<queue>
#include<array>

using namespace std;

struct Coord
{
    int i,j;
};

// Prototype
void markBoundaryRegions(int i, int j, 
                        const vector<vector<char>>& board,
                        vector<deque<bool>>& visited);


void fillSorroundedRegions(vector<vector<char>>& board)
{
    if (board.empty())
        return;
        
    vector<deque<bool>> visited (board.size(),
                                deque<bool>(board.front().size(),false));
                                
    // Identify the regions that are reacheable via white path starting from
    
    // the first and last columns
    int lastCol = board.front().size() - 1;
    
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i][0] == 'W' && !visited[i][0])
            markBoundaryRegions(i,0,board,visited);
        
        if (board[i][lastCol] == 'W' && !visited[i][lastCol])
            markBoundaryRegions(i,lastCol,board,visited);
    }
    
    // the first and last rows
    int lastRow = board.size() - 1;
    
    for (int j = 0 ; j < board.front().size(); ++j)
    {
        if (board[0][j] == 'W' && !visited[0][j])
            markBoundaryRegions(0,j,board,visited);
        
        if (board[lastRow][j] == 'W' && !visited[lastRow][j])
            markBoundaryRegions(lastRow,j,board,visited); 
    }
    
    // Marks the sorrounded white regions as black
    for (int i = 1; i < board.size() - 1; ++i){
        for (int j = 1; j < board[i].size() - 1; ++j)
        {
            if(board[i][j] == 'W' && !visited[i][j])
            {    
                board[i][j] = 'B';
            }
        }
    }
}

void markBoundaryRegions(int i, int j, 
                        const vector<vector<char>>& board,
                        vector<deque<bool>>& visited)
{
    queue<Coord> q;
    q.emplace(Coord{i,j});
    visited[i][j] = true;
    
    while (!q.empty())
    {
        const Coord curr = q.front();
        q.pop();
        const static array<array<int,2>,4> kDirs = {
            {{0,1},{0,-1},{1,0},{-1,0}}
        };
        
        for (const array<int,2>&d : kDirs)
        {
            const Coord next = Coord{curr.i + d[0], curr.j + d[1]};
            if (next.i >= 0 && next.i < board.size() && 
                next.j >= 0 && next.j < board.front().size() &&
                !visited[next.i][next.j] && board[next.i][next.j] == 'W')
            {
                q.emplace(next);
                visited[next.i][next.j] = true;
            }
        }
    }
    
}

int main()
{
    vector<vector<char>> board {
     {'B','B','B','B'},
     {'W','B','W','B'},
     {'B','W','W','B'},
     {'B','B','B','B'}
    };
    
    fillSorroundedRegions(board);
    
    for(const auto& row : board)
    {
        for(const auto& ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    
    return 0;
}