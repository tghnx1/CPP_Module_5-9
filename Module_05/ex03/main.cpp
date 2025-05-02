#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
  std::srand(std::time(NULL));
  const std::string burName = "Lolek";

  Bureaucrat b(burName, 5);
  ShrubberyCreationForm shrubbery;
  RobotomyRequestForm robotomy;
  PresidentialPardonForm presidential;
  std::cout << shrubbery.getIsSigned() << std::endl;


  //Shrubbery:
  //_________________________________________________________________________________________

  try
  {
    shrubbery.execute(b);
  }
  catch (const std::exception &a)
  {
    std::cout << b.getName() <<" couldn’t execute " << shrubbery.getName() << " because " << a.what() << std::endl;
  }
  std::cout << shrubbery << std::endl;
  std::cout << b << std::endl;


  try
  {
    b.signForm(shrubbery);
  }
  catch (const std::exception& g)
  {
    std::cout << b.getName() <<" couldn’t sign " << shrubbery.getName() << " because " << g.what() << std::endl;
  }
    std::cout << shrubbery << std::endl;

  try
  {
    shrubbery.execute(b);
  }
  catch (const std::exception &e)
  {
    std::cout << b.getName() <<" couldn’t execute " << shrubbery.getName() << " because " << e.what() << std::endl;
  }

  std::cout << shrubbery << std::endl;
  std::cout << b << std::endl;

  try
  {
    b.executeForm(shrubbery);
  }
  catch (const std::exception &h)
  {
    std::cout << b.getName() <<" couldn’t execute " << shrubbery.getName() << " because " << h.what() << std::endl;
  }

  //Robotomy:
  //_________________________________________________________________________________________

  try
  {
    b.executeForm(robotomy);
  }
  catch (const std::exception &h)
  {
    std::cout << b.getName() <<" couldn’t execute " << robotomy.getName() << " because " << h.what() << std::endl;
  }
  try
  {
    b.signForm(robotomy);
  }
  catch (const std::exception& g)
  {
    std::cout << b.getName() <<" couldn’t sign " << robotomy.getName() << " because " << g.what() << std::endl;
  }
  std::cout << robotomy << std::endl;

  try
  {
    b.executeForm(robotomy);
  }
  catch (const std::exception &h)
  {
    std::cout << b.getName() <<" couldn’t execute " << robotomy.getName() << " because " << h.what() << std::endl;
  }

  //Presidential:
  //_________________________________________________________________________________________

  try
  {
    b.executeForm(presidential);
  }
  catch (const std::exception &h)
  {
    std::cout << b.getName() <<" couldn’t execute " << presidential.getName() << " because " << h.what() << std::endl;
  }

  try
  {
    b.signForm(presidential);
  }
  catch (const std::exception& g)
  {
    std::cout << b.getName() <<" couldn’t sign " << presidential.getName() << " because " << g.what() << std::endl;
  }
  std::cout << presidential << std::endl;

  try
  {
    b.executeForm(presidential);
  }
  catch (const std::exception &h)
  {
    std::cout << b.getName() <<" couldn’t execute " << presidential.getName() << " because " << h.what() << std::endl;
  }

}