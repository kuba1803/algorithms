#ifndef ALGORITHMS_COUNTSORT_H
#define ALGORITHMS_COUNTSORT_H
#include <algorithm>

namespace SORT {

    template<typename Container>
    inline void countSort(Container &container, int start, int size, int64_t maxValue) {
        typename std::remove_reference<decltype(container[0])>::type temporalTable[maxValue+1];
        int countTable[size - start];
        for(int i=0; i < size - start; i++) countTable[i]=0;
        for(int i=0; i < size - start; i++) countTable[container[i]]++;
        for(int i=1;i<=maxValue;i++) countTable[i]+=countTable[i-1];
        for(int i=0; i < size - start; i++){
            temporalTable[countTable[container[i]]-1]=std::move(container[i]);
            countTable[container[i]]--;
        }
        for(int i=0; i < size - start; i++){
            container[i]=std::move(temporalTable[i]);
        }

    }
}
#endif //ALGORITHMS_COUNTSORT_H
