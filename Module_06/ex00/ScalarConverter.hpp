#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>

class ScalarConverter
{
   public:
    void convert(std::string&);
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter&);
};