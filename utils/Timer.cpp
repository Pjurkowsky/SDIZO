#include "Timer.h"

double Timer::getElapsedTime(std::function<void()> fun)
{

    auto start = std::chrono::high_resolution_clock::now();
    fun();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return elapsed.count();
}

