//
// Created by Maksim Kokorev on 07.05.25.
//

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>

class Base
{
  public:
    virtual ~Base();
    Base *generate(void);
    void identify(Base* p);
};

#endif //BASE_HPP
