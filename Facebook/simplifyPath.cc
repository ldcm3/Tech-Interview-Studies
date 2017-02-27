/*
Given an absolute file path (Unix-style), shorten it to the format /<dir1>/<dir2>/<dir3>/....

Here is some info on Unix file system paths:

/ is the root directory; the path should always start with it even if it isn't there in the given path;
/ is also used as a directory separator; for example, /code/fights denotes a fights subfolder in the code folder in the root directory;
this also means that // stands for "change the current directory to the current directory"
. is used to mark the current directory;
.. is used to mark the parent directory; if the current directory is root already, .. does nothing.
Example

For path = "/home/a/./x/../b//c/", the output should be
simplifyPath(path) = "/home/a/b/c".

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


string simplifyPath(std::string path) {
    string tmp;
    stack<string> s;
    stringstream in(path);

    while(getline(in,tmp,'/'))
    {
        if(tmp == "" || tmp == ".")
            continue;
        else if(tmp == ".." && !s.empty())
            s.pop();
        else if(tmp != "..")
            s.push(tmp);
    }

    string res = "";

    while(!s.empty())
    {
        res = '/' + s.top() + res;
        s.pop();
    }

    return res.size() == 0? "/" : res;
}


int main()
{
    return 0;
}