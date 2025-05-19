#include "MutantStack.hpp"

int main()
{
 MutantStack<int> mutantStack;

 mutantStack.push(10);
 mutantStack.push(20);
 mutantStack.push(30);


 for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
 {
     std::cout << *it << std::endl;
 }

  return 0;
}