#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

  public:
    Form();
    Form(const std::string name, const int gradeToSign, const int gradeToExecute);
    Form(const Form&);
    ~Form();
    Form& operator=(const Form&);
  
    std::string getName() const;
    bool getIsSigned() const;
    bool setIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void  beSigned(Bureaucrat&);
};

std::ostream& operator<<(std::ostream& stream, const Form& f);
#endif //FORM_HPP
