#ifndef ALGORITHMS_ARRAY_H
#define ALGORITHMS_ARRAY_H

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <vector>

namespace CONTAINER {
    template<typename T>
    class Array {
    private:
        T *array;
        size_t arraySize;
        size_t arrayCapacity;

    public:

#pragma region types
        typedef T					                          value_type;
        typedef T*	     		                              pointer;
        typedef const T*                                      const_pointer;
        typedef T&  		                                  reference;
        typedef const T&   	                                  const_reference;
        typedef __gnu_cxx::__normal_iterator<pointer, Array>      iterator;
        typedef __gnu_cxx::__normal_iterator<const_pointer, Array>
                const_iterator;
        typedef std::reverse_iterator<const_iterator>	      const_reverse_iterator;
        typedef std::reverse_iterator<iterator>		          reverse_iterator;
        typedef size_t					                      size_type;
        typedef ptrdiff_t				                      difference_type;

#pragma endregion types

#pragma region constructors

        explicit Array() : arraySize(0), arrayCapacity(1) {
            array = new T[arrayCapacity];
        }


        explicit Array(size_type size) : arraySize(0), arrayCapacity(size) {
            array = new T[arrayCapacity];
        }

        Array(size_type size, const T &value) : arraySize(0), arrayCapacity(size) {
            array = new T[arrayCapacity];
            for (; arraySize < arrayCapacity; arraySize++) {
                array[arraySize] = value;
            }
        }

        template<class InputIt,typename = std::_RequireInputIter<InputIt>>
        Array(InputIt first,
              InputIt last):arraySize(0), arrayCapacity(0){
            arrayCapacity = std::distance(first, last);
            array = new T[arrayCapacity];
            for (InputIt it = first; it != last; it++) {
                array[arraySize++] = *it;
            }
        }


        Array(std::initializer_list<T> init) : arraySize(0), arrayCapacity(init.size()) {
            array = new T[arrayCapacity];
            arraySize = 0;
            for (T &in: init) {
                array[arraySize++] = std::move(in);
            }
        }

        Array(const Array &other) : arrayCapacity(other.arrayCapacity), arraySize(other.arraySize) {
            array = new T[arrayCapacity];
            for (size_type i = 0; i < arrayCapacity; i++) {
                array[i] = other.array[i];
            }
        }

        Array(Array &&other) noexcept: arrayCapacity(other.arrayCapacity), arraySize(other.arraySize),
                                       array(std::move(other.array)) {
        }

#pragma endregion constructor

#pragma region destructor

        ~Array() {
            delete[] array;
        }

#pragma endregion destructor

#pragma region operator=

        Array &operator=(const Array &Array) {
            if (this != &Array) {
                delete[] array;
                arraySize = Array.arraySize;
                arrayCapacity = Array.arrayCapacity;
                array = new T[arrayCapacity];
                for (size_type i; i < arraySize; i++) {
                    array[i] = Array.array[i];
                }
            }
            return *this;
        }

        Array &operator=(Array &&Array) noexcept {
            delete[] array;
            arraySize = Array.arraySize;
            arrayCapacity = Array.arrayCapacity;
            array = std::move(Array.array);
            return *this;
        }

#pragma endregion operator=

#pragma region assign

        void assign(size_type count, const T &value) {
            delete[] array;
            arrayCapacity = count;
            arraySize = count;
            array = new T[arrayCapacity];
            for (size_type i = 0; i < arrayCapacity; i++) {
                array[i] = value;
            }
        }

        template<class InputIt>
        void assign(InputIt first, InputIt last) {
            delete[] array;
            arrayCapacity = 0;
            arrayCapacity = std::distance(first, last);
            array = new T[arrayCapacity];
            for (InputIt it = first; it != last; it++) {
                array[arraySize++] = *it;
            }
        }

        void assign(std::initializer_list<T> init) {
            delete[] array;
            arrayCapacity = init.size();
            array = new T[arrayCapacity];
            arraySize = 0;
            for (T &in: init) {
                array[arraySize++] = std::move(in);
            }
        }

        template<class Range>
        void assign(Range &range) {
            delete[] array;
            arrayCapacity = 0;
            for (auto &r: range) {
                arrayCapacity++;
            }
            array = new T[arrayCapacity];
            for (auto &r: range) {
                array[arraySize++] = r;
            }
        }

#pragma endregion assign

#pragma region access

        reference at(size_type n) {
            if (n < 0 || n >= arraySize)throw std::out_of_range("");
            return array[n];
        }

        const_reference at(size_type n) const {
            if (n < 0 || n >= arraySize)throw std::out_of_range("");
            return array[n];
        }

        reference operator[](size_type n) {
            return array[n];
        }

        const_reference operator[](size_type n) const {
            return array[n];
        }

        reference front() {
            return array[0];
        }

        const_reference front() const{
            return array[0];
        }

        reference back() {
            return array[arraySize - 1];
        }

        const_reference back() const {
            return array[arraySize -1];
        }

        T *data() noexcept {
            return array;
        }

        const T *data() const noexcept{
            return array;
        }

#pragma endregion access

#pragma region iterators

        iterator begin() {
            return iterator(array);
        }

        iterator end() {
            return iterator(array + arraySize);
        }

        reverse_iterator rbegin() {
            return std::reverse_iterator(array + arraySize);
        }

        reverse_iterator rend() {
            return std::reverse_iterator(array);
        }

#pragma endregion iterators

#pragma region capacity

        [[nodiscard]] size_type size() const {
            return arraySize;
        }

        [[nodiscard]] bool empty() const {
            return arraySize == 0;
        }

        [[nodiscard]] size_type max_size() const {
            return arrayCapacity;
        }

        void shrink_to_fit() {
            resize(arraySize);
        }

#pragma endregion capacity

#pragma region modificators

        void resize(size_type size) {
            T *temp = new T[size];
            for (size_type i = 0; i < arraySize; i++) {
                temp[i] = std::move(array[i]);
            }
            std::swap(array, temp);
            delete[] temp;
            arrayCapacity = size;
        }

        void resize(size_type size, const T &value) {
            T *temp = new T[size];
            for (size_type i = 0; i < arraySize; i++) {
                temp[i] = std::move(array[i]);
            }
            for (size_type i = arraySize; i < size; i++) {
                temp[i] = value;
            }
            std::swap(array, temp);
            delete[] temp;
            arrayCapacity = size;
        }

        void swap(Array<T> &item) {
            std::swap(array, item.array);
            std::swap(arraySize, item.arraySize);
            std::swap(arrayCapacity, item.arrayCapacity);
        }

        void clear() {
            resize(1);
            arraySize = 0;
        }

        iterator insert(const_iterator pos, const T value) {
            if (arraySize == arrayCapacity)resize(arrayCapacity << 1);
            auto it = end();
            for (; it != pos; it--) {
                *(it+1) = std::move(*(it));
            }
            *(++it) = std::move(value);
            arraySize++;
            return it;
        }

        iterator insert(const_iterator pos, size_type count, const T &value) {
            if (arraySize + count < arrayCapacity)resize(arrayCapacity << 1);
            auto it = end();
            for (; it != pos; it--) {
                *(it + count) = std::move(*(it));
            }
            for (size_type i = 0; i < count; i++)*(pos++) = value;
            arraySize += count;
            return --it;
        }

        template<class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last) {
            size_type count = std::distance(first, last);
            T *temp = pos;
            if (arraySize + count < arrayCapacity)resize(arrayCapacity << 1);
            for (auto it = end(); it != pos - 1; it--) {
                *(it + count) = std::move(*(it));
            }
            for (InputIt *it = first; it != last; it++)*(pos++) = *it;
            arraySize += count;
            return temp;
        }

        iterator insert(const_iterator pos, std::initializer_list<T> init) {
            T *temp = pos;
            if (arraySize + init.size() < arrayCapacity)resize(arrayCapacity << 1);
            for (auto *it = end() ; it != pos - 1; it--) {
                *(it + init.size()) = std::move(*(it));
            }
            for (auto &item: init)*(pos++) = std::move(item);
            arraySize += init.size();
            return temp;
        }

        template<class Range>
        iterator insert(const_iterator pos, const Range &range) {
            size_type count = 0;
            T *temp = pos;
            for (T *item: range)count++;
            if (arraySize + count < arrayCapacity)resize(arrayCapacity << 1);
            for (T *it = end() - 1; it != pos - 1; it--) {
                *(it + count) = std::move(*(it));
            }
            for (T item: range)*(pos++) = std::move(item);
            arraySize += count;
            return temp;
        }

        template<class... Args>
        iterator emplace(const_iterator pos, Args &&... args) {
            if (arraySize == arrayCapacity)resize(arrayCapacity << 1);
            auto it = end();
            for (; it != pos; it--) {
                *(it + 1) = std::move(*(it));
            }
            *(++it) = std::move(T(std::forward<Args>(args)...));
            arraySize++;
            return iterator(it);
        }

        iterator erase(const_iterator pos) {
            for (T *it = pos; it != end() - 1; it++) {
                *(it) = std::move(*(it + 1));
            }
            arraySize--;
            if (arraySize < (arrayCapacity >> 1))resize(arrayCapacity >> 1);
            return iterator(pos);
        }

        template<class InputIt>
        iterator erase(InputIt first, InputIt last) {
            size_type count = std::distance(first, last);
            for (auto it = first; it != last; it++) {
                *(it) = std::move(*(it + count));
            }
            arraySize -= count;
            if (arraySize < (arrayCapacity >> 1))resize(arrayCapacity >> 1);
            return first;
        }

        template<class... Args>
        iterator emplace_back(Args &&... args) {
            if (arraySize == arrayCapacity)resize(arrayCapacity << 1);
            array[arraySize] = std::move(T(std::forward<Args>(args)...));
            return array[arraySize++];
        }

        void push_back(T item) {
            if (arraySize == arrayCapacity)resize(arrayCapacity << 1);
            array[arraySize++] = std::move(item);
        }

        template<class Range>
        void push_back(const Range &range) {
            size_type count = 0;
            for (T *item: range)count++;
            if (arraySize + count < arrayCapacity)resize(arrayCapacity << 1);
            for (T item: range)array[arraySize++] = std::move(item);
        }

        void pop_back(){
            arraySize--;
            if (arraySize < (arrayCapacity >> 1) )resize(arrayCapacity >> 1);
        }

#pragma endregion modificators
    };

    template<typename InputIt,
            typename ValT = typename std::iterator_traits<InputIt>::value_type,
            typename = std::_RequireInputIter<InputIt>>
    Array(InputIt first,
          InputIt last) -> Array<ValT>;


    template<typename T>
    inline bool operator==(const Array<T> &rhs, const Array<T> &lhs) {
        if (rhs.size() != lhs.size()) return false;
        for (typename Array<T>::size_type i = 0; i < rhs.size(); i++) {
            if (rhs[i] != lhs[i]) return false;
        }
        return true;
    }

    template<typename T>
    inline auto operator<=>(const Array<T> &rhs, const Array<T> &lhs) {
        return std::lexicographical_compare_three_way(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template<typename T, typename U>
    inline typename Array<T>::size_type erase(Array<T> &vector, const U &value) {
        typename Array<T>::size_type count = 0;
        for (auto it = vector.begin(); it != vector.end();) {
            if (*it == value) {
                vector.erase(it);
                count++;
            } else it++;
        }
        return count;
    }


    template<typename T, typename Pred>
    inline typename Array<T>::size_type erase(Array<T> &vector, Pred pred) {
        typename Array<T>::size_type count = 0;
        for (auto it = vector.begin(); it != vector.end();) {
            if (pred(*it)) {
                vector.erase(it);
                count++;
            } else it++;
        }
        return count;
    }

}

namespace std {
    template<typename T>
    inline void swap(CONTAINER::Array <T> &v1, CONTAINER::Array <T> &v2) {
        v1.swap(v2);
    }
}

#endif //ALGORITHMS_ARRAY_H
