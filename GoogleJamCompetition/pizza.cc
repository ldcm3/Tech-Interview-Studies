#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<fstream>
using namespace std;

ifstream in ("input.txt");
ofstream out ("output.txt");

struct PizzaSlice
{
    pair<int,int> r;
    pair<int,int> c;
    
    PizzaSlice(int r1,int r2,int c1,int c2): 
        r(make_pair(r1,r2)),
        c(make_pair(c1,c2)) {}
};

struct NumberIngred
{
    int m;
    int t;
    
    NumberIngred(int mushroon, int tomatoe): 
        m(mushroon),
        t(tomatoe) {}
};


unordered_map<PizzaSlice,NumberIngred> preProcessPizza(
                                            const vector<vecto<char>>& pizza, int H, int L)
{
    int minElems = L*2;
    unordered_map<PizzaSlice,NumberIngred> pre;
    
    // Horizontal search
    for(int len = minElems; len <= H; ++len)
    {
        for(int i = 0 ; i < pizza.size(); ++i)
        {
            int m = 0;
            int t = 0;
            
            for (int j = 0; j < len; ++j)
            {
                if(pizza[i][j] == 'T')
                    ++t;
                else
                    ++m;
            }
            
            PizzaSlice prevS(i,i,0,len-1);
            NumberIngred prevI(m,t);
            
            pre.insert(make_pair(prevS,prevI));
            
            for(int j = 1 ;j < pizza[i].size() - len + 1; ++j)
            {
                PizzaSlice newSlice(i,i,j,j + len - 1);
                
                m = prevI.m;
                t = prevI.t;
                if(pizza[i][j + len - 1] == 'T')
                    ++t;
                else
                    ++m;
                
                pizza[i][j - 1] == 'T'? --t : --m;
                
                NumberIngred newIngred(m,t);
                PizzaSlice newSlide(i,i,j,j +len-1);
                prevI = newIngred;
                
                pre.insert(make_pair(newSlide,newIngred));
            }
        }
    }
    
    return pre;
    
    
}


void pizzaGetData()
{
    int R,C,L,H;
    
    in >> R >> C >> L >> H;
    
    vector<vector<char>> pizza;
    

    for(int i = 0; i < R; ++i)
    {
        string line;
        in >> line;
        vector<char> tmp;
        
        for(char cell : line)
        {
            tmp.push_back(cell);
        }
        
        pizza.push_back(tmp);
    }
    
    
    unordered_map<PizzaSlice,NumberIngred> pizzaTop;
    
    // Preprocess ingredients per slice of pizza
    pizzaTop = preProcessPizza(pizza, H, L);
   
}

int main()
{
    pizzaGetData();
    return 0;
}