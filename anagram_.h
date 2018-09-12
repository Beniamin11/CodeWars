#include <string>

bool isAnagram(std::string test, std::string original){
  
  std::transform(test.begin(), test.end(), test.begin(),
                  [](unsigned char c) -> unsigned char { return std::toupper(c);});
  std::transform(original.begin(), original.end(), original.begin(),
                  [](unsigned char c) -> unsigned char { return std::toupper(c);});   
                  
  std::sort(test.begin(),test.end());
  std::sort(original.begin(), original.end());
  
  return test == original;
}