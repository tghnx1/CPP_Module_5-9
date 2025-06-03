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

struct Extras
{
  int value;
  int index;

  Extras(int val) : value(val) {};
};

struct IntPair
{
    int smaller;
    int larger;
    int index;

    IntPair(int a, int b) {
        if (a < b) { smaller = a; larger = b; }
        else       { smaller = b; larger = a; }
    }
};

class PmergeMe
{
    private:
        std::vector<IntPair> pairs_sorted;
        std::vector<Extras> extras;
        int b_ind_max;
    public:
        void    ft_custom_input_create();
        void    ft_custom_output();
        void    sort();
        void    indexation();
        void    binary_insert_range(int&, int);
};



#endif //PMERGEME_HPP
