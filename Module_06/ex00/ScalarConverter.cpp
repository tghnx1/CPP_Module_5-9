#include "ScalarConverter.hpp"

//actions:

int ScalarConverter::nanInfCheck(std::string &value)
{
  if (value == "nan" || value == "nanf")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    return 0;
  }
  else if (value == "+inf" || value == "+inff")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
    return 0;
  }
  else if (value == "-inf" || value == "-inff")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
    return 0;
  }
  return 1;
}

void ScalarConverter::printValues(char &valueChar, int &valueInt, float &valueFloat, double &valueDouble, bool setpresicion)
{
  if (valueChar >= 32 && valueChar <= 126)
    std::cout << "char: '" << valueChar << "'" << std::endl;
  else if (valueChar < 0 || valueChar > 127)
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: non displayable" << std::endl;
  std::cout << "int: " << valueInt << std::endl;
  if (setpresicion)
    std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << valueFloat << "f" << std::endl;
  std::cout << "double: " << valueDouble << std::endl;
}

void ScalarConverter::noMatches(std::string &value)
{
  std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

void ScalarConverter::doubleingConvert(std::string &value)
{
  char   valueChar;
  int    valueInt;
  float  valueFloat;
  double  valueDouble;
  //converting:
  std::istringstream stream(value);
  stream >> valueDouble;
  if (stream.fail() || !stream.eof())
  {
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
    return;
  }
  valueChar = static_cast<char>(valueDouble);
  valueFloat = static_cast<float>(valueDouble);
  valueInt = static_cast<int>(valueDouble);


  //printing:
  printValues(valueChar, valueInt, valueFloat, valueDouble, false);
}

void ScalarConverter::floatingConvert(std::string &value)
{
  char   valueChar;
  int    valueInt;
  float  valueFloat;
  double  valueDouble;

  //converting:
  if (!value.empty())
    value.erase(value.length() - 1);
  std::istringstream stream(value);
  stream >> valueFloat;
  if (stream.fail() || !stream.eof())
  {
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
    return;
  }
  valueChar = static_cast<char>(valueFloat);
  valueFloat = static_cast<float>(valueFloat);
  valueInt = static_cast<int>(valueFloat);
  valueDouble = static_cast<double>(valueFloat);

  //printing:
  printValues(valueChar, valueInt, valueFloat, valueDouble, false);
}

void ScalarConverter::integerConvert(std::string &value)
{
  char   valueChar;
  int    valueInt;
  float  valueFloat;
  double  valueDouble;

  //converting:
  std::istringstream stream(value);
  stream >> valueInt;
  valueChar = static_cast<char>(valueInt);
  valueFloat = static_cast<float>(valueInt);
  valueDouble = static_cast<double>(valueInt);
  //printing:
  printValues(valueChar, valueInt, valueFloat, valueDouble, true);
}

void ScalarConverter::charConvert(std::string &value)
{
  char   valueChar;
  int    valueInt;
  float  valueFloat;
  double  valueDouble;

  //converting:
  valueChar = value[0];
  valueInt = static_cast<int>(valueChar);
  valueFloat = static_cast<float>(valueChar);
  valueDouble = static_cast<double>(valueChar);
  //printing:
  printValues(valueChar, valueInt, valueFloat, valueDouble, false);
}

std::string ScalarConverter::typeDetect(std::string &value)
{
  bool charing = true, integer = true, valid = true;
  int dot_met = 0;
  //check infinity and nan:
  if (!nanInfCheck(value))
  {
    value.clear();
    return value;
  }
  //check if char
  if (value.size() == 1 && value[0] >= 32 && value[0] <= 126 && !(value[0] >= '0' && value[0] <= '9'))
    return "char";
  if (value.size() == 1 && value[0] >= '0' && value[0] <= '9')
    return "integer";

  if (value[0] != '+' && value[0] != '-' && !(value[0] >= '0' && value[0] <= '9'))
    return "nomatch";
  for (int i = 1; i < value.length() - 2; i++)
  {
    if (value[i] == '.')
    {
      dot_met++;
      integer = false;
    }
    if (((value[i] < '0' || value[i] > '9') && value[i] != '.') || dot_met > 1)
      return "nomatch";
  }
  //check the last value
  char end = value[value.length() - 1];
  if (end == 'f')
    return "float";
  if (end == '.')
    return "double";
  else if ((end < '0' || end > '9') && end != 'f')
    return "nomatch";
  else if (!integer)
    return "double";
  else
    return "integer";
  return "nomatch";
}

void ScalarConverter::convert( std::string& value)
{
  std::string name;

  name = typeDetect(value);
  if (name.empty())
    return;
  std::string commands[] = {"char", "integer", "float", "double", "nomatch"};
  void (*functions[])(std::string& value) =
  {
    &ScalarConverter::charConvert,
    &ScalarConverter::integerConvert,
    &ScalarConverter::floatingConvert,
    &ScalarConverter::doubleingConvert,
    &ScalarConverter::noMatches
  };
  for (int i = 0; i < 5; i++)
  {
    if (name == commands[i])
    {
      return (functions[i])(value);
    }
  }
}