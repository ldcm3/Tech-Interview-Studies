
size_t getRandom(size_t floor, size_t ceiling);

void shuffle(vector<int>& A)
{
    for (size_t indexWeAreChoosing = 0; indexWeAreChoosing < A.size(); ++indexWeAreChoosing)
    {
        size_t randomIdx = getRandom(indexWeAreChoosing, A.size() - 1);
        swap(A[randomIdx],A[indexWeAreChoosing]);
    }
}