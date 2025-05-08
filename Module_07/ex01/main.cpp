#include "iter.hpp"
#include <string>

void printArrInt(const int &value)
{
    std::cout << value << " ";
}

void printString(const std::string &value) {
    std::cout << value << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string words[] = {"lol", "kek", "lol", "kek"};
    iter(arr, 10, printArrInt);
    std::cout << std::endl;
    iter(words, 4, printString);
    std::cout << std::endl;
    return 0;
}