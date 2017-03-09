/*
    Requirements
    
    - Class that represents contacts.
    - Each contact is a string stored in a list (which might contains duplicates)
    - Two contacts should be equal if they contains the same set of strings, regardless 
    of the ordering of the strings within the underlying list.
    
    Solution: 
    
    - The hash function should depend on the strings present, but not their ordering
    - It should consider only one copy if a string appears in duplicate form (use XOR hashcode for individual entries)

    - Time Complexity is O(n)
    - Hash Codes are often cached for performance (must be cleared if hash function is updated)
*/


#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct ContactList {
    // Equal function for Hash 
    bool operator==(const ContactList& that) const {
        return unordered_set<string>(names.begin(),names.end()) == 
                unordered_set<string>(that.names.begin(), that.names.end());
    }
    
    vector<string> names;
};

// hash Function for Contact List
struct HashContactList {
    
    size_t operator()(const ContactList& contacts) const {
        
        size_t hash_code = 0;
        for (const string& name : unordered_set<string>(contacts.names.begin(),
                                                        contacts.names.end()))
        {
            hash_code ^= hash<string>()(name);
        }
        
        return hash_code;
    }
};

vector<ContactList> MergeContactLists(const vector<ContactList>& contacts)
{
    unordered_set<ContactList,HashContactList> unique_contacts(
        contacts.begin(),contacts.end());
    
    return {unique_contacts.begin(),unique_contacts.end()};
}

int main()
{
    return 0;
}
