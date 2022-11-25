/*
Zachariah Kline
30 NOV 2021
Runtime calculator.
*/

#pragma once
#include <iostream>

//Class to measure runtime of an application.
class Timer {
public:
    Timer();

    //Begin stopclock.
    void start();

    //End stopclock and returns runtime speed in seconds.
    std::string stop();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> t1, t2;
};