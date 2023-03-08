#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <algorithm>
#include "search.h"

namespace  SORT{
    template<class RandomIt, class Comperator>
    inline void insertionSort(RandomIt begin, RandomIt end, Comperator comper) {
        RandomIt item = begin;
        RandomIt help;
        item++;
        while (item != end) {
            help = begin;
            while (help != item && comper(*help, *item)) {
                help++;
            }
            while (help != item) {
                std::swap(*help, *item);
                help++;
            }
            item++;
        }
    }

    template<class Container, class Comperator>
    inline void insertionSort(Container &container, int start, int end, Comperator comper) {
        int j, tmp;
        for (int i = start + 1; i < end; i++) {
            j = SEARCH::binary_search(container, start, i, container[i], comper);
            tmp = i;
            while (tmp > j) {
                std::swap(container[tmp], container[tmp - 1]);
                tmp--;
            }
        }
    }
}
#endif //ALGORITHMS_INSERTIONSORT_H
