#ifndef ALGORITHMS_HEAPSORT_H
#define ALGORITHMS_HEAPSORT_H

#include <algorithm>

namespace SORT {
    inline int parent(int i) {
        return i >> 1;
    }

    inline int left(int i) {
        return i << 1;
    }

    inline int right(int i) {
        return (i << 1) + 1;
    }

    template<typename Container, typename Comparator >
    inline void heapify(Container &container, int start, int end, int i, Comparator compere) {
        int l;
        int r;
        int top;
        while (true) {
            l = left(i - start) + start;
            r = right(i - start) + start;
            if (l <= end && compere(container[i - 1], container[l - 1])) {
                top = l;
            } else {
                top = i;
            }
            if (r <= end && compere(container[top - 1], container[r - 1])) {
                top = r;
            }
            if (top != i) {
                std::swap(container[i-1], container[top-1]);
                i = top;
            } else {
                return;
            }
        }
    }

    template<typename Container, typename Comparator >
    inline void buildHeap(Container &container, int start, int end, Comparator compere) {
        for (int i = (end - start ) / 2; i >= 1; i--) {
            heapify(container, start, end, i + start, compere);
        }
    }

    template<typename Container, typename Comparator>
    inline void heapSort(Container &container, int start, int size, Comparator compere) {
        buildHeap(container, start, size, compere);
        for (int i = size ; i >= 2 + start; i--) {
            std::swap(container[start], container[i-1]);
            size--;
            heapify(container, start, size, start + 1, compere);
        }
    }
}
#endif //ALGORITHMS_HEAPSORT_H
