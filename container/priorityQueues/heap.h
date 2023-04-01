
#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <functional>
#include "../array.h"

namespace CONTAINER {

    template<typename T,
            typename Comparator,
            typename Container = Array<T>>
    class Heap {
    protected:
        Container container;
        Comparator compere;

        inline void buildHeap(int start, int end, Comparator compere) {
            for (int i = (end - start ) / 2; i >= 1; i--) {
                heapifyDown(i + start);
            }
        }

        void heapifyUp(int index) {
            index++;
            while (index > 1 && !compere(container[parent(index) - 1], container[index - 1])) {
                std::swap(container[index - 1], container[parent(index) - 1]);
                index = parent(index);
            }
        }

        void heapifyDown(int index) {
            int l;
            int r;
            int top;
            index++;
            while (true) {
                l = left(index);
                r = right(index);
                if (l <= container.size() && compere(container[index - 1], container[l - 1])) {
                    top = l;
                } else {
                    top = index;
                }
                if (r <= container.size() && compere(container[top - 1], container[r - 1])) {
                    top = r;
                }
                if (top != index) {
                    std::swap(container[index - 1], container[top - 1]);
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
#pragma region types
        typedef T					                          value_type;
        typedef T*	     		                              pointer;
        typedef const T*                                      const_pointer;
        typedef T&  		                                  reference;
        typedef const T&   	                                  const_reference;
        typedef __gnu_cxx::__normal_iterator<pointer, Container>      iterator;
        typedef __gnu_cxx::__normal_iterator<const_pointer, Container>
                const_iterator;
        typedef std::reverse_iterator<const_iterator>	      const_reverse_iterator;
        typedef std::reverse_iterator<iterator>		          reverse_iterator;
        typedef size_t					                      size_type;
        typedef ptrdiff_t				                      difference_type;

#pragma endregion types

#pragma region constructors

        explicit Heap(const Comparator& comparator) :compere(comparator) {
        }

        Heap( const Comparator& comparator, const Container& cont ): compere(comparator), container(cont){
            buildHeap(0,container.size());
        }

        Heap( const Comparator& comparator, const Container&& cont ): compere(comparator), container(std::move(cont)){
            buildHeap(0,container.size());
        }

        explicit Heap(Comparator comparator, int size) :compere(comparator),container(size) {
        }

        Heap(const Heap &heap) : compere(heap.compere),container(heap.container) {
        }

        Heap(const Heap &&heap) noexcept: compere(std::move(heap.compere)),
                                          container(std::move(heap.container))  {
        }

        template< class InputIt >
        Heap( InputIt first, InputIt last,const Comparator& compare ):container(first,last),compere(compere){
            buildHeap(0,container.size());
        }

        template< class InputIt >
        Heap( InputIt first, InputIt last,const Comparator& compare, const Container& cont):container(cont),compere(compere){
            container.push(container.end(), first, last);
            buildHeap(0,container.size());
        }

        template< class InputIt >
        Heap( InputIt first, InputIt last,
        const Comparator& compare, Container&& cont ): compere(compere), container(std::move(cont)){
            container.push(container.end(), first, last);
            buildHeap(0,container.size());
        }

#pragma endregion constructor

#pragma region destructor

        ~Heap() {
            delete[] container;
        }

#pragma endregion destructor

#pragma region operator=

        Heap & operator=(const Heap & heap){
            if(this != &heap) {
                compere = heap.compere;
                container = heap.container;
            }
            return *this;
        }

        Heap & operator=(Heap && heap) noexcept{
            if(this != &heap) {
            compere = std::move(heap.compere);
            container = std::move(heap.container);
            }
            return *this;
        }

#pragma endregion operator=

#pragma region access

        const_reference top() const {
            return container[0];
        }

        T extractTop() {
            T top = std::move(container[0]);
            std::swap(container[0],container[container.size() - 1]);
            container.pop_back();
            if (container.size() < container.max_size() / 2 && container.size() > 1) {
                container.resize(container.max_size() >> 1);
            }
            heapifyDown(0);
            return std::move(top);
        }

#pragma endregion access

#pragma region capacity

        [[nodiscard]] int  size() const {
            return container.size();
        }

        [[nodiscard]] bool empty() const {
            return container.size() == 0;
        }

#pragma endregion capacity

#pragma region modificators

        void swap(Heap & other){
            std::swap(container, other.container);
            std::swap(compere,other.compere);
        }

        void push(const T& item) {
            if (container.size() == container.max_size()) {
                container.resize(container.max_size() << 1);
            }
            container.push_back(item);
            heapifyUp(container.size()-1);
        }

        void push(T&& item) {
            if (container.size() == container.max_size()) {
                container.resize(container.max_size() << 1);
            }
            container.push_back(std::move(item));
            heapifyUp(container.size()-1);
        }

        template<typename Range>
        void push(const Range & range) {
            for(auto item: range){
                push(std::move(item));
            }
        }

        template<class... Args>
        void emplace( Args &&... args) {
            push(std::move(T(std::forward<Args>(args)...)));
        }

        void pop(){
            extractTop();
        }

#pragma endregion modificators
    };

    template <class Comp, class Container>
    Heap(Comp, Container)
    -> Heap<typename Container::value_type, Container, Comp>;
}

namespace std{
    template<typename T,
            typename Comparator>
    void swap(CONTAINER::Heap<T,Comparator>& v1, CONTAINER::Heap<T,Comparator>& v2) {
        v1.swap(v2);
    }
}

#endif //ALGORITHMS_HEAP_H
