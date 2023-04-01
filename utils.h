//
// Created by Jakub on 25.03.2023.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include <iterator>
#include <experimental/random>
#include "sort/insertionSort.h"

namespace UTILS {
    template<typename RandomIt>
    RandomIt minimum(RandomIt begin, RandomIt end) {
        RandomIt *min = begin;
        for (RandomIt it = begin; begin != end; it++) {
            min = (*min < *it) ? min : it;
        }
        return min;
    }

    template<typename RandomIt>
    RandomIt maximum(RandomIt begin, RandomIt end) {
        RandomIt *max = begin;
        for (RandomIt it = begin; begin != end; it++) {
            max = (*max > *it) ? max : it;
        }
        return max;
    }

    template<typename Container, typename Comparator>
    inline auto randomizedSelect(Container &container, int start, int end, int ith, Comparator comper) {
        if (start == end) return container[start];
        int q;
        do {
            q = start;
            std::swap(container[rand()%(end-start)+start], container[end]);
            for (int j = start; j < end; j++) {
                if (comper(container[j], container[end])) {
                    std::swap(container[q], container[j]);
                    q++;
                }
            }
            std::swap(container[q], container[end]);
            if (ith < q) end = q - 1;
            else if (ith > q) {
                start = q + 1;
            }
        } while (ith != q && start != end);
        if (start == end) return container[start];
        return container[q];
    }


    template<typename Container, typename Comparator>
    inline auto select(Container &container, int start, int end, int ith, Comparator comper) {
        int q, k;
        do {
            while (end - start < 5 || ((end - start + 1) % 5) != 0) {
                for (int j = start + 1; j <= end; j++) {
                    if (!comper(container[start], container[j])) {
                        std::swap(container[start], container[j]);
                    }
                }
                if (ith == 0)return container[start];
                start++;
                ith--;
            }
            int amountGroup = (end - start + 1) / 5;

            for (int j = start; j < start + amountGroup; j++) {
                for (int i = 0; i < 5; i++) {
                    for (int p = 0; p < 5 - i - 1; p++) {
                        if (!comper(container[j + amountGroup * p], container[j + amountGroup * (p + 1)])) {
                            std::swap(container[j + amountGroup * p], container[j + amountGroup * (p + 1)]);
                        }
                    }
                }
            }

            int x = select(container, start + 2 * amountGroup, start + 3 * amountGroup - 1, std::ceil(amountGroup / 2),
                           comper);
            q = start;
            std::swap(container[x], container[end]);
            for (int j = start; j < end; j++) {
                if (comper(container[j], container[end])) {
                    std::swap(container[q], container[j]);
                    q++;
                }
            }
            std::swap(container[q], container[end]);
            k = q - start + 1;
            if (ith == k)return container[q];
            if (ith < k) end = q - 1;
            else if (ith > k) {
                start = q + 1;
                ith -= k;
            }
        } while (true);
    }
}

#endif //ALGORITHMS_UTILS_H
