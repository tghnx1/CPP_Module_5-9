//
// Created by Maksim Kokorev on 14.05.25.
//

#include "Span.hpp"
#include <climits>

void    Span::addNumber(int number)
{
  if (v.size() == this->N)
    throw std::out_of_range("Span::addNumber: error in adding the value");
  v.push_back(number);
}

int Span::shortestSpan()
{
  if (v.size() < 2)
      throw std::logic_error("Span::shortestSpan: error in adding the value");
  std::vector<int> sorted = v;
  std::sort(sorted.begin(), sorted.end());
  int shortestSpan = INT_MAX;
  for (unsigned int i = 0; i < sorted.size() - 1; i++)
  {
    if (sorted[i + 1] - sorted[i] < shortestSpan)
      shortestSpan = sorted[i + 1] - sorted[i];
  }
  return shortestSpan;
}

int Span::longestSpan()
{
  int smallest = 0;
  int biggest = 0;

  if (v.size() < 2)
    throw std::logic_error("Span::longestSpan: error in adding the value");
  smallest = *(std::min_element(v.begin(), v.end()));
  biggest = *(std::max_element(v.begin(), v.end()));
  return biggest - smallest;
}

//Othodox Canonical Form:

Span::Span(unsigned int num)
{
  this->N = num;
}

Span::Span(const Span& newone)
{
  this->N = newone.N;
  this->v = newone.v;
}

Span::~Span() {}

Span &Span::operator=(const Span& newone)
{
  if (this != &newone)
  {
    this->N = newone.N;
    this->v = newone.v;
  }
  return (*this);
}
