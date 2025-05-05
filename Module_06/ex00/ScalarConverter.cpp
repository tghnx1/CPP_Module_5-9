#include "ScalarConverter.hpp"

//actions:

void ScalarConverter::convert( std::string& value)
{
  std::cout << "string " << value << std::endl;
  //check if char
  if (value.size() == 1 && value[0] >= 32 && value[0] <= 126 && !(value[0] >= '0' && value[0] <= '9'))
  {
    std::cout << "char: '" << value[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(value[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(value[0]) << std::endl;
    return ;
  }
  bool integer = true;
  bool floating = false;
  bool doubleing = false;
  if (value[0] != '+' && value[0] != '-' && !(value[0] >= '0' && value[0] <= '9'))
    integer = false;
  for (int i = 1; value[i] != '\0'; i++)
  {
    if ((value[i] < '0' || value[i] > '9') || value[i] != '.')
    {
      integer = false;
      floating = false;
      doubleing = false;
      break;
    }
    if (value[i] == '.')
    {
      floating = true;
      doubleing = true;
    }
  }
  if (value.back() == 'f')
      doubleing = false;
  if (integer)
  {
    std::cout << "integer!" << std::endl;
    int number = atoi(value.c_str());
    if (number >= 32 && number <= 126)
      std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(number) << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
    return ;
  }
  if (floating)
  {
    std::cout << "float!" << std::endl;
    float number = atof(value.c_str());
    std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(number) << std::endl;
    std::cout << "float: " << number << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
  }
  if (doubleing)
  {
    std::cout << "double" << std::endl;
    double number = atof(value.c_str());
    std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
  }
}

//Orthodox canonical form:

ScalarConverter::ScalarConverter()
{
  std::cout << "ScalarConverter basic constructor" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
  std::cout << "ScalarConverter basic destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
  std::cout << "ScalarConverter basic copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs)
{
  std::cout << "ScalarConverter basic copy assigment" << std::endl;
  return *this;
}