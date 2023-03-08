#ifndef ALGORITHMS_SEARCH_H
#define ALGORITHMS_SEARCH_H

namespace SEARCH {

    template<typename Item, typename Container,typename Comparator>
    inline int binary_search(Container &container, int start, int end, Item item, Comparator comper){
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

    template<typename Item, typename Container >
    inline int lineary_search(Container &container, int start, int end, Item &item){
        for(int i = start;i<end;i++){
            if( item == container[i] ) return i;
        }
        return end;
    }

    template<typename RandomIt, typename Item>
    inline RandomIt lineary_search(RandomIt begin, RandomIt end, Item &item) {
        for(RandomIt *it = begin;it!=end;it++){
            if( item == *it ) return it;
        }
        return end;
    }

}

#endif //ALGORITHMS_SEARCH_H
