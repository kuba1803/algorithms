#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <algorithm>
#include <stack>
#include <tuple>

namespace SORT {

    template<typename RandomIt, typename Comparator>
    inline void quickSort(RandomIt begin, RandomIt end, Comparator &compere) {
        std::stack<std::tuple<RandomIt, RandomIt>> stack;
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
                if (compere(*j, *tempEnd)) {
                    std::swap(*i, *j);
                    i++;
                }
            }
            std::swap(*i, *tempEnd);
            tempEnd = temp = std::get<0>(range);
            while (temp != i) {
                tempEnd = temp;
                temp++;
            }
            if (std::get<0>(range) != tempEnd)stack.push(std::tuple<RandomIt, RandomIt>(std::get<0>(range), i ));
            i++;
            if (i != std::get<1>(range)) stack.push(std::tuple<RandomIt, RandomIt>(tempEnd, std::get<1>(range)));

        }
    }

    template<typename Container, typename Comparator>
    inline void quickSort(Container &container, int start, int size, Comparator &compere) {
        std::stack<std::tuple<int, int>> stack;
        std::tuple<int, int> range;
        int i;
        stack.push(std::tuple<int, int>(start, size));
        while (!stack.empty()) {
            range = std::move(stack.top());
            stack.pop();
            i = std::get<0>(range);
            for (int j = std::get<0>(range); j < std::get<1>(range) - 1; j++) {
                if (compere(container[j], container[std::get<1>(range) - 1])) {
                    std::swap(container[i], container[j]);
                    i++;
                }
            }
            std::swap(container[i], container[std::get<1>(range) - 1]);
            if (std::get<0>(range) < i - 1)stack.push(std::tuple<int, int>(std::get<0>(range), i ));
            if (i + 1 < std::get<1>(range)) stack.push(std::tuple<int, int>(i + 1, std::get<1>(range)));

        }
    }
}

#endif //ALGORITHMS_QUICKSORT_H
