#include "Base.hpp"
#include <iostream>
#include <time.h>

int main()
{
    std::srand(std::time(NULL));
    Base *lol;
    lol = lol->generate();
    lol->identify(lol);
    delete lol;
}
