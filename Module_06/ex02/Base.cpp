#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void Base::identify(Base* p)
{
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "ERROR" << std::endl;
}

Base* Base::generate(void)
{
  int random = std::rand() % 3;

    if (random == 0)
    {
      std::cout << "A created" << std::endl;
      return new A();
    }
    else if (random == 1)
    {
      std::cout << "B created" << std::endl;
      return new B();
    }
    else
    {
      std::cout << "C created" << std::endl;
      return new C();
    }
}

Base::~Base() {};