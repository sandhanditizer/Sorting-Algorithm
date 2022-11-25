/*
Zachariah Kline
1 DEC 2021
Integar array sorting algorithms.
*/

#include "algorithms.h"
#include <iostream>


void bubble_sort(int container[], int size_of_container) {
    bool swapped = false;
    for (int i = 0; i < size_of_container; ++i) {
        for (int n = 1; n < size_of_container; ++n) {
            if (container[n - 1] > container[n]) {
                std::swap(container[n - 1], container[n]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// --------------------------------------------------------------

// Assures the parent is larger than its two children in a subtree.
void heapify_subtree(int array[], int parent, int size) {
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;
    int largest = parent;
    
    if(left_child < size && array[left_child] > array[largest]) {
        largest = left_child;
    }
    if(right_child < size && array[right_child] > array[largest]) {
        largest = right_child;
    }
    if(largest != parent) {
        std::swap(array[parent], array[largest]);
        heapify_subtree(array, largest, size);
    }
}

// Percolates upward the largest item in the tree.
void heapify(int array[], int size) {
    int starting_p = size/2 - 1;
    for (; starting_p >= 0; --starting_p) {
        heapify_subtree(array, starting_p, size);
    }
}

void heap_sort(int array[], int size) {
    heapify(array, size);
    int starting_p = size/2 - 1;
    for(int n = size - 1; n >= 0; --n) {
        std::swap(array[0], array[n]);
        heapify_subtree(array, 0,  n);
    }
}

// --------------------------------------------------------------

void insertion_sort(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        int temp = array[i];
        int n;
        for(n = i; n > 0 && temp < array[n - 1]; --n) {
            array[n] = array[n - 1];
        }
        array[n] = temp;
    }
}

// --------------------------------------------------------------

//Finds the pivot.
int median(int array[], int low, int high) {
    int center = (high + low) / 2;
    if(array[center] < array[low]) {
        std::swap(array[low], array[center]);
    }
    if(array[high] < array[low]) {
        std::swap(array[low], array[high]);
    }
    if(array[high] < array[center]) {
        std::swap(array[center], array[high]);
    }

    std::swap(array[center], array[high - 1]);
    return array[high - 1];
}

//Splits the array in two halves.
int partition (int array[], int low, int high) {
	int pivot = median(array, low, high);
	int l = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (array[j] <= pivot) {
			++l;
			std::swap(array[l], array[j]);
		}
	}
	std::swap(array[l + 1], array[high]);
	return (l + 1);
}

void quick_sort(int array[], int low, int high) {
	if (low < high) {
		int part = partition(array, low, high);
		quick_sort(array, low, part - 1);
		quick_sort(array, part + 1, high);
	}
}