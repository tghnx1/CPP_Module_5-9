//
// Created by Maksim Kokorev on 14.05.25.
//

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typename std::stack<T>::container_type::iterator begin()
        {
          return this->c.begin();
        }
        typename std::stack<T>::container_type::iterator end()
        {
            return this->c.end();
        }

};


#endif
