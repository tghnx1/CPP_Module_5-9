#pragma once

/*Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array*/

#include <iostream>
#include <string>
#include <cstdint>

class TooBigIteratorException : public std::exception
{
	public:
		virtual const char* what() const throw()
	{
		return "you're trying to access the memory block you don't have an access 🤦🤦🤦🤦🤦";
	}
};

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int len;
	public:
	//actions:

	unsigned int size()
	{
		return this->len;
	}

	//Othodox canonical form:
		Array()
		{
			arr = nullptr;
			len = 0;
		};

		Array(unsigned int n)
		{
			this->arr = new T[n];
			this->len = n;
			for (unsigned int i = 0; i < len; i++)
				arr[i] = T();
		};

		Array(const Array& oldone)
		{
				this->len = oldone.len;
				this->arr = new T[len];
				for (unsigned int i = 0; i < this->len; i++)
				{
					this->arr[i] = oldone.arr[i];
				}
		};

		~Array()
		{
			delete[] this->arr;
		};

		Array& operator=(const Array& oldone)
		{
			this->len = oldone.len;
			delete[] this->arr;
			this->arr = new T[len];
			for (unsigned int i = 0; i < this->len; i++)
			{
				this->arr[i] = oldone.arr[i];
			}
			return *this;
		}

		T& operator[](int i)
		{
			if (static_cast<unsigned int>(i) >= this->len)
			{
				throw TooBigIteratorException();
			}
			return this->arr[i];
		}

};

