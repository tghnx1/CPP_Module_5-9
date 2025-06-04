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
    int index;

    int smaller;
    int larger;
    IntPair *pair_smaller;
    IntPair *pair_larger;

    IntPair(int a, int b) {
        if (a < b) { smaller = a; larger = b; }
        else       { smaller = b; larger = a; }
    }
    IntPair(IntPair *p1, IntPair *p2)
    {
      smaller = -1;
      larger = -1;
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
        std::vector<IntPair> pairs_sorted;
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
};



#endif //PMERGEME_HPP
