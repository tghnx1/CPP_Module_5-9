#include "Form.hpp"
#include "Exceptions.hpp"

//actions:
void  Form::beSigned(Bureaucrat &b)
{
  if (b.getGrade() <= this->getGradeToSign())
    {
      this->isSigned = true;
      std::cout << b.getName() <<" signed " << this->getName() << std::endl;
    }
  else
    throw GradeTooLowException();
}

//getters:

std::string Form::getName() const
{
  return this->name;
};

bool Form::getIsSigned() const
{
  return this->isSigned;
};

int Form::getGradeToSign() const 
{
  return this->gradeToSign;
};

int Form::getGradeToExecute() const
{
  return this->gradeToExecute;
};



// Ortodox Canonical Form:

Form::Form(void) : name("Form"), isSigned(0), gradeToSign(100), gradeToExecute(100)
{
  std::cout << "Form Basic constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
          : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw GradeTooLowException();
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw GradeTooHighException();
  std::cout << "Form constructor called" << std::endl;
};

Form::Form(const Form& newone) : name(newone.name), isSigned(newone.isSigned), gradeToSign(newone.gradeToSign), gradeToExecute(newone.gradeToExecute)
{
  std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
  std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form& newone)
{
  std::cout << "Form copy assignment operator called" << std::endl;
  if (this != &newone)
  {
    this->isSigned = newone.isSigned;
  }
  return (*this);
}

//stream

std::ostream& operator<<(std::ostream& stream, const Form& f)
{
  stream << "name: " << f.getName() << " "
         << "isSigned: " << f.getIsSigned() << " "
         << "gradeToSign: " << f.getGradeToSign() << " "
         << "gradeToExecute: " << f.getGradeToExecute();
  return stream;
}