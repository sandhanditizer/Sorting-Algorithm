/*
Zachariah Kline
18 NOV 2021
Functions that populate an array in different ways.
*/

#pragma once


//Generates a random number between [min, max] (inclusive range).
int random_num(int min, int max);

//Populates an array with random integers.
void populate_randomly(int array[], int size);

//Populates an array with integers in reversed order largest to smallest.
void populate_reverse(int array[], int size);

//Populates and array with partially sorted integers smallest to largest.
void populate_part(int array[], int size);

//Populates an array with integers smallest to largest.
void populate(int array[], int size);