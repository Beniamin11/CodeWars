template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
    std::vector<size_t> lengths;
    int j = 0;
    
    if(arrayOfArrays.size() == 0)
        return 0;
    
    for (std::vector<TYPE> v : arrayOfArrays)
    {           
      if(v.size() == 0)
        return 0;
        
      lengths.push_back(static_cast<int>(v.size()));
      ++j;
        
    }
    
    std::sort(lengths.begin(), lengths.end() );
        
    for ( size_t i = 0; i < lengths.size()-1; i++)
    {
      if(lengths[i] + 1 != lengths[i+1])
        return lengths[i]+1;
    }

    return 0;
}