#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        /*const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;*/
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

        virtual void execute(Bureaucrat const &) const;
};