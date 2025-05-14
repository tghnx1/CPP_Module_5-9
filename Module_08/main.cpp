#include "easyfind.hpp"
#include <vector>
#include <list>
int main()
{
    std::deque<int> myVector;

    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(8);

    try
    {
        std::cout << *(easyfind(myVector, 8)) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}