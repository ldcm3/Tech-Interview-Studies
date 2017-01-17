 /*
 
Write a function that takes a vector of cake type objects and a weight capacity,
and returns the maximum monetary value the duffel bag can hold. 
 
 */
 #include <iostream>
 #include <vector>
 
 using namespace std;
 
class CakeType
{
public:
    size_t weight_;
    long long value_;

     CakeType(size_t weight = 0, long long value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};
 
int maxDuffelBagValue(const vector<CakeType> &cakeTypes, size_t capacity)
{
    vector<long long> maxValuesAtCap(capacity + 1);
    
    for (const CakeType& cakes : cakeTypes)
    {
        for (size_t i = cakes.weight_; i <= capacity; ++i)
        {
            maxValuesAtCap[i] = max(maxValuesAtCap[i - cakes.weight_] + cakes.value_, maxValuesAtCap[i]);
        }
    }
    
    return maxValuesAtCap[capacity];
}
 
 int main()
 {
    
 
 
    const vector<CakeType> cakeTypes {
        CakeType(3, 40),
        CakeType(5, 70),
    };
    
    size_t capacity = 6;
    
    cout << maxDuffelBagValue(cakeTypes, capacity) << endl;
    // returns 555 (6 of the middle type of cake and 1 of the last type of cake

    return 0;
}