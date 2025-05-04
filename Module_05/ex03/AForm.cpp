#include "AForm.hpp"
#include "Exceptions.hpp"

//actions:

int  AForm::checkRequirements(Bureaucrat const & executor) const
{
  if (this->getIsSigned() == false)
  {
      throw NotSigned();
      return 0;
  }
  if (executor.getGrade() > this->getGradeToExecute())
  {
    throw GradeTooLowException();
    return 0;
  }
  return 1;
}

void  AForm::beSigned(Bureaucrat &b)
{
  if (b.getGrade() <= this->getGradeToSign())
    {
      this->isSigned = true;
      std::cout << b.getName() <<" signed " << this->getName() << std::endl;
    }
  else
    throw GradeTooLowException();
}

//getters setters:

std::string AForm::getName() const
{
  return this->name;
};

bool AForm::getIsSigned() const
{
  return this->isSigned;
};

void AForm::setIsSigned(bool value)
{
  this->isSigned = value;
};

int AForm::getGradeToSign() const 
{
  return this->gradeToSign;
};

int AForm::getGradeToExecute() const
{
  return this->gradeToExecute;
};

std::string AForm::getTarget() const
{
  return this->target;
}

void AForm::setTarget(std::string const& targ)
{
  this->target = targ;
}

// Ortodox Canonical AForm:

AForm::AForm(void) : name("AForm"), isSigned(false), gradeToSign(100), gradeToExecute(100), target("AForm target")
{
  std::cout << "AForm Basic constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target) :
          name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target), isSigned(false)
{
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw GradeTooLowException();
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw GradeTooHighException();
  std::cout << "AForm constructor called" << std::endl;
};

AForm::AForm(const AForm& newone) : name(newone.name), isSigned(newone.isSigned),
      gradeToSign(newone.gradeToSign), gradeToExecute(newone.gradeToExecute), target(newone.target)
{
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
  std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& newone)
{
  std::cout << "AForm copy assignment operator called" << std::endl;
  if (this != &newone)
  {
    this->isSigned = newone.isSigned;
  }
  return (*this);
}

//stream

std::ostream& operator<<(std::ostream& stream, const AForm& f)
{
  stream << "name: " << f.getName() << ", "
         << "target: " << f.getTarget() << ", "
         << "isSigned: ";
  if (f.getIsSigned() == true)
    stream << "yes, ";
  else
    stream << "no, ";
    stream  << "gradeToSign: " << f.getGradeToSign() << ", "
            << "gradeToExecute: " << f.getGradeToExecute();
  return stream;
}