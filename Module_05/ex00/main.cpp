#include "Bureaucrat.hpp"

int main(void)
{
  const std::string name = "Lolek";
  Bureaucrat b(name, 130);
  try
  {
    b.decreaseGrade();
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << b << std::endl;
}