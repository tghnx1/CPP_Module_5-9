#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "AForm.hpp"

//actions:

void Bureaucrat::executeForm(AForm const & form)
{
    form.execute(*this);
}

void Bureaucrat::signForm(AForm& f)
{
    if (this->grade > 150)
        throw GradeTooLowException();
    if (this->grade < 1)
        throw GradeTooHighException();
     f.beSigned(*this);
}

std::string    Bureaucrat::getName() const
{
  return this->name;
}

int    Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increaseGrade()
{
  if (this->grade - 1 < 1)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

// Ortodox Canonical AForm:
Bureaucrat::Bureaucrat(void) : name("Bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat Basic constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name , int grade) : name(name), grade(grade)
{
  std::cout << "Bureaucrat constructor called" << std::endl;
    if (this->grade > 150)
        throw GradeTooLowException();
    if (this->grade < 1)
        throw GradeTooHighException();
};

Bureaucrat::Bureaucrat(const Bureaucrat& newone) : grade(newone.grade), name(newone.name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& newone)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &newone)
    {
        this->grade = newone.grade;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
    stream << b.getName() << ", bureaucrat grade " << b.getGrade();
    return stream;
}