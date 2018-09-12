#include <vector>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{

  for(size_t i = 0; i < arr.size(); ++i)
  {
    if( std::count(arr.begin(), arr.begin() + i, arr[i]) >= n )
    {
      arr.erase(arr.begin() + i);
      --i;
    }
  }
  
  return {arr};
}
