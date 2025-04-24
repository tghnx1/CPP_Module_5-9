#pragma once

#include <iostream>

class GradeTooHighException : public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "the grade is too high";
    }
};

class GradeTooLowException : public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "the grade is too low";
  }
};