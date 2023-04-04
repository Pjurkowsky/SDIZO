#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <functional>
class Timer
{
public:
    double getElapsedTime(std::function<void()> fun);
private:
};
#endif