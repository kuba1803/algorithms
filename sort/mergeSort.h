#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H
#include <list>
#include "insertionSort.h"
namespace SORT {
    template<typename RandomIt, typename Comparator>
    inline void merge(RandomIt begin, RandomIt split, RandomIt end, Comparator compere) {
        std::list<typename std::iterator_traits<RandomIt>::value_type> L, R;

        for (RandomIt it = begin; it != split; it++) {
            L.push_back(std::move(*it));
        }
        for (RandomIt it = split; it != end; it++) {
            R.push_back(std::move(*it));
        }
        decltype(L.begin()) lIt = L.begin();
        decltype(L.begin()) rIt = R.begin();
        RandomIt it = begin;

        while (lIt != L.end() && rIt != R.end()) {
            if (compere(*lIt, *rIt)) {
                *it = std::move(*lIt);
                it++;
                lIt++;
            } else {
                *it = std::move(*rIt);
                it++;
                rIt++;
            }
        }
        while (lIt != L.end()) {
            *it = std::move(*lIt);
            it++;
            lIt++;
        }
        while (rIt != R.end()) {
            *it = std::move(*rIt);
            it++;
            rIt++;
        }
    }

    template<typename Container, typename Comparator>
    inline void merge(Container & container, int begin, int split, int end, Comparator compere){
        std::list<typename std::remove_pointer<int*>::type> L, R;

        for (int it = begin; it != split; it++) {
            L.push_back(std::move(container[it]));
        }
        for (int it = split; it != end; it++) {
            R.push_back(std::move(container[it]));
        }

        decltype(L.begin()) lIt = L.begin();
        decltype(L.begin()) rIt = R.begin();
        int it = begin;

        while (lIt != L.end() && rIt != R.end()) {
            if (compere(*lIt, *rIt)) {
                container[it] = std::move(*lIt);
                it++;
                lIt++;
            } else {
                container[it] = std::move(*rIt);
                it++;
                rIt++;
            }
        }
        while (lIt != L.end()) {
            container[it] = std::move(*lIt);
            it++;
            lIt++;
        }
        while (rIt != R.end()) {
            container[it] = std::move(*rIt);
            it++;
            rIt++;
        }
    }

    template<typename RandomIt, typename Comparator>
    inline void mergeSort(RandomIt begin, RandomIt end, Comparator compere) {
        int mergeDistance = 16;
        int overallDistance = 0;
        int distance = 0;
        int spiltDistance;
        RandomIt leftIt, rightIt, it;
        rightIt = begin;
        leftIt = begin;
        while (rightIt != end) {
            while (distance < mergeDistance && rightIt != end) {
                distance++;
                overallDistance++;
                rightIt++;
            }
            insertionSort(leftIt, rightIt, compere);
            distance = 0;
            leftIt = rightIt;
        }
        do {
            distance = 0;
            spiltDistance = mergeDistance;
            mergeDistance *= 2;
            rightIt = begin;
            leftIt = begin;
            do {
                while (distance < spiltDistance && rightIt != end) {
                    distance++;
                    rightIt++;
                }
                if (rightIt == end) {
                    continue;
                }
                it = rightIt;
                while (distance < mergeDistance && rightIt != end) {
                    distance++;
                    rightIt++;
                }
                merge(leftIt, it, rightIt, compere);
                leftIt = rightIt;
                distance = 0;
            } while (rightIt != end);
        } while (mergeDistance < overallDistance);
    }

    template<typename Container, typename Comparator>
    inline void mergeSort(Container &container, int start, int size, Comparator compere) {
        int mergeDistance = 16;
        int overallDistance = size - start;
        int left, right;
        right = 0;
        left = 0;
        while (right != size) {
            right += mergeDistance;
            if (right > size) {
                right = size;
            }
            insertionSort(container, left, right, compere);
            left = right;
        }
        do {
            right = 0;
            left = 0;
            do {
                right += mergeDistance;
                if (right >= size) {
                    right = size;
                    continue;
                }
                right += mergeDistance;
                if (right >= size) {
                    right = size;
                }
                merge(container, left, left + mergeDistance, right, compere);
                left = right;
            } while (right != size);
            mergeDistance *= 2;
        } while (mergeDistance < overallDistance);
    }
}
#endif //ALGORITHMS_MERGESORT_H
