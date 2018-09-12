#include <vector>
#include <algorithm>

template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
    std::vector<int> lengths;

    int j = 0;
    for (std::vector<TYPE> v : arrayOfArrays)
    {
      lengths.push_back(v.size());
      ++j;
    }

    std::sort(lengths.begin(), lengths.end() );

    for (size_t i = 0; i < lengths.size() - 1; ++i)
    {
      if  ( lengths[i+1] - lengths[i] != 1 )
        {return lengths[i] + 1; }
    }

    return 0;
}
