#include <iostream>
#include <fstream>
#include <vector>

//g++ -std=c++11 sort_checker.cpp -o sort_checker
using namespace std;

int main() {
    ifstream file("sorted.txt");
    vector<int> nums;
    int x;

    while (file >> x)
        nums.push_back(x);

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            cout << "Not sorted\n";
            return 0;
        }
    }

    cout << "Sorted\n";
    return 0;
}
