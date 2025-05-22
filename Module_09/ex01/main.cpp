#include "RPN.hpp"
#include <cassert>

void runTests()
{
  std::string input = "1 2 +";
  RPN l(input);
  assert(l.evaluate() == 3);
  input = "4 2 * 3 +";
  RPN r(input);
  assert(r.evaluate() == 11);
  input = "5 1 2 + 4 * + 3 -";
  RPN s(input);
  assert(s.evaluate() == 14); // classic example
  input = "2 3 * 4 /";
  RPN d(input);
  assert(d.evaluate() == 1);
  input = "9 2 / 3 *";
  RPN m(input);
  assert(m.evaluate() == 12);
  input = "1 2 * 2 / 2 * 9 5 - +";
  RPN h(input);
  assert(h.evaluate() == 6);

  std::cout << "All tests passed!" << std::endl;
}

int main(int argc, const char * argv[])
{
  if (argc != 2)
  {
    std::cout << "Wrong input!" << std::endl;
    return 1;
  }
  std::string input = argv[1];
  RPN r(input);
  r.evaluate();
  //runTests();

  return 0;
}