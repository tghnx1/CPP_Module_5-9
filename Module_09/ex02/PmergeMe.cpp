//
// Created by Maksim Kokorev on 03.06.25.
//

#include "PmergeMe.hpp"

void    PmergeMe::ft_custom_input_create()
{

    int pair[] = {1, 2, 4, 6, 7, 8, 3, 12, 14, 15, 9, 19, 21, 23, 5, 27, 24, 30, 22, 35};
    int pair_size = 20;

    int extr[] = {25};
    int extra_size = 3;

    for (int i = 0; i + 1 < pair_size; i += 2)
    {
      IntPair pairr(pair[i], pair[i + 1]);
        this->pairs_sorted.push_back(pairr);
    }
    if (extra_size)
    {
        for (int i = 0; i < extra_size; i ++)
        {
          Extras extra(extr[i]);
            this->extras.push_back(extra);
        }
    }
}

void    PmergeMe::ft_custom_output()
{
    for (size_t i = 0; i < pairs_sorted.size(); ++i)
    {
        std::cout << "(" << pairs_sorted[i].smaller << ", " << pairs_sorted[i].larger << "); ";
    }
    std::cout << std::endl;
    if (extras.size())
    {
        for (size_t i = 0; i < extras.size(); ++i)
        {
            std::cout << extras[i].value << "; ";
        }
        std::cout << std::endl;
    }
}

void    PmergeMe::indexation()
{
    int ind = 0;
    while (ind < pairs_sorted.size())
    {
        pairs_sorted[ind].index = ind + 1;
        ind++;
    }
    if (extras.size())
    {
        for (int i = 0; i < extras.size(); ++i)
        {
            extras[i].index = ind + 1;
            ind++;
        }
    }
    if (extras.size())
    {
      b_ind_max = (extras.end() - 1)->index;
    }
    else
      b_ind_max = (pairs_sorted.end() - 1)->index;
    //check the indexes:
    std::cout << "pairs 1-st index:" << pairs_sorted.begin()->index << std::endl;
    std::cout << "pairs last index:" << (pairs_sorted.end() - 1)->index << std::endl;
    if (extras.size())
    {
        std::cout << "extras 1-st index:" <<  extras.begin()->index << std::endl;
        std::cout << "extras lsst index:" << (extras.end() - 1)->index << std::endl;
    }
}

void    PmergeMe::binary_insert_range(int& b_last, int n)
{
  std::cout << b_last << std::endl;
  std::cout << n << std::endl;
  std::cout << "Let's merge!" << std::endl;
}

void    PmergeMe::sort()
{
  // indexation:
  this->indexation();
  //detect the Jakobstahl number
  //std::cout << "ind max: "<< b_ind_max << std::endl;
  int step = 1; int t_prev = 1; int t_cur = 3;
  while (t_prev <= b_ind_max )
  {
    //std::cout << "t_cur: " << t_cur << std::endl;
    //detect the last b index to insert:
    int b_ind = t_cur;
    if (b_ind > b_ind_max)
        b_ind = b_ind_max;
    //std::cout << "b ind: " << b_ind << std::endl;
    binary_insert_range(b_ind, b_ind - t_prev);
    //set t_prev and count the next t_cur
    t_prev = t_cur;
    t_cur = (pow(2, step + 3) + pow(-1, step)) / 3;
    step++;
  }
}