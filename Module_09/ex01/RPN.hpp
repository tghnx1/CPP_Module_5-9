#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
      std::stack<int> myStack;
      std::string input;
      int result;
    public:
      int evaluate();
      void evalStack(char&);

      //helpers
      int add(int, int);
      int subtract(int, int);
      int multiply(int, int);
      int divide(int, int);
      //orthodox canonical
      RPN(std::string&); // default constructor
      ~RPN();  // default destructor
      RPN(const RPN& other);       // Copy constructor
      RPN& operator=(const RPN& other); // Copy assignment
};



#endif //RPN_HPP
