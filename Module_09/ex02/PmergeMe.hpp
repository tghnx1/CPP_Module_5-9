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
		void		parse(int &agrc, char **argv);
		bool		is_valid_positive_int(const char* str, int& out);
		void		vector_sort();
		void		deque_sort();
		void		get_vector();
		template	<typename Container>
        void		ft_pairing(int &lvl, Container &container);
		template	<typename Container>
        void		ft_merge_insert(int, Container &container);
		template <typename Container>
		void		ft_main_pend_generate( Container& container, int &pair_size,
							std::vector<typename Container::iterator> &main,
							std::vector<typename Container::iterator> &pend,
							std::vector<typename Container::iterator> &extra);
		template <typename Container>
		void		ft_binary_insert(std::vector<typename Container::iterator> &pend,
									std::vector<typename Container::iterator> &main);
		template <typename Container>
		void		ft_binary_insert_range(int pend_last_ind_to_insert, int &t_prev,
										std::vector<typename Container::iterator> &main,
										std::vector<typename Container::iterator> &pend);
		template <typename Container>
		void    ft_merge(int &pair_size, Container& container, std::vector<typename Container::iterator> &main,
										std::vector<typename Container::iterator> &extra);

		//Othodox canonical
};

struct DerefLess {
	bool operator()(const std::vector<int>::iterator &a, const std::vector<int>::iterator &b) const {
		return *a < *b;
	}
};

#endif //PMERGEME_HPP
