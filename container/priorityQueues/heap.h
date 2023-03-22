
#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <functional>

namespace CONTAINER {

        template<typename T,
                typename Comparator >
        class Heap {
        private:
            T *array;
            int arraySize;
            int arrayCapacity;
            static const int minArrayCapacity = 8;
            Comparator comper;

            void heapify(int index) {
                int l;
                int r;
                int top;
                index++;
                while (true) {
                    l = left(index);
                    r = right(index);
                    if (l <= arraySize && comper(array[index - 1], array[l - 1])) {
                        top = l;
                    } else {
                        top = index;
                    }
                    if (r <= arraySize && comper(array[top - 1], array[r - 1])) {
                        top = r;
                    }
                    if (top != index) {
                        std::swap(array[index - 1], array[top - 1]);
                        index = top;
                    } else {
                        return;
                    }
                }
            }
            inline int parent(int i) {
                return i >> 1;
            }

            inline int left(int i) {
                return i << 1;
            }

            inline int right(int i) {
                return (i << 1) + 1;
            }

        public:
            Heap(Comparator comparator):arraySize(0),arrayCapacity(minArrayCapacity),comper(comparator){
                array = new T[arrayCapacity];
            }
            int size() {
                return arraySize;
            }

            T top() {
                return array[0];
            }

            T extractTop() {
                T top = std::move(array[0]);
                array[0] = std::move(array[arraySize - 1]);
                arraySize--;
                if (arraySize < arrayCapacity / 2 + 10 && arraySize > minArrayCapacity) {
                    T *temp = new T[arrayCapacity >> 1];
                    for (int i = 0; i < arraySize; i++) {
                        temp[i] = std::move(array[i]);
                    }
                    std::swap(*array, *temp);
                    delete[] temp;
                    arrayCapacity >>= 1;
                }
                heapify(0);
                return top;
            }

            void insert(T item) {
                if (arraySize + 1 == arrayCapacity) {
                    T *temp = new T[arrayCapacity << 1];
                    for (int i = 0; i < arraySize; i++) {
                        temp[i] = std::move(array[i]);
                    }
                    std::swap(*array, *temp);
                    delete[] temp;
                    arrayCapacity <<= 1;
                }
                array[arraySize] = std::move(item);
                arraySize++;
                int idx = arraySize;
                while (idx > 1 && !comper(array[parent(idx)-1],array[idx - 1])) {
                    std::swap(array[idx - 1], array[parent(idx)-1]);
                    idx = parent(idx);
                }
            }
        };
}

#endif //ALGORITHMS_HEAP_H
