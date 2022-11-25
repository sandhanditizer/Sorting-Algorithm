/*
Zachariah Kline
30 NOV 2021
Runtime calculator.
*/

#include "timer.h"
#include <chrono>


Timer::Timer() {}

void Timer::start() {
    t1 = std::chrono::high_resolution_clock::now();
}

std::string Timer::stop() {
    t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = t2 - t1;
    double count = elapsed.count();
    std::string msg = "\nRuntime: ";
    msg += std::to_string(count);
    msg += " seconds\n\n";
    return msg;
}