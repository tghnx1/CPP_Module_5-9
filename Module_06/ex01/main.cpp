#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
  Data *data1 = new Data;
  Data *data2;
  uintptr_t address;;

  data1->test = 228;
  address = Serializer::serialize(data1);
  std::cout << address << std::endl;
  data1 = Serializer::deserialize(address);
  std::cout << data1->test << std::endl;
  delete data1;
  return 0;
}