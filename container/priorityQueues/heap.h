
#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <functional>
#include <queue>

namespace CONTAINER {

    template<typename T,
            typename Comparator>
    class Heap {
    private:
        T *array;
        int arraySize;
        int arrayCapacity;
        Comparator compere;

        void heapify() {
            int l;
            int r;
            int top;
            int index = 1;
            while (true) {
                l = left(index);
                r = right(index);
                if (l <= arraySize && compere(array[index - 1], array[l - 1])) {
                    top = l;
                } else {
                    top = index;
                }
                if (r <= arraySize && compere(array[top - 1], array[r - 1])) {
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

        inline void resize(int size){
            T *temp = new T[size];
            for (int i = 0; i < arraySize; i++) {
                temp[i] = std::move(array[i]);
            }
            std::swap(*array, *temp);
            delete[] temp;
            arrayCapacity = size;
        }

    public:
        explicit Heap(Comparator comparator) : arraySize(0), arrayCapacity(1), compere(comparator) {
            array = new T[arrayCapacity];
        }

        explicit Heap(Comparator comparator, int size) : arraySize(0), arrayCapacity(size), compere(comparator) {
            array = new T[arrayCapacity];
        }

         Heap(const Heap &heap) : arraySize(heap.arraySize), arrayCapacity(heap.arrayCapacity),
                                          compere(heap.compere) {
            array = new T[arrayCapacity];
            for (int i = 0; i < arraySize; i++) {
                array[i] = heap.array[i];
            }
        }

        Heap(const Heap &&heap) noexcept: arraySize(std::move(heap.arraySize)),
                                           arrayCapacity(std::move(heap.arrayCapacity)),
                                           compere(std::move(heap.compere)),
                                           array(std::move(heap.array))  {

        }

        ~Heap() {
            delete[] array;
        }

        Heap & operator=(const Heap & heap){
            if(this != &heap) {
                delete[] array;
                arraySize = heap.arraySize;
                compere = heap.compere;
                arrayCapacity = heap.arrayCapacity;
                array = new T[arrayCapacity];
                for (int i; i < arraySize; i++) {
                    array[i] = heap.array[i];
                }
            }
            return *this;
        }

        Heap & operator=(Heap && heap) noexcept{
            delete[] array;
            arraySize = heap.arraySize;
            compere = heap.compere;
            arrayCapacity = heap.arrayCapacity;
            array = std::move(heap.array);
            return *this;
        }

        void swap(Heap & other){
             std::swap(array,other.array);
             std::swap(arraySize,other.arraySize);
             std::swap(arrayCapacity,other.arrayCapacity);
             std::swap(compere,other.compere);
        }

        [[nodiscard]] int  size() const {
            return arraySize;
        }

        [[nodiscard]] bool empty() const {
            return arraySize == 0;
        }

        T top() const {
            return array[0];
        }

        T extractTop() {
            T top = std::move(array[0]);
            array[0] = std::move(array[arraySize - 1]);
            arraySize--;
            if (arraySize < arrayCapacity / 2 + 10 && arraySize > 1) {
                resize(arrayCapacity >> 1);
            }
            heapify();
            return std::move(top);
        }

        void insert(const T item) {
            if (arraySize + 1 == arrayCapacity) {
                resize(arrayCapacity << 1);
            }
            array[arraySize] = std::move(item);
            arraySize++;
            int idx = arraySize;
            while (idx > 1 && !compere(array[parent(idx) - 1], array[idx - 1])) {
                std::swap(array[idx - 1], array[parent(idx) - 1]);
                idx = parent(idx);
            }
        }

        bool contain(const T &item) const {
            for (int i = 0; i < arraySize; i++) {
                if (array[i] == item) {
                    return true;
                }
            }
            return false;
        }
    };

    template<typename T,
            typename Comparator>
    void swap(Heap<T,Comparator>& v1, Heap<T,Comparator>& v2) {
        v1.swap(v2);
    }
}

#endif //ALGORITHMS_HEAP_H
