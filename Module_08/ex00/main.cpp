#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
int main()
{
    std::vector<int> myVector;

    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(9);

    try
    {
        std::cout << *(easyfind(myVector, 2)) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::deque<int> myDeque;
	myDeque.push_back(1);
    myDeque.push_back(12);
    myDeque.push_back(9);

    try
    {
        std::cout << *(easyfind(myDeque, 12)) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
