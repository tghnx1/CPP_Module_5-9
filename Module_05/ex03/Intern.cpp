#include "Intern.hpp"
#include <string>
#include "ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string &name, std::string &target)
{
    AForm* form = new ShrubberyCreationForm(name, target);
    std::string commands[] = {"shrubbery request", "robotomy request", "presidential request"};
 // these functions should allocate and return the corresponding poiner to the form class. So make functions.
    void (Harl::*functions[])() =
{
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
      };

    for (int i = 0; i < 4; i++)
    {
        if (level == commands[i])
            (this->*functions[i])();
    }
}

void (Harl::*functions[])() =
{
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };
}

for (int i = 0; i < 4; i++)
{
    if (level == commands[i])
        (this->*functions[i])();
}