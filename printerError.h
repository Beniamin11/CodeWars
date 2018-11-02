#include <string>
class Printer
{
public:
    static std::string printerError(const std::string s);
};

std::string Printer::printerError(const std::string s)
{
  size_t err = 0;

  for ( auto elem : s )
  {
    if (elem > 'm' )  err++;
  }

  std::string ret_val {std::to_string(err) + "/" + std::to_string(s.length())};

  return ret_val;
}
