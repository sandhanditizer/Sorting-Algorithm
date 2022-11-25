/*
Zachariah Kline
18 NOV 2021
Functions that populate an array in different ways.
*/

#include <random>


int random_num(int min, int max) {
    static std::random_device rd;
    static std::mt19937_64 engine{rd()};
    std::uniform_int_distribution<int> dist{min, max};
    return dist(engine);
}

void populate_randomly(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        array[i] = random_num(0, size);
    }
}

void populate_reverse(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
}

void populate_part(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        int even = i*2;
        if(i%2 == 0) {
            array[i] = even;
        }
        else {
            array[i] = i*2 - 3;
        }
    } 
}

void populate(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        array[i] = i;
    }
}