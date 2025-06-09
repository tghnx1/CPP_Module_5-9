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

class PmergeMe
{
    private:
		std::vector<int> vector;
		std::vector<std::vector<int>::iterator> main;
  		std::vector<std::vector<int>::iterator> pend;
        std::vector<std::vector<int>::iterator> extra;
    public:
      //parsing:
		void	parse(int &agrc, char **argv);
		bool	is_valid_positive_int(const char* str, int& out);
		void	get_parsed();

		void    sort();
        void    ft_pairing(int&);
        void    ft_merge_insert(int);
        void   ft_main_pend_generate(int&);
		void   ft_binary_insert();
	    void ft_binary_insert_range(int, int&);
        void   ft_merge(int&);
};

struct DerefLess {
	bool operator()(const std::vector<int>::iterator &a, const std::vector<int>::iterator &b) const {
		return *a < *b;
	}
};

#endif //PMERGEME_HPP
