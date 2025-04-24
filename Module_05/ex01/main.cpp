#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  const std::string burName = "Lolek";
  const std::string formName2 = "Form000";

  Bureaucrat b(burName, 100);
  Form f(formName2, 150, 100);

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
}