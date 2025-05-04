#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
  public:
    AForm* makeForm(const std::string&, const std::string&);
    Intern();
    Intern(const Intern&);
    ~Intern();
    Intern& operator=(const Intern&);
  private:
    AForm* shrubberyCreationForm(const std::string&, const std::string&);
    AForm* robotomyCreationForm(const std::string&, const std::string&);
    AForm* presidentialCreationForm(const std::string&, const std::string&);
};

#endif //INTERN_HPP
