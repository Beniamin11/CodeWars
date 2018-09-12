#include <algorithm>
#include <string>

std::string fakeBin(std::string str){


    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) -> unsigned char{return c < '5' ? '0' :'1';});


  return str;
}

