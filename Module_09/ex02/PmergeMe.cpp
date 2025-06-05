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
	for (int i = 0; i < parsed.size(); i++)
	{
		std::cout << parsed[i] << " ";
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
        parsed.push_back(value);
    }
}

void    PmergeMe::indexation()
{
	 int ind = 0;

    std::cout << "pairs size: " << pairs.size() << std::endl;

    // Index all pairs
    for (size_t i = 0; i < pairs.size(); ++i) {
        pairs[i]->index = ++ind;
    }

    // Index all pending elements
    for (size_t i = 0; i < pend.size(); ++i) {
        pend[i]->index = ++ind;
    }

    // Update b_ind_max from the last inserted
    if (!pend.empty()) {
        b_ind_max = pend.back()->index;
    } else if (!pairs.empty()) {
        b_ind_max = pairs.back()->index;
    } else {
        b_ind_max = 0; // edge case: nothing to index
    }

    // Debug prints
    if (!pairs.empty()) {
        std::cout << "pairs 1-st index: " << pairs.front()->index << std::endl;
        std::cout << "pairs last index: " << pairs.back()->index << std::endl;
    }

    if (!pend.empty()) {
        std::cout << "pend 1-st index: " << pend.front()->index << std::endl;
        std::cout << "pend last index: " << pend.back()->index << std::endl;
    }
}

void    PmergeMe::binary_insert_range(int& b_last, int n)
{
  std::cout <<"b last:" << b_last << std::endl;
  std::cout << n << std::endl;
  std::cout << "Let's binary insert!" << std::endl;

  //should make a binary insert from the last up to the first to the range
    while (n)
    {
		if (pend.empty()) {
            std::cerr << "Error: pend is empty but binary insert still expects values.\n";
            return;
        }
      Pair *to_insert = pend.back();
    //   if (pairs.size() >= b_last)
    //       to_insert = (pairs[b_last - 1])->b;
    //   else
    //   {
        to_insert = (*(pend.end() - 1));
        pend.erase(pend.end() - 1);
		PairLargerCompare comp;
		std::vector<Pair*>::iterator pos = std::lower_bound(main.begin(),
		main.end(), to_insert, comp);
    //   }
      //std::cout << "To insert: " << to_insert << std::endl;
        // Binary search to find the correct position
      //std::vector<Pair*>::iterator pos = std::lower_bound(main.begin(), main.end(), to_insert);
        // Insert at the position
      main.insert(pos, to_insert);
      n--;
      b_last--;
    }


    //print
    for (const Pair* p : main)
    {
        std::cout << "(" << p->get_smaller() << ", " << p->get_larger() << ") ";
    }
    std::cout << std::endl;
}


void    PmergeMe::main_create()
{
  //create main (a1, b1, a2 ... a_ind_max)
  std::cout << "larger from the pair: " << (*pairs.begin())->get_larger() << std::endl;
  main.push_back((*pairs.begin())->b);
  main.push_back((*pairs.begin())->a);
  for (int i = 1; i < pairs.size(); ++i)
  {
    main.push_back(pairs[i]->a);
  }

}

void    PmergeMe::merge_insert()
{


  this->main_create();

  std::cout << "lolololololO!!" << std::endl;
  //detect the Jakobstahl number
  int step = 1; int t_prev = 1; int t_cur = 3;
  while (t_prev <= b_ind_max )
  {

	//detect the last b index to insert:
    int b_ind = t_cur;
    if (b_ind > b_ind_max)
        b_ind = b_ind_max;
	std::cout << "b_ind: " << b_ind << std::endl;
    binary_insert_range(b_ind, b_ind - t_prev);
	//set t_prev and count the next t_cur
    t_prev = t_cur;
    t_cur = (pow(2, step + 3) + pow(-1, step)) / 3;
    step++;
  }

}

void	PmergeMe::make_first_pairs()
{
	for (int i = 0; i + 1 < this->parsed.size(); i += 2) {
        Pair* pair = new Pair(this->parsed[i], this->parsed[i + 1]);
        this->pairs.push_back(pair);
    }


    // if (parsed.size() % 2 != 0)
    //     this->extras.emplace_back(this->parsed.back());


    std::cout << "sorted by larger (a_int): ";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i]->b_int << ", " << pairs[i]->a_int << ") ";
    }
	// std::cout << "; extras: ";
    // for (size_t i = 0; i < extras.size(); i++) {
    //     std::cout << extras[i].value << " ";
    // }
    std::cout << std::endl;
	std::cout << " pairs size after the first pairing: " << pairs.size() <<  std::endl;
}


void PmergeMe::make_pairs_from_pairs(int lvl)
{
		if (pairs.size() <= 1)
	{
		std::cout << "recursion lvl: " << lvl << std::endl;
		return;
	}
	//std::cout << "larger from the last pair: " << pairs.back()->get_larger() << std::endl;
	std::cout << "looool" << std::endl;
	std::vector<Pair*> temp = pairs;
	pairs.clear();
	for (int i = 0; i + 1 < temp.size(); i += 2) {
		Pair *pair = new Pair(temp[i], temp[i + 1]);
        this->pairs.push_back(pair);
    }
	// for (size_t i = 1; i < pairs.size(); ++i)
    // 	pend.push_back(pairs[i]->b);
    if (temp.size() % 2 != 0) {
    	this->pend.push_back(temp.back());  // correct: push the last Pair*
	}
	this->make_pairs_from_pairs(lvl + 1);

}

void	PmergeMe::sort()
{
	this->make_first_pairs();
	this->make_pairs_from_pairs(0);
	print_pairs_recurs(pairs);
	print_pairs_recurs(pend);
	this->indexation();
	this->merge_insert();
	std::cout << "a new main: " << std::endl;
	print_pairs_recurs(main);

}
