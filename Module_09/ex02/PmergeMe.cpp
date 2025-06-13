#include "PmergeMe.hpp"

//Othodox canonical








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

void	PmergeMe::get_vector()
{
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
	if (argc < 3)
	{
		std::cerr << "Error: At least two numbers are required." << std::endl;
		exit(1);
	}

    for (int i = 1; i < argc; ++i) {
        int value;
        if (!is_valid_positive_int(argv[i], value)) {
            std::cerr << "Invalid input: \"" << argv[i] << "\" (must be positive integer within int range)" << std::endl;
            exit(1);
        }
    	deque.push_back(value);
        vector.push_back(value);
    }
	if (std::is_sorted(vector.begin(),vector.end()))
	{
		std::cerr << "Error: Input is already sorted." << std::endl;
		exit(1);
	}
}

template <typename Container>
void	PmergeMe::ft_pairing(int &lvl, Container &container)
{
	int block_size = (1 << (lvl - 1)) * 2; // 4 for lvl=2

    if (block_size > container.size())
    {
		if (container.size() <= 3)
			lvl--;
		else
 			lvl -= 2;
    	return ;
    }
    int pair_size = block_size / 2;
	std::size_t total_size = container.size();

	for (std::size_t i = 0; i + block_size - 1 < total_size; i += block_size)
	{
		// Each block contains two pairs (4 values)
		// Compare leading value of the first pair vs leading of second
		int a = container[i + pair_size - 1];             // last of first pair
		int b = container[i + block_size - 1];         // last of second pair

		if (a > b)
		{
			// Swap full pairs
			for (int j = 0; j < pair_size; ++j)
			{
				int tmp = container[i + j];
				container[i + j] = container[i + j + pair_size];
				container[i + j + pair_size] = tmp;
			}
		}
	}
    ft_pairing(++lvl, container);
}

template <typename Container>
void PmergeMe::ft_main_pend_generate(Container& container, int &pair_size,
							std::vector<typename Container::iterator> &main,
							std::vector<typename Container::iterator> &pend,
							std::vector<typename Container::iterator> &extra)
{
  int total_size = container.size();
  int block_size = pair_size * 2;
  int pairs_number = total_size / pair_size;


  //main.push_back(b1);
  main.push_back(container.begin() + pair_size - 1);
  //main.push_back everything else
    for (int i = 1; i < pairs_number; i++)
    {
      if (i % 2)
    	main.push_back(container.begin() + pair_size * (i + 1) - 1);
      else
      	pend.push_back(container.begin() + pair_size * (i + 1) - 1);
    }
	if (total_size % pairs_number)
	{
		typename Container::iterator start = pend.back() + 1;
		if (start < container.end())
		{
			for (std::vector<int>::iterator it = start; it != container.end(); ++it)
				extra.push_back(it);
		}
	}
}

template <typename Container>
void	PmergeMe::ft_binary_insert_range(int pend_last_ind_to_insert, int &t_prev,
										std::vector<typename Container::iterator> &main,
										std::vector<typename Container::iterator> &pend)
{
    typename Container::iterator b_it;
    while (pend_last_ind_to_insert + 2 > t_prev)
    {
    	b_it = pend[pend_last_ind_to_insert];
    	// Binary search in main to find correct insert position by value
    	typename std::vector<typename Container::iterator>::iterator insert_pos =
			std::lower_bound(main.begin(), main.end(), b_it, DerefLess());
    	main.insert(insert_pos, b_it);
    	pend_last_ind_to_insert--;
    }

}

template <typename Container>
void	PmergeMe::ft_binary_insert(std::vector<typename Container::iterator> &pend,
									std::vector<typename Container::iterator> &main)
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
		ft_binary_insert_range(pend_last_ind_to_insert, t_prev, main, pend);
		//set t_prev and count the next t_cur
		t_prev = t_cur;
		t_cur = (pow(2, step + 3) + pow(-1, step)) / 3;
		step++;
	}
}

template <typename Container>
void PmergeMe::ft_merge(			int &pair_size, Container& container,
									std::vector<typename Container::iterator> &main,
									std::vector<typename Container::iterator> &extra)
{
	Container temp;
	for (std::size_t i = 0; i < main.size(); ++i)
	{
		// main[i] points to aᵢ — the last element of the pair
		typename Container::iterator a_i = main[i];

		// Reconstruct the original pair (bᵢ, aᵢ) and push both
		for (int j = 0; j < pair_size; ++j)
			temp.push_back(*(a_i - (pair_size - 1) + j));
	}

	// Add any extra elements
	for (std::size_t i = 0; i < extra.size(); ++i)
		temp.push_back(*extra[i]);

	container = temp;


}

template <typename Container>
void	PmergeMe::ft_merge_insert(int lvl, Container &container)
{
	int pair_size;
	while (lvl)
    {
		typedef typename Container::iterator iterator_type;
		std::vector<iterator_type> main;
		std::vector<iterator_type> pend;
		std::vector<iterator_type> extra;
		pair_size = (1 << (lvl - 1));
		ft_main_pend_generate(container, pair_size, main, pend, extra);
		ft_binary_insert<Container>(pend, main);
		ft_merge<Container>(pair_size, container, main, extra);
		lvl--;
    }
}

void	PmergeMe::vector_sort()
{
    int lvl = 1;
    ft_pairing(lvl, vector);
    ft_merge_insert(lvl, vector);
}

void	PmergeMe::deque_sort()
{
    int lvl = 1;
    ft_pairing(lvl, deque);
    ft_merge_insert(lvl, deque);
}


