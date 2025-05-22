#include "RPN.hpp"

//helpers
int RPN::subtract(int a, int b)
{
  return a - b;
}
int RPN::multiply(int a, int b)
{
  return a * b;
}
int RPN::divide(int a, int b)
{
  if (b == 0)
  {
    std::cout << "Division by zero!" << std::endl;
    exit(0);
  }
  return a / b;
}

int RPN::add(int a, int b)
{
  return a + b;
}

//actions:

void RPN::evalStack(char& ch)
{
  if (myStack.size() < 2)
  {
    std::cerr << "Error: not enough values on the stack for operation '" << ch << "'" << std::endl;
    exit(1);
  }
  int a = myStack.top();
  myStack.pop();
  int b = myStack.top();
  std::string operators = "+-*/";
  int (RPN::*operations[])(int, int) =
      { &RPN::add,
       &RPN::subtract,
       &RPN::multiply,
       &RPN::divide
      };
  for (int i = 0; i < operators.size(); i++)
  {
    if (ch == operators[i])
      result = (this->*operations[i])(b, a);
  }
    myStack.pop();
  myStack.push(result);
}

int RPN::evaluate()
{
  int stackResult;
  for (int i = 0; i < input.length(); i++)
  {
    while (input[i] == ' ')
      i++;
    if (std::isdigit(input[i]))
      myStack.push(input[i] - '0');
    else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
      this->evalStack(input[i]);
    else
    {
        std::cout << "Error: Invalid token!" << std::endl;
        exit(1);
    }
  }
  if (myStack.size() > 1)
  {
    std::cout << "Error: Stack size is " << myStack.size() << std::endl;
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    std::cout << myStack.top() << std::endl;
    exit(1);
  }
  std::cout << result << std::endl;
  return result;
}

// orthodox canonical form:

RPN::RPN(std::string& inpt)
{
  this->input = inpt;
  this->result = 0;
}

RPN::RPN(const RPN& other)
{
  if (this != &other)
  {
    this->input = other.input;
    this->result = other.result;
    this->myStack = other.myStack;
  }
}

RPN& RPN::operator=(const RPN& other)
{
  if (this != &other)
  {
    this->input = other.input;
    this->result = other.result;
    this->myStack = other.myStack;
  }
  return *this;
}

RPN::~RPN() {};