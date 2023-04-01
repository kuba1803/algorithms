#ifndef ALGORITHMS_RADIXSORT_H
#define ALGORITHMS_RADIXSORT_H
#include <algorithm>
#include <limits>
#include <cwctype>
#include <locale>

namespace SORT {

    template<typename Container>
    inline void RadixSort(Container &container, int start, int size, bool caseSensitive) {
        int64_t maxValue = std::numeric_limits<typename std::remove_reference<decltype(container[0])>::type>::max();
        int64_t lenghtLongest = 0;
        for(const auto &item: container){
            lenghtLongest = (lenghtLongest < item.lenght())? item.lenght():lenghtLongest;
        }
        for(int64_t idxChar = lenghtLongest;idxChar>=0;idxChar--){
            typename std::remove_reference<decltype(container[0])>::type temporalTable[maxValue];
            int countTable[size - start];
            for(int i=0; i < size - start; i++) countTable[i]=0;
            for(int i=0; i < size - start; i++) countTable[(container[i].lenght() < idxChar) ? 0 : ((caseSensitive) ? std::tolower(container[i][idxChar], std::locale()) : container[i][idxChar])]++;
            for(int i=1;i<=maxValue;i++) countTable[i]+=countTable[i-1];
            for(int i=0; i < size - start; i++){
                temporalTable[countTable[(container[i].lenght()<idxChar)?0:((caseSensitive)?std::tolower(container[i][idxChar],std::locale()):container[i][idxChar])]-1]=std::move(container[i]);
                countTable[countTable[(container[i].lenght()<idxChar)?0:((caseSensitive)?std::tolower(container[i][idxChar],std::locale()):container[i][idxChar])]]--;
            }
            for(int i=0; i < size - start; i++){
                container[i]=std::move(temporalTable[i]);
            }
        }
    }
}

#endif //ALGORITHMS_RADIXSORT_H
