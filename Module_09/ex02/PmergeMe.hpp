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

struct Extras
{
  int value;
  int index;

  Extras(int val) : value(val) {};
};

struct Pair {
    int index;

    // Leaf data
    int smaller_int;
    int larger_int;

    // Nested subpairs (NULL if this is a leaf)
    Pair* pair_smaller;
    Pair* pair_larger;

    bool is_leaf;

    // Leaf constructor
    Pair(int a, int b)
        : index(-1), pair_smaller(NULL), pair_larger(NULL), is_leaf(true) {
        if (a < b) {
            smaller_int = a;
            larger_int = b;
        } else {
            smaller_int = b;
            larger_int = a;
        }
    }

    // Nested pair constructor
    Pair(Pair* p1, Pair* p2)
        : index(-1), smaller_int(-1), larger_int(-1), is_leaf(false) {
        if (p1->get_larger() < p2->get_larger()) {
            pair_smaller = p1;
            pair_larger = p2;
        } else {
            pair_smaller = p2;
            pair_larger = p1;
        }
    }

    // Access the actual comparable value of a pair (recursively if needed)
    int get_larger() const {
        return is_leaf ? larger_int : pair_larger->get_larger();
    }

    int get_smaller() const {
        return is_leaf ? smaller_int : pair_smaller->get_smaller();
    }
};


struct Main
{
    int value;
    int index;

    Main(int val) : value(val) {};
    bool operator<(const Main& other) const
    {
        return value < other.value;
    }
};

class PmergeMe
{
    private:
        std::vector<Pair*> pairs_sorted;
        std::vector<Extras> extras;
        std::vector<Main> main;
        int b_ind_max;
    public:
        void    ft_custom_input_create();
        void    ft_custom_output();
        void    sort();
        void    indexation();
        void    binary_insert_range(int&, int);
        void    main_create();
		void	make_pairs_recursion();
};



#endif //PMERGEME_HPP
