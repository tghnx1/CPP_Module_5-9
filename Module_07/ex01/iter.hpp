//
// Created by mkokorev on 5/8/25.
//

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdint>

template <typename T>
void iter(T *arr, int len, void (*function)(const T&))
{
    for (int i = 0; i < len; i++)
    {
        function(arr[i]);
    }
}


#endif //ITER_HPP
