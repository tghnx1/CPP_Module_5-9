#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
  Intern intern;
  AForm *form;

  form = intern.makeForm("presidential request", "targetZopa");
  std::cout << *form << std::endl;
  delete form;

  form = intern.makeForm("robotomy request", "targetZopa");
  std::cout << *form << std::endl;
  delete form;

  form = intern.makeForm("shrubbery request", "targetZopa");
  std::cout << *form << std::endl;
  delete form;
}