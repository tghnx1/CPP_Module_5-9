
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Test 1: Normal use
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Test 1 Shortest: " << sp.shortestSpan() << std::endl;  // Expect: 2
        std::cout << "Test 1 Longest: " << sp.longestSpan() << std::endl;    // Expect: 14
    } catch (const std::exception &e) {
        std::cerr << "Test 1 Error: " << e.what() << std::endl;
    }

    // Test 2: Overflow
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    } catch (const std::exception &e) {
        std::cout << "Test 2 Caught expected overflow: " << e.what() << std::endl;
    }

    // Test 3: Range addition
    try {
        Span sp(10000);
        std::vector<int> bigData(10000);
        for (int i = 0; i < 10000; ++i) bigData[i] = rand();
        sp.addRange(bigData.begin(), bigData.end());
        std::cout << "Test 3 Large span calculated." << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Test 3 Error: " << e.what() << std::endl;
    }

    // Test 4: Not enough elements
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // Should throw
    } catch (const std::exception &e) {
        std::cout << "Test 4 Caught expected span error: " << e.what() << std::endl;
    }

    return 0;
}
