#pragma once
#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm&);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm&);

        virtual void execute(Bureaucrat const &) const;
};