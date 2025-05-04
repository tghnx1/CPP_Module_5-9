#include "Intern.hpp"
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


AForm* Intern::shrubberyCreationForm(const std::string &name, const std::string &target)
{
  AForm* form = new ShrubberyCreationForm(name, target);
  return form;
}

AForm* Intern::robotomyCreationForm(const std::string &name, const std::string &target)
{
  AForm* form = new RobotomyRequestForm(name, target);
  return form;
}

AForm* Intern::presidentialCreationForm(const std::string &name, const std::string &target)
{
  AForm* form = new PresidentialPardonForm(name, target);
  return form;
}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string commands[] = {"shrubbery request", "robotomy request", "presidential request"};

    AForm* (Intern::*functions[])(const std::string &name, const std::string &target) =
    {
        &Intern::shrubberyCreationForm,
        &Intern::robotomyCreationForm,
        &Intern::presidentialCreationForm
    };

    std::cout << name << std::endl;
    for (int i = 0; i < 3; i++)
    {
      std::cout << commands[i] << std::endl;
        if (name == commands[i])
          {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return (this->*functions[i])(name, target);
          }
    }
    std::cerr << "Error in makeForm()" << std::endl;
    return NULL;
}

//Canonical Ortodox Form:

// Ortodox Canonical Intern:

Intern::Intern()
{
    std::cout << "Intern Basic constructor called" << std::endl;
};

Intern::Intern(const Intern& newone)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern& newone)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}
