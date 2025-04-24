#pragma once

#include "Form.hpp"
#include <iostream>
#include <string.h>

class Form;

class Bureaucrat
{
  private:
    const std::string name;
    int          grade;
  public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat&);

    std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
    void signForm(Form&);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);