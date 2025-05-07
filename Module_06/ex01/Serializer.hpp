#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"
#include <cstdint>

class Serializer
{
  public:
    static uintptr_t serialize(Data*);
    static Data* deserialize(uintptr_t);
  private:
    Serializer();
};

#endif //SERIALIZER_HPP
