#include "PresidentialPardonForm.hpp"

//actions:

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->checkRequirements(executor))
        return;
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Ortodox Canonical PresidentialPardonForm:

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const std::string &target)
          : AForm(name, 25, 5, target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5, "PresidentialTarget")
{
    std::cout << "PresidentialPardonForm Basic constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
          : AForm()
{
    this->setTarget(target);
    if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
        throw GradeTooLowException();
    if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
        throw GradeTooHighException();
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& newone) :
AForm(newone)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& newone)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &newone)
    {
        AForm::operator=(newone);
    }
    return (*this);
}