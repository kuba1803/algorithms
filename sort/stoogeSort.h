//
// Created by Jakub on 22.03.2023.
//

#ifndef ALGORITHMS_STOOGESORT_H
#define ALGORITHMS_STOOGESORT_H

#include <algorithm>
#include <stack>
#include <tuple>
#include <cmath>

namespace SORT {

    template<typename Container, typename Comparator>
    inline void stoogeSort(Container &container, int start, int size, Comparator &compere) {
        std::stack<std::tuple<int, int>> stack;
        std::tuple<int, int> range;
        int k;
        stack.push(std::tuple<int, int>(start, size));
        while (!stack.empty()) {
            range = std::move(stack.top());
            stack.pop();
            if (!compere(container[std::get<0>(range)], container[std::get<1>(range) - 1])) {
                std::swap(container[std::get<0>(range)], container[std::get<1>(range) - 1]);
            }
            if ((std::get<0>(range) + 1) >= (std::get<1>(range) - 1))continue;
            k = std::floor((std::get<1>(range) - std::get<0>(range)) / 3);
            stack.push(std::tuple<int, int>(std::get<0>(range), std::get<1>(range) - k));
            stack.push(std::tuple<int, int>(std::get<0>(range) + k, std::get<1>(range)));
            stack.push(std::tuple<int, int>(std::get<0>(range), std::get<1>(range) - k));

        }
    }
}

#endif //ALGORITHMS_STOOGESORT_H
