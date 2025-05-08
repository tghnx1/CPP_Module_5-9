#pragma once

/*Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array*/

#include <iostream>
#include <string>
#include <cstdint>

template <typename T> class Array
{
	public:
		Array() : value(new T())
		{
			std::cout << "lol" << std::endl;
		};
		T *value;
		int kek;

};
