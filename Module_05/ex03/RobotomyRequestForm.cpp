#include "RobotomyRequestForm.hpp"

//actions:

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->checkRequirements(executor))
        return;
    std::cout << "wroom WRRROOOMMM!!!!!!!" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << this->getTarget() << " robotomize failed." << std::endl;
}

// Ortodox Canonical RobotomyRequestForm:

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target)
          : AForm(name, 72, 45, target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45, "RobotomyTarget")
{
    std::cout << "RobotomyRequestForm Basic constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
          : AForm()
{
    this->setTarget(target);
    if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
        throw GradeTooLowException();
    if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
        throw GradeTooHighException();
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& newone) :
AForm(newone)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& newone)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &newone)
    {
        AForm::operator=(newone);
    }
    return (*this);
}