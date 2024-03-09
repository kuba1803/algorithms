
#include "../sort/bubbleSort.h"
#include "../sort/countSort.h"
#include "../sort/heapSort.h"
#include "../sort/insertionSort.h"
#include "../sort/mergeSort.h"
#include "../sort/quickSort.h"
#include "../sort/radixSort.h"
#include "../sort/selectionSort.h"
#include "../sort/shellSort.h"
#include "../sort/stoogeSort.h"
#include <vector>
#include <gtest/gtest.h>

namespace {
TEST(Sort, bubbleSort_vector) {
        std::vector<int> table({1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> ittable = table;
        std::vector<int> sorted({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::bubbleSort(ittable.begin(), ittable.end(), [](int a, int b) { return a < b; });
        SORT::bubbleSort(table, 0, table.size(), [](int a, int b) { return a < b; });

        EXPECT_EQ(table, sorted);
        EXPECT_EQ(ittable, sorted);
    }

TEST(Sort, countSort) {
        std::vector<int> table({1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> sorted({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::countSort(table, 0, table.size(), 20);

        EXPECT_EQ(table, sorted);
    }

    TEST(Sort, heapSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::heapSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
    }

    TEST(Sort, insertionSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> ittable = table;
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::insertionSort(ittable.begin(),ittable.end(),[](int a,int b){return a < b;});
        SORT::insertionSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
        EXPECT_EQ(ittable, sorted);
    }

    TEST(Sort, mergeSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> ittable = table;
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::mergeSort(ittable.begin(),ittable.end(),[](int a,int b){return a < b;});
        SORT::mergeSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
        EXPECT_EQ(ittable, sorted);
    }

    TEST(Sort, quickSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> ittable = table;
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::quickSort(ittable.begin(),ittable.end(),[](int a,int b){return a < b;});
        SORT::quickSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
        EXPECT_EQ(ittable, sorted);
    }

    TEST(Sort, selectionSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int> ittable = table;
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::selectionSort(ittable.begin(),ittable.end(),[](int a,int b){return a < b;});
        SORT::selectionSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
        EXPECT_EQ(ittable, sorted);
    }

    TEST(Sort, shellSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::shellSort(table,0,table.size(),[](int a,int b){return a < b;});
        EXPECT_EQ(table, sorted);
    }

    TEST(Sort, stoogeSort) {
        std::vector<int> table( {1, 10, 9, 8, 2, 5, 7, 3, 4, 6, 13, 12, 11});
        std::vector<int>  sorted( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        SORT::stoogeSort(table,0,table.size(),[](int a,int b){return a < b;});

        EXPECT_EQ(table, sorted);
    }

    TEST(Sort, bubbleSort_random) {
        int table[100];
        int ittable[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            ittable[i]=table[i];
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::bubbleSort(ittable,ittable+100,[](int a,int b){return a < b;});
        SORT::bubbleSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
        EXPECT_EQ(std::vector(ittable,ittable+100), std::vector(sorted,sorted+100));

    }

   TEST(Sort, countSort_random) {
        int table[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand()%100;
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::countSort(table, 0, 100,100 );

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
    }

    TEST(Sort, heapSort_random) {
        int table[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::heapSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
    }

    TEST(Sort, insertionSort_random) {
        int table[100];
        int ittable[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            ittable[i]=table[i];
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::insertionSort(ittable,ittable+100,[](int a,int b){return a < b;});
        SORT::insertionSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
        EXPECT_EQ(std::vector(ittable,ittable+100), std::vector(sorted,sorted+100));

    }

    TEST(Sort, mergeSort_random) {
        int table[100];
        int ittable[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            ittable[i]=table[i];
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::mergeSort(ittable,ittable+100,[](int a,int b){return a < b;});
        SORT::mergeSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
        EXPECT_EQ(std::vector(ittable,ittable+100), std::vector(sorted,sorted+100));

    }

    TEST(Sort, quickSort_random) {
        int table[100];
        int ittable[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            ittable[i]=table[i];
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::quickSort(ittable,ittable+100,[](int a,int b){return a < b;});
        SORT::quickSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
        EXPECT_EQ(std::vector(ittable,ittable+100), std::vector(sorted,sorted+100));

    }

    TEST(Sort, selectionSort_random) {
        int table[100];
        int ittable[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            ittable[i]=table[i];
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::selectionSort(ittable,ittable+100,[](int a,int b){return a < b;});
        SORT::selectionSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
        EXPECT_EQ(std::vector(ittable,ittable+100), std::vector(sorted,sorted+100));
    }

    TEST(Sort, shellSort_random) {
        int table[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::shellSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
    }

    TEST(Sort, stoogeSort_random) {
        int table[100];
        int sorted[100];
        for(int i =0;i<100;i++)
        {
            table[i]=rand();
            sorted[i]=table[i];
        }
        std::sort(sorted,sorted+100,[](int a,int b){return a < b;});
        SORT::stoogeSort(table,0,100,[](int a,int b){return a < b;});

        EXPECT_EQ(std::vector(table,table+100), std::vector(sorted,sorted+100));
    }

}