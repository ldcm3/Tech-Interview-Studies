#include <iostream>
#include <vector>

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int> &A)
{
    vector<int> productsOfAllIntsExceptAtIndex;
    size_t len = A.size();
    int productLeftToRight = 1;

    // Left to right
    for (size_t i = 0 ;i < len; ++i)
    {
        productLeftToRight *= A[i];
        productsOfAllIntsExceptAtIndex.push_back(productLeftToRight);
    }

    int productRightToLeft = 1;

    // right to Left
    for (size_t i = len - 1; i >= 0; --i)
    {
        if (i != 0)
        {
            productsOfAllIntsExceptAtIndex[i] = productRightToLeft * productsOfAllIntsExceptAtIndex[i - 1];
        }
        else
            productsOfAllIntsExceptAtIndex[i] = productRightToLeft;

        productRightToLeft *= A[i];
    }

    return productsOfAllIntsExceptAtIndex;
}

int main()
{
    const vector<int> A {1,7,3,4};

    vector <int> productsOfAllIntsExceptAtIndex = getProductsOfAllIntsExceptAtIndex(A);

    for (auto i : productsOfAllIntsExceptAtIndex)
        cout << i << " ";

    cout<< endl;


    return 0;
}
