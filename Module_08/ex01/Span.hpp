//
// Created by Maksim Kokorev on 14.05.25.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
      unsigned int N;
      std::vector<int> v;
    public:
      template <typename Iterator>
      void addRange(Iterator begin, Iterator end)
      {
          if (std::distance(begin, end) + v.size() > N)
              throw std::logic_error("Span::addRange: error in adding the value");
          v.insert(v.end(), begin, end);
      }
      void addNumber(int);
      int shortestSpan();
      int longestSpan();

      //Canonical Othtodox:
      Span(unsigned int);
      Span(const Span& newone);
      Span &operator=(const Span& newone);
      ~Span();

};



#endif //SPAN_HPP
