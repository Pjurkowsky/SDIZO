#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>

#include <functional>

class Timer
{
public:
    double getElapsedTime(std::function<void()> fun); // returns elapsed time of function
    void start();                                     // starts timer
    void stop();                                      // stops timer
    double getElapsedTime();                          // returns elapsed time

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
};
#endif