#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H

#include <algorithm>

namespace SORT {

    template<typename RandomIt, typename Comparator>
    inline void bubbleSort(RandomIt begin, RandomIt end, Comparator comper) {
        bool change = true;
        RandomIt temp, inner_temp;
        while (begin != end && change) {
            change = false;
            temp = begin;
            while (true) {
                inner_temp = temp;
                inner_temp++;
                if (inner_temp == end) {
                    end = temp;
                    break;
                }
                if (!comper(*(temp), *(inner_temp))) {
                    std::swap(*(inner_temp), *temp);
                    change = true;
                }
                temp = inner_temp;

            }
        }
    }

    template<typename Container, typename Comparator>
    inline void bubbleSort(Container &container, int start, int end, Comparator comper) {
        int temp;
        bool change = true;
        while (change && start < end--) {
            change = false;
            for (temp = start; temp < end; temp++) {
                if (!comper(container[temp], container[temp + 1])) {
                    std::swap(container[temp], container[temp + 1]);
                    change = true;
                }
            }
        }
    }
}
#endif //ALGORITHMS_BUBBLESORT_H
