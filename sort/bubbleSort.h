#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H

#include <algorithm>

namespace SORT {

    template<typename RandomIt, typename Comparator>
    inline void bubbleSort(RandomIt begin, RandomIt end, Comparator &compere) {
        bool change = true;
        RandomIt temp, inner_temp;
        while (change && begin != end ) {
            change = false;
            inner_temp = temp = begin;
            inner_temp++;
            while (inner_temp != end){
                if (!compere(*temp, *inner_temp)) {
                    std::swap(*inner_temp, *temp);
                    change = true;
                }
                temp++;
                inner_temp++;
            }
            end = temp;
        }
    }

    template<typename Container, typename Comparator>
    inline void bubbleSort(Container &container, int start, int size, Comparator &compere) {
        int temp;
        bool change = true;
        while (change && start < size--) {
            change = false;
            for (temp = start; temp < size; temp++) {
                if (!compere(container[temp], container[temp + 1])) {
                    std::swap(container[temp], container[temp + 1]);
                    change = true;
                }
            }
        }
    }
}
#endif //ALGORITHMS_BUBBLESORT_H
