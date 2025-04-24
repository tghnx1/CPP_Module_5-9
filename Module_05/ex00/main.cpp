#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
  stream << b.getName() << ", bureaucrat grade " << b.getGrade();
  return stream;
}

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