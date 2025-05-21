

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
  BitcoinExchange bitoc;

  if (argc != 2)
  {
    std::cerr << "Error: could not open file." << std::endl;
    return EXIT_FAILURE;
  }
  std::string input = argv[1];
  bitoc.parseDataBase(input);
  bitoc.printResults();
  return 0;
}