#include<iostream>
#include<list>
#include <vector>

/*

    Given a Binary tree, find the lists of all the nodes at each depth
*/

using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

struct node* addNode(int val)
{
    node *newNode = new node;
    newNode->data = val;
    
    return newNode;
}

void listOfDep(node *root,int level, vector<vector <int> > &ans)
{
    // In-Order traversal
    if(!root)
        return;
    
    listOfDep(root->left,level+1,ans);
    
    vector<int> tmp;
    
    while (ans.size() <= level)
    {
        ans.push_back(tmp);        
    }
    
    ans[level].push_back(root->data);

    listOfDep(root->right,level+1,ans);

}

int main()
{
    node *root  = new node;
    root = addNode(1);
    root->left = addNode(2);
    root->right = addNode(3);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->right->left = addNode(6);
    root->right->right = addNode(7);
    
    vector<vector<int> > ans;
    

    listOfDep(root, 0, ans);
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "LEVEL : " << i << endl;
        for(int j = 0; j < ans[i].size() ; j++)
        {
            cout << ans[i][j] << " ";
        }
        
        cout << endl;
    }
    return 0;
}