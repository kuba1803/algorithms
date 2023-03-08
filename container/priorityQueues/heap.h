//
// Created by Dorota on 08.03.2023.
//

#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H
#include <vector>
#include <functional>

namespace CONTAINER{
    namespace PRIORITY_QUEUE{

        template<typename T, typename Container = std::vector<T>,
                typename Comparator = std::less<typename Container::value_type> >
        class Heap{
        private:
           Container container;

        };
    }
}
#endif //ALGORITHMS_HEAP_H
