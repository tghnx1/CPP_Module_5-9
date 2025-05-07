//
// Created by Maksim Kokorev on 07.05.25.
//

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
  uintptr_t adress = reinterpret_cast<uintptr_t>(ptr);
  return adress;
}

Data* Serializer::deserialize(uintptr_t address)
{
  Data *data;
  data = reinterpret_cast<Data*>(address);
  return data;
}