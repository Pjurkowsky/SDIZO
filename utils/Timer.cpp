#include "Timer.h"
// returns elapsed time of function
double Timer::getElapsedTime(std::function<void()> fun)
{
    auto start = std::chrono::high_resolution_clock::now();
    fun();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return elapsed.count();
}
// stops timer
void Timer::stop()
{
    end_time = std::chrono::high_resolution_clock::now();
}
// returns elapsed time
double Timer::getElapsedTime()
{
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    return elapsed.count();
}
// starts timer
void Timer::start()
{
    start_time = std::chrono::high_resolution_clock::now();
}
