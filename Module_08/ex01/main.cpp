#include "Span.hpp"

int main()
{
  Span sp(50000);
  std::vector<int> bigRange(10000, 42);
  try
  {
    sp.addNumber(6);
    sp.addNumber(7);
    sp.addRange(bigRange.begin(), bigRange.end());
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }


  return 0;
}