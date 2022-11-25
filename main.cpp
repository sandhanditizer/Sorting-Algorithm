/*
Zachariah Kline
1 DEC 2021
Testing my sorting algorithm
*/

#include <iostream>
#include "sort.h"
#include "timer.h"
#include "populate.h"

int main() {
    int a[100];
    int size_a = sizeof(a)/sizeof(a[0]);
    populate_randomly(a, size_a);

    Timer timer;
    timer.start();
    Zachariahs_Alg::sort(a, size_a);
    std::cout << timer.stop();
}