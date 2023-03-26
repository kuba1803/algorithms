//
// Created by Jakub on 25.03.2023.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H
#include <iterator>
#include <experimental/random>

namespace UTILS {
    template<typename RandomIt>
    RandomIt minimum(RandomIt begin, RandomIt end){
        RandomIt *min = begin;
        for(RandomIt it = begin; begin!=end;it++){
            min = (*min<*it)?min:it;
        }
        return min;
    }

    template<typename RandomIt>
    RandomIt maximum(RandomIt begin, RandomIt end){
        RandomIt *max = begin;
        for(RandomIt it = begin; begin!=end;it++){
            max = (*max>*it)?max:it;
        }
        return max;
    }

    template<typename Container, typename Comparator>
    inline auto select(Container &container, int start, int end, int n, Comparator comper) {
        if (start == end ) return container[start];
        int q;
        do {
            q = start;
            for (int j = start; j < end; j++) {
                if (comper(container[j], container[end])) {
                    std::swap(container[q], container[j]);
                    q++;
                }
            }
            std::swap(container[q], container[end]);
            if( n < q ) end = q - 1;
            else if( n > q ) {
                start = q+1;
            }
        } while (n != q && start != end);
        if (start == end ) return container[start];
        return container[q];
    }
}

#endif //ALGORITHMS_UTILS_H
