/*

    Rotate the Matrix by 90 degrees
    
*/

#include<iostream>
#include<vector>

using namespace std;

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> m) {

    for (int layer = 0; layer < m.size()/2; ++layer)
    {
        int first = layer;
        int last = m.size() - layer - 1;
        for (int i = first; i < last; ++i)
        {
            int off = i - first;

            int top = m[first][i];
            
            // Top <- Left
            m[first][i] = m[last - off][first];

            // Left <- Bottom
            m[last - off][first] = m[last][last - off];

            // Bottom <- Right
            m[last][last - off] = m[i][last];

            // Right <- Top
            m[i][last] = top;
        }
    }
    
      for (auto x : m)
    {
        for (auto c : x)
            cout << c;
        cout << endl;
    }
    return m;
}

int main()
{
    vector<vector<int> > test = { {1,2,3},{4,5,6},{7,8,9} };
    rotateImage(test);
    return 0;
}