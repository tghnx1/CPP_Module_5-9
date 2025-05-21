#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>


template <typename T>
typename T::iterator easyfind(T myContainer, int value)
{
    typename T::iterator it;
    it = find (myContainer.begin(), myContainer.end(), value);
    if (it == myContainer.end())
      throw std::out_of_range("Easyfind: value not found");
    else
      return it;
}

#endif // EASYFIND_TPP