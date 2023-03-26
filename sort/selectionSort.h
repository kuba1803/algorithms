#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <algorithm>

namespace SORT {

    template<typename RandomIt, class Comparator>
    inline void selectionSort(RandomIt begin, RandomIt end, Comparator comper) {
        RandomIt max = begin;
        RandomIt item, nextIt;
        nextIt = max;
        nextIt++;
        while (nextIt != end) {
            max++;
            nextIt = max;
            nextIt++;
        }
        while (begin != max) {
            item = begin;
            nextIt = begin;
            nextIt++;
            while (nextIt != max) {
                if (!comper(*item, *max)) {
                    std::swap(*item, *max);
                }
                item++;
                nextIt = item;
                nextIt++;
            }
            max = item;
        }

    }

    template<class Container, class Comparator>
    inline void selectionSort(Container &container, int start, int size, Comparator comper) {
        int maxIn = size - 1;
        while (maxIn != start) {
            for (int in = start; in != maxIn; in++) {
                if (!comper(container[in], container[maxIn])) {
                    std::swap(container[in], container[maxIn]);
                }
            }
            maxIn--;
        }
    }
}
#endif //ALGORITHMS_SELECTIONSORT_H
