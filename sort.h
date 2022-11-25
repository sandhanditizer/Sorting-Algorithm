/*
Zachariah Kline
1 DEC 2021
Personalized sorting algorithm that I entered a competition with.

I did some testing with populating the array with random data:
Num of elements | Estimated Runtime (sec)
1 ................. 0
10 ................ 0.000003
100 ............... 0.000014
1000 .............. 0.000302
10000 ............. 0.010510
100000 ............ 0.036975
1000000 ........... 0.277974
2000000 ........... 0.625725
*/

#pragma once
#include "algorithms.h"


namespace Zachariahs_Alg {
    void sort(int array[], int size) {
        //Checks if the array is already sorted correctly.
        bool presorted = true;
        for(int i = 1; i < size; ++i) {
            if(array[i - 1] > array[i]) {
                presorted = false;
            }
        }
        if(presorted) {
            return;
        }

        //Checks what range the array size falls into.
        bool size_large = false; // >= 5,000
        bool size_normal = false; // >= 100
        bool size_small = false; // >= 0
        if(size >= 5000) {
            size_large = true;
        }
        else if(size >= 100) {
            size_normal = true;
        }
        else {
            size_small = true;
        }

        //Check to see if the array is partially sorted (works well for any size).
        if(array[0] <= array[size / 4] && array[size / 4] <= array[size / 2] && array[size / 2] <= array[(size*3) / 4] && array[(size*3) / 4] <= array[size - 1]) {
            insertion_sort(array, size);
            return;
        }

        //If the array is not partially sorted or completely sorted,
        //then depending on size one of these will be used.
        if(size_large) {
            quick_sort(array, 0, size);
            return;
        }
        if(size_normal) {
            heap_sort(array, size);
            return;
        }
        if(size_small) {
            insertion_sort(array, size);
            return;
        }
    }
}
