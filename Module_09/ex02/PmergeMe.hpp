//
// Created by Maksim Kokorev on 03.06.25.
//

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <sstream>
#include <limits>
#include <deque>

class PmergeMe
{
    private:
		std::vector<int> vector;
		std::deque<int>	 deque;
    public:
      //parsing:
		void	parse(int &agrc, char **argv);
		bool	is_valid_positive_int(const char* str, int& out);
		void    vector_sort();
		void	get_vector();
		void	get_deque();
        void    ft_pairing(int&);
        void    ft_merge_insert(int);
		void    ft_main_pend_generate(int &pair_size,
						std::vector<std::vector<int>::iterator> &,
						std::vector<std::vector<int>::iterator> &,
						std::vector<std::vector<int>::iterator> &);
		void    ft_binary_insert(std::vector<std::vector<int>::iterator> &pend,
						std::vector<std::vector<int>::iterator> &main);
	    void    ft_binary_insert_range(int, int&, std::vector<std::vector<int>::iterator>&,
						std::vector<std::vector<int>::iterator>&);
		void    ft_merge(int &pair_size, std::vector<std::vector<int>::iterator> &main,
						std::vector<std::vector<int>::iterator> &extra);

		//Othodox canonical
};

struct DerefLess {
	bool operator()(const std::vector<int>::iterator &a, const std::vector<int>::iterator &b) const {
		return *a < *b;
	}
};

#endif //PMERGEME_HPP
