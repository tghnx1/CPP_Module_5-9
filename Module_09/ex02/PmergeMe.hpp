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

// struct Extras
// {
//   int value;
//   int index;

//   Extras(int val) : value(val) {};
// };


struct Pair {
    int index;

    // Leaf data
    int b_int;
    int a_int;

    // Nested subpairs (NULL if this is a leaf)
    Pair* b;
    Pair* a;

    bool is_leaf;

    // Leaf constructor
    Pair(int a, int b)
        : index(-1), b(NULL), a(NULL), is_leaf(true) {
        if (a < b) {
            b_int = a;
            a_int = b;
        } else {
            b_int = b;
            a_int = a;
        }
    }

    // Nested pair constructor
    Pair(Pair* p1, Pair* p2)
        : index(-1), b_int(-1), a_int(-1), is_leaf(false) {
        if (p1->get_larger() < p2->get_larger()) {
            b = p1;
            a = p2;
        } else {
            b = p2;
            a = p1;
        }
    }

    // Access the actual comparable value of a pair (recursively if needed)
    int get_larger() const
	{
		if (is_leaf)
			return (a_int);
		return (a->get_larger());
    }

    int get_smaller() const
	{
		if (is_leaf)
			return (b_int);
        return b->get_smaller();
    }

};

struct PairLargerCompare {
    bool operator()(const Pair* a, const Pair* b) const {
        return a->get_larger() < b->get_larger();
    }
};

// struct Main
// {
//     int value;
//     int index;

//     Main(int val) : value(val) {};
//     bool operator<(const Main& other) const
//     {
//         return value < other.value;
//     }
// };

class PmergeMe
{
    private:
		std::vector<int> parsed;
        std::vector<Pair*> pairs;
		std::vector<Pair*> pend;
        // std::vector<Extras> extras;
        std::vector<Pair*> main;
        int b_ind_max;
    public:
		void	parse(int &agrc, char **argv);
		bool	is_valid_positive_int(const char* str, int& out);
		void	get_parsed();
		void    sort();
        void    merge_insert();
        void    indexation();
        void    binary_insert_range(int&, int);
        void    main_create();
		void	make_first_pairs();
		void	make_pairs_from_pairs(int);
};

void print_pair_recursive(const Pair* pair);
void	print_pairs_recurs(std::vector<Pair*>&);

#endif //PMERGEME_HPP
