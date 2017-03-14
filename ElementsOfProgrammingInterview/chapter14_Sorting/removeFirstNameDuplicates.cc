/*

   
    
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Name {
    string firstName, lastName;
    
    bool operator==(const Name& that) const {
        return firstName == that.firstName;
    }
    
    bool operator<(const Name& that) const {
        return firstName < that.firstName;
    }
};

void eleminateDuplicate(vector<Name>& A)
{
    sort(A.begin(), A.end());
    
    A.erase(unique(A.begin(), A.end()), A.end());
}

int main()
{
    
    return 0;
}