#include "PmergeMe.hpp"

bool is_valid_positive_int(const char* str, int& out) {
    errno = 0;
    char* endptr = nullptr;

    long val = std::strtol(str, &endptr, 10); // Base 10

    // Check: not empty, fully converted, no overflow, positive range
    if (*str == '\0' || *endptr != '\0') return false;
    if (errno == ERANGE || val > std::numeric_limits<int>::max() || val <= 0) return false;

    out = static_cast<int>(val);
    return true;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "No input" << std::endl;
		return (1);
	}

	std::vector<int> numbers;

    for (int i = 1; i < argc; ++i) {
        int value;
        if (!is_valid_positive_int(argv[i], value)) {
            std::cerr << "Invalid input: \"" << argv[i] << "\" (must be positive integer within int range)" << std::endl;
            return 1;
        }
        numbers.push_back(value);
    }

    std::cout << "Parsed positive integers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

	//PmergeMe merge;

	//merge.ft_custom_input_create();
	//merge.ft_custom_output();
	//merge.sort();
	return 0;
}
