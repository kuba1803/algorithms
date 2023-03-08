#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <algorithm>
#include "../search/search.h"

namespace  SORT{
    template<typename RandomIt, typename Comparator>
    inline void insertionSort(RandomIt begin, RandomIt end, Comparator comper) {
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

    template<typename Container, typename Comparator>
    inline void insertionSort(Container &container, int start, int end, Comparator comper) {
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
