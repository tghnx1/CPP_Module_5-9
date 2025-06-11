#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iostream>

// custom input: 1 2 4 6 7 8 3 12 14 15 9 19 21 23 5 27 24 30 22 35 25

int main(int argc, char **argv)
{
	std::deque<int> deque;
	PmergeMe pm_vector;

	pm_vector.parse(argc, argv);

	// Print before
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	// Time measurement for std::vector
	struct timeval start, end;
	gettimeofday(&start, NULL);
	pm_vector.vector_sort();
	gettimeofday(&end, NULL);

	double elapsed_vector = (end.tv_sec - start.tv_sec) * 1e6 +
							(end.tv_usec - start.tv_usec);
	// Print after
	std::cout << "After: ";
	pm_vector.get_vector();
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector: "
			  << elapsed_vector << " us" << std::endl;

	// Time measurement for std::deque
	gettimeofday(&start, NULL);
	pm_vector.vector_sort();
	gettimeofday(&end, NULL);

	double elapsed_deque = (end.tv_sec - start.tv_sec) * 1e6 +
						   (end.tv_usec - start.tv_usec);

	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector: "
			  << elapsed_deque << " us" << std::endl;

	return 0;
}

