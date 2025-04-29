#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

  public:
    AForm();
    AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm&);
    ~AForm();
    AForm& operator=(const AForm&);
  
    std::string getName() const;
    bool getIsSigned() const;
    void setIsSigned(bool) ;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void  beSigned(Bureaucrat&);

    virtual void  execute(Bureaucrat const &) const = 0; // makes the class abstract and requires the func in childs
    int  checkRequirements(Bureaucrat const &) const;
};

std::ostream& operator<<(std::ostream& stream, const AForm& f);
#endif //FORM_HPP
