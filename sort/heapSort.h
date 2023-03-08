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

    template<class Container, class Comperator>
    inline void heapify(Container &container, int start, int end, int i, Comperator comper) {
        int l;
        int r;
        int top;
        while (true) {
            l = left(i - start) + start;
            r = right(i - start) + start;
            if (l <= end && comper( container[i-1], container[l-1])) {
                top = l;
            } else {
                top = i;
            }
            if (r <= end && comper( container[top-1], container[r-1])) {
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

    template<class Container, class Comperator>
    inline void buildHeap(Container &container, int start, int end, Comperator comper) {
        for (int i = (end - start ) / 2; i >= 1; i--) {
            heapify(container, start, end, i + start, comper);
        }
    }

    template<class Container, class Comperator>
    inline void heapSort(Container &container, int start, int end, Comperator comper) {
        buildHeap(container, start, end, comper);
        for (int i = end ; i >= 2 + start; i--) {
            std::swap(container[start], container[i-1]);
            end--;
            heapify(container, start, end, start+1, comper);
        }
    }
}
#endif //ALGORITHMS_HEAPSORT_H
