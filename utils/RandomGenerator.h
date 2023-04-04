#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>
#include <chrono>
#include <random>
class RandomGenerator
{
public:
    RandomGenerator();
    int generateRandomInteger();
    int *generateArrayOfIntegers(size_t size);

private:
    unsigned seed;
    std::random_device rd;
    std::seed_seq sd;
    std::mt19937 rng;
};

#endif