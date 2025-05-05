#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "wrong input!" << std::endl;
    return 1;
  }

  std::string value = argv[1];
  ScalarConverter converter;

  converter.convert(value);
}