//
// Created by Maksim Kokorev on 03.06.25.
//

#include "PmergeMe.hpp"

//parser
bool PmergeMe::is_valid_positive_int(const char* str, int& out) {
    errno = 0;
    char* endptr = nullptr;

    long val = std::strtol(str, &endptr, 10); // Base 10

    // Check: not empty, fully converted, no overflow, positive range
    if (*str == '\0' || *endptr != '\0') return false;
    if (errno == ERANGE || val > std::numeric_limits<int>::max() || val < 0) return false;

    out = static_cast<int>(val);
    return true;
}

void	PmergeMe::get_parsed()
{
	std::cout << "parsed: ";
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::parse(int &argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "No input" << std::endl;
		exit(1);
	}

    for (int i = 1; i < argc; ++i) {
        int value;
        if (!is_valid_positive_int(argv[i], value)) {
            std::cerr << "Invalid input: \"" << argv[i] << "\" (must be positive integer within int range)" << std::endl;
            exit(1);
        }
        vector.push_back(value);
    }
}

void	PmergeMe::ft_pairing(int &lvl)
{
	int block_size = (1 << (lvl - 1)) * 2; // 4 for lvl=2

    if (block_size > vector.size())
    {
 		lvl = lvl - 2;
    	return ;
    }
    int pair_size = block_size / 2;
	std::size_t total_size = vector.size();

	std::cout << "Level " << lvl << " | Block size: " << block_size << " | Pair size: " << pair_size << std::endl;

	for (std::size_t i = 0; i + block_size - 1 < total_size; i += block_size)
	{
		// Each block contains two pairs (4 values)
		// Compare leading value of the first pair vs leading of second
		int a = vector[i + pair_size - 1];             // last of first pair
		int b = vector[i + block_size - 1];         // last of second pair

		if (a > b)
		{
			// Swap full pairs
			for (int j = 0; j < pair_size; ++j)
			{
				int tmp = vector[i + j];
				vector[i + j] = vector[i + j + pair_size];
				vector[i + j + pair_size] = tmp;
			}
		}
	}
    ft_pairing(++lvl);
}

void PmergeMe::ft_main_pend_generate(int &pair_size)
{
  int total_size = vector.size();
  int block_size = pair_size * 2;
  int pairs_number = total_size / pair_size;
  std::cout << "Pair size: " << pair_size << " | Block size: " << block_size
            	<< " | Pairs number: " << pairs_number << std::endl;
  main.clear();
  pend.clear();
  extra.clear();

  //main.push_back(b1);
  main.push_back(vector.begin() + pair_size - 1);
  //main.push_back everything else
    for (int i = 1; i < pairs_number; i++)
    {
      if (i % 2)
    	main.push_back(vector.begin() + pair_size * (i + 1) - 1);
      else
      	pend.push_back(vector.begin() + pair_size * (i + 1) - 1);
    }
	if (total_size % pairs_number)
	{
		std::vector<int>::iterator start = pend.back() + 1;
		if (start < vector.end())
		{
			for (std::vector<int>::iterator it = start; it != vector.end(); ++it)
				extra.push_back(it);
		}
	}


	std::cout << "Main: " << std::endl;
  for (int i = 0; i < main.size(); ++i)
    std::cout << *main[i] << " ";
  std::cout << std::endl;
	std::cout << "Pend: " << std::endl;
	for (int i = 0; i < pend.size(); ++i)
		std::cout << *pend[i] << " ";
	std::cout << std::endl;

	std::cout << "Extra: " << std::endl;
	for (int i = 0; i < extra.size(); ++i)
		std::cout << *extra[i] << " ";
	std::cout << std::endl;

}

void	PmergeMe::ft_binary_insert_range(int pend_last_ind_to_insert, int &t_prev)
{
	std::cout << "b_last_to_insert: " << pend_last_ind_to_insert << " ";
	std::cout << "start to mix from: " << *(pend[pend_last_ind_to_insert]) << " "; std::cout << std::endl;
    std::vector<int>::iterator b_it;
    while (pend_last_ind_to_insert + 2 > t_prev)
    {
    	b_it = pend[pend_last_ind_to_insert];
    	// Binary search in main to find correct insert position by value
    	std::vector<std::vector<int>::iterator>::iterator insert_pos =
			std::lower_bound(main.begin(), main.end(), b_it, DerefLess());

    	main.insert(insert_pos, b_it);

    	std::cout << "new Main: " << std::endl;
    	for (int i = 0; i < main.size(); ++i)
    		std::cout << *main[i] << " ";
    	std::cout << std::endl;
        std::cout << "new main size: " << main.size() << std::endl;
    	pend_last_ind_to_insert--;
    }

}

void	PmergeMe::ft_binary_insert()
{
	//detect the Jakobstahl number
	int step = 1; int t_prev = 1; int t_cur = 3; int b_ind_last = pend.size() + 1;
	while (t_prev < b_ind_last)
	{

        int pend_last_ind_to_insert;
        if (b_ind_last < t_cur)
          	pend_last_ind_to_insert = b_ind_last - 2;
        else
          pend_last_ind_to_insert = t_cur - 2;
		ft_binary_insert_range(pend_last_ind_to_insert, t_prev);
		//set t_prev and count the next t_cur
		t_prev = t_cur;
		t_cur = (pow(2, step + 3) + pow(-1, step)) / 3;
		step++;
	}
}

void PmergeMe::ft_merge(int &pair_size)
{
	std::cout << "Pair size: " << pair_size << std::endl;

	std::vector<int> temp;

	for (std::size_t i = 0; i < main.size(); ++i)
	{
		// main[i] points to aᵢ — the last element of the pair
		std::vector<int>::iterator a_i = main[i];

		// Reconstruct the original pair (bᵢ, aᵢ) and push both
		for (int j = 0; j < pair_size; ++j)
			temp.push_back(*(a_i - (pair_size - 1) + j));
	}

	// Add any extra elements
	for (std::size_t i = 0; i < extra.size(); ++i)
		temp.push_back(*extra[i]);

	vector = temp;

	std::cout << "New vector after merge: ";
	for (std::size_t i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::ft_merge_insert(int lvl)
{
	std::vector<std::vector<int>::iterator> iterators;
	int pair_size;
	while (lvl)
    {
		pair_size = (1 << (lvl - 1));
          std::cout << "lvl " << lvl << std::endl;
	 	  ft_main_pend_generate(pair_size);
          ft_binary_insert();
          ft_merge(pair_size);
          lvl--;
    }
}

void	PmergeMe::sort()
{
    int lvl = 1;
    ft_pairing(lvl);
	std::cout << "vector new: " << std::endl;
	for (int i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
    ft_merge_insert(lvl);
}
