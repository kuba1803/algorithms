//
// Created by Jakub on 23.03.2023.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include <algorithm>
#include <stack>
#include <tuple>
#include <cmath>

namespace SORT {

    template<typename Container, typename Comparator>
    inline void shellSort(Container &container, int start, int end, Comparator comper) {
        int gap, i = 1;
        std::stack<int> gaps;
        do {
            gap = std::ceil(1.8 * std::pow(2.25, i - 1) - 0.8);
            i++;
        } while (gap < (end - start));
        i--;
        while (i > 0) {
            gap = std::ceil(1.8 * std::pow(2.25, i - 1) - 0.8);
            for (int i = gap; i < (end - start); i++) {
                for (int j = i; j >= gap && comper(container[j], container[j - gap]); j -= gap) {
                    std::swap(container[j], container[j - gap]);
                }
            }
            i--;
        }
    }
}
#endif //ALGORITHMS_SHELLSORT_H
