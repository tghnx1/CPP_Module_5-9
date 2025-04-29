#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
  const std::string burName = "Lolek";
  const std::string formName2 = "Form000";

  Bureaucrat b(burName, 100);
  ShrubberyCreationForm f;

  try
  {
    f.execute(b);
  }
  catch (const std::exception &e)
  {
    std::cout << b.getName() <<" couldn’t execute " << f.getName() << " because " << e.what() << std::endl;
  }
  std::cout << f << std::endl;
  std::cout << b << std::endl;
  try
  {
    b.signForm(f);
  }
  catch (const std::exception& g)
  {
    std::cout << b.getName() <<" couldn’t sign " << f.getName() << " because " << g.what() << std::endl;
  }
    std::cout << f << std::endl;

  try
  {
    f.execute(b);
  }
  catch (const std::exception &e)
  {
    std::cout << b.getName() <<" couldn’t execute " << f.getName() << " because " << e.what() << std::endl;
  }
  std::cout << b.getName() << " executed " << f.getName() << " successifully " << std::endl;
}