#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include <algorithm>
#include <cmath>

namespace SORT {

    template<typename Container, typename Comparator>
    constexpr void shellSort(Container &container, int start, int size, Comparator compere) {
        int gap, gapNumber = 1;
        do {
            gap = std::ceil(1.8 * std::pow(2.25, gapNumber - 1) - 0.8);
            ++gapNumber;
        } while (gap < (size - start));
        --gapNumber;
        while (gapNumber > 0) {
            gap = std::ceil(1.8 * std::pow(2.25, gapNumber - 1) - 0.8);
            for (int i = gap; i < (size - start); ++i) {
                for (int j = i; j >= gap && compere(container[j], container[j - gap]); j -= gap) {
                    std::swap(container[j], container[j - gap]);
                }
            }
            --gapNumber;
        }
    }
}
#endif //ALGORITHMS_SHELLSORT_H
