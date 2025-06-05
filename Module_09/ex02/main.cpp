#include "PmergeMe.hpp"

// custom input: 1 2 4 6 7 8 3 12 14 15 9 19 21 23 5 27 24 30 22 35 25

void	print_pairs_recurs(std::vector<Pair*> &pairs)
{
	std::cout << "in recursion: sorted by larger (a_int): " << std::endl;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
    	std::cout << "Pair " << i << ": ";
    	print_pair_recursive(pairs[i]);
    	std::cout << std::endl;
	}
}

void print_pair_recursive(const Pair* pair) {
    if (pair == nullptr) return;

    if (pair->is_leaf) {
        std::cout << "(" << pair->b_int << ", " << pair->a_int << ")";
    } else {
        std::cout << "[";
        print_pair_recursive(pair->b);
        std::cout << " , ";
        print_pair_recursive(pair->a);
        std::cout << "]";
    }
}

int main(int argc, char **argv)
{
	PmergeMe merge;

	merge.parse(argc, argv);
	merge.get_parsed();
	merge.sort();
	return 0;
}
