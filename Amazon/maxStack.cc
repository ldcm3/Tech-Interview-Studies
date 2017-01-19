/*

    Access the largest element in a stack.

*/

#include<iostream>
#include <stack>

using namespace std;

class MaxStack
{
private:
    stack<int> values;
    stack<int> maxValues;

public:
    int push(int item)
    {
        values.push(item);

        if (maxValues.empty() || item >= maxValues.top())
            maxValues.push(item);

        return item;
    }

    int pop()
    {
        int item = values.top();
        values.pop();

        if (item == maxValues.top())
            maxValues.pop();

        return item;
    }

    int getMax() const
    {
        return maxValues.top();
    }
};
