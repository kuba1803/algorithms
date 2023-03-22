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
        int h = 1;
        while (h < (end - start) / 3)h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h; i < (end - start); i++) {
                for (int j = i; j >= h && comper(container[j], container[j - h]); j -= h) {
                    std::swap(container[j], container[j - h]);
                }
            }
            h /= 3;
        }
    }
}
#endif //ALGORITHMS_SHELLSORT_H
