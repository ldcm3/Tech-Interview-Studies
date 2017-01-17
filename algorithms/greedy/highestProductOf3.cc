#include<iostream>
#include<vector>

using namespace std;

int highestProduct(const vector<int> &A)
{
    int case1,case2,case3;
    int a,b,c;
    a = A[0];
    b = A[1];
    c = A[2];
    case1 = a*b;
    case2 = a*c;
    case3 = b*c;

    int highestProduct = a*b*c;

    for (size_t i = 3; i < A.size(); ++i)
    {
        if (case1 * A[i] > highestProduct)
        {
            c = A[i];
        }
        else if(case2 * A[i] > highestProduct)
        {
            b = A[i];
        }
        else if(case3 * A[i] > highestProduct)
        {
            a = A[i];
        }

        case1 = a*b;
        case2 = a*c;
        case3 = b*c;
        highestProduct = a*b*c;

    }


    return highestProduct;
}

int main()
{
    const vector<int> A { 1, -4, 3, -6, 7, 0 };
    
    cout << highestProduct(A) << endl;
    
    return 0;
}
