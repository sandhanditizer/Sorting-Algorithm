/*
Zachariah Kline
1 DEC 2021
Integar array sorting algorithms.
*/

#pragma once


void bubble_sort(int container[], int size_of_container);

void heapify_subtree(int array[], int parent, int size);
void heapify(int array[], int size);
void heap_sort(int array[], int size);

void insertion_sort(int array[], int size);

int median(int array[], int low, int high);
int partition (int array[], int low, int high);
void quick_sort(int array[], int low, int high);

