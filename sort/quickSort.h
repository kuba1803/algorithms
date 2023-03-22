//
// Created by Jakub on 20.03.2023.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <algorithm>
#include <stack>
#include <tuple>

namespace SORT {

    template<typename RandomIt, typename Comparator>
    inline void quickSort(RandomIt begin, RandomIt end, Comparator comper) {
        std::stack<std::tuple<int, int>> stack;
        std::tuple<RandomIt, RandomIt> range;
        RandomIt i, tempEnd, temp;
        stack.push(std::tuple<RandomIt, RandomIt>(begin, end));
        while (!stack.empty()) {
            range = std::move(stack.top());
            stack.pop();
            i = std::get<0>(range);
            while (i != std::get<1>(range)) {
                tempEnd = i;
                i++;
            }
            i = std::get<0>(range);
            for (RandomIt j = std::get<0>(range); j != tempEnd; j++) {
                if (comper(*j, *tempEnd)) {
                    std::swap(i, j);
                    i++;
                }
            }
            std::swap(i, tempEnd);
            tempEnd = temp = std::get<0>(range);
            while (temp != i) {
                tempEnd = temp;
                temp++;
            }
            if (std::get<0>(range) != tempEnd)stack.push(std::tuple<int, int>(std::get<0>(range), i - 1));
            i++;
            if (i != std::get<1>(range)) stack.push(std::tuple<int, int>(i, std::get<1>(range)));

        }
    }

    template<typename Container, typename Comparator>
    inline void quickSort(Container &container, int start, int end, Comparator comper) {
        std::stack<std::tuple<int, int>> stack;
        std::tuple<int, int> range;
        int i;
        stack.push(std::tuple<int, int>(start, end));
        while (!stack.empty()) {
            range = std::move(stack.top());
            stack.pop();
            i = std::get<0>(range);
            for (int j = std::get<0>(range); j < std::get<1>(range) - 1; j++) {
                if (comper(container[j], container[std::get<1>(range) - 1])) {
                    std::swap(container[i], container[j]);
                    i++;
                }
            }
            std::swap(container[i], container[std::get<1>(range) - 1]);
            if (std::get<0>(range) < i - 1)stack.push(std::tuple<int, int>(std::get<0>(range), i - 1));
            if (i + 1 < std::get<1>(range)) stack.push(std::tuple<int, int>(i + 1, std::get<1>(range)));

        }
    }
}

#endif //ALGORITHMS_QUICKSORT_H