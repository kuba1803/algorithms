#ifndef ALGORITHMS_SEARCH_H
#define ALGORITHMS_SEARCH_H

namespace SEARCH {

    template<class Item, class Container,class Comper>
    inline int binary_search(Container &container, int start, int end, Item item, Comper comper){
        int tmp;
        while(start<end){
            tmp=(start+end)/2;
            if(!comper(item,container[tmp])){
                start = tmp+1;
            }
            else{
                end = tmp;
            }
        }
        return start;
    }

    template<class Item, class Container,class Comper>
    inline int lineary_search(Container &container, int start, int end, Item &item){
        for(int i = start;i<end;i++){
            if( item == container[i] ) return i;
        }
        return end;
    }

    template<class RandomIt, class T>
    inline RandomIt lineary_search(RandomIt begin, RandomIt end, T &item) {
        for(RandomIt *it = begin;it!=end;it++){
            if( item == *it ) return it;
        }
        return end;
    }

}

#endif //ALGORITHMS_SEARCH_H
