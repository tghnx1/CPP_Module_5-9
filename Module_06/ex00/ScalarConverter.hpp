#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
   public:
    static void convert(std::string&);
   private:
     ScalarConverter();
     static std::string  typeDetect(std::string &);
     static void         charConvert(std::string &);
     static void         integerConvert(std::string &);
     static void         floatingConvert(std::string &);
     static void         doubleingConvert(std::string &);
     static void         noMatches(std::string &);
     static void         printValues(char&, int&, float&, double&, bool);
     static int          nanInfCheck(std::string &);
};