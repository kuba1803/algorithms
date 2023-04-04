#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <algorithm>

namespace SORT {

    template<typename RandomIt, class Comparator>
    inline void selectionSort(RandomIt begin, RandomIt end, Comparator &compere) {
        RandomIt min;
        while (begin!=end){
            min = begin;
            RandomIt it = begin;
            it++;
            for( ;it!=end;it++){
                if(!compere(*min,*it)){
                    min = it;
                }
            }
            if(min != begin)std::swap(*min,*begin);
            begin++;
        }
    }

    template<class Container, class Comparator>
    inline void selectionSort(Container &container, int start, int size, Comparator &compere) {
        int maxIn = size - 1;
        while (maxIn != start) {
            for (int in = start; in != maxIn; in++) {
                if (!compere(container[in], container[maxIn])) {
                    std::swap(container[in], container[maxIn]);
                }
            }
            maxIn--;
        }
    }
}
#endif //ALGORITHMS_SELECTIONSORT_H
