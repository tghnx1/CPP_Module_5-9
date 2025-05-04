#pragma once
#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm&);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        PresidentialPardonForm(const std::string &name, const std::string &target);

        virtual void execute(Bureaucrat const &) const;
};