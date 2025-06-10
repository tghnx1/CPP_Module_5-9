#include <iostream>
#include <unordered_set>
#include <random>
#include <algorithm>

//g++ -std=c++11 numbers_generator.cpp -o numbers_generator

int main() {
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 1000000;
    const int NUM_VALUES = 3000;

    // Use a hash set to ensure uniqueness
    std::unordered_set<int> unique_numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);

    // Generate 3000 unique random numbers
    while (unique_numbers.size() < NUM_VALUES) {
        int num = dist(gen);
        unique_numbers.insert(num);
    }

    // Print them in a space-separated single line
    bool first = true;
    for (int num : unique_numbers) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << num;
        first = false;
    }

    return 0;
}