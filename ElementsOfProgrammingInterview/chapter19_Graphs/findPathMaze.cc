/*

    Given a 2D array of black and white entries representing a maze with designated
    entrance and exit points, find a path from the entrance to the exit, if one exists.
    
    Time Complexity is the same for DFS, O(V + E)
*/

#include<iostream>
#include<vector>
#include<array>

using namespace std;

#define BLACK true
#define WHITE false


struct Coord
{
    int x,y;
    bool operator==(const Coord& that) const
    {
        return that.x == x && that.y == y;
    }
    Coord(int i,int j): x(i),y(j){}
};

bool isFeasible(const Coord& next, const vector<vector<bool>>& maze)
{
    return next.x < maze.size() && next.x >= 0 && 
           next.y < maze[next.x].size() && next.y >= 0 &&
           maze[next.x][next.y] == WHITE;
}

bool searchPathHelper(vector<vector<bool>>& maze,const Coord& curr,
                    const Coord& e, vector<Coord>& path )
{
    path.emplace_back(curr);
    
    if (curr == e)
        return true;
    
    maze[curr.x][curr.y] = BLACK; // mark node as visited
    
    const array<array<int,2>, 4> kShift = {{{0,1}, {0,-1}, {1,0}, {-1,0}}};
    
    for (const array<int, 2>&s : kShift)
    {
        Coord next(curr.x + s[0], curr.y + s[1]);
        if (isFeasible(next,maze))
            if (searchPathHelper(maze,next,e,path))
                return true;
            else
                path.pop_back();
    }
    
    return false;
}

vector<Coord> searchPath(vector<vector<bool>>& maze, const Coord& start,
                        const Coord& end)
{
    vector<Coord> path; // path from start to end if there is one
    
    if (!searchPathHelper(maze,start,end,path))
    {
        path.pop_back();
    }

    return path;
}

int main()
{
    vector<vector<bool>> maze { { BLACK, WHITE, WHITE },
                                { BLACK, WHITE, BLACK },
                                { WHITE, WHITE, BLACK }};
                                
    Coord startPoint(2,0);
    Coord endPoint(0,2);
    
    vector<Coord> path = searchPath(maze,startPoint,endPoint);
    
    if (path.size())
    {
        for (const auto& p : path)
        {
            cout << "(" << p.x << " ," << p.y << ")" << endl; 
        }
    }
    else
        cout << "path is not possible" << endl;
    return 0;
}