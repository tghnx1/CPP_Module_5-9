#include "PmergeMe.hpp"

// custom input: 1 2 4 6 7 8 3 12 14 15 9 19 21 23 5 27 24 30 22 35 25



int main(int argc, char **argv)
{
	PmergeMe merge;

	merge.parse(argc, argv);
	merge.get_parsed();
	merge.sort();
	return 0;
}
