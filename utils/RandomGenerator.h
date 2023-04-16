#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
class RandomGenerator
{
public:
    RandomGenerator();
    int generateRandomInteger();
    int *generateArrayOfIntegers(size_t size);
    void generateFile(std::string filename, int numbers);

private:
    unsigned seed;
    std::random_device rd;
    std::seed_seq sd;
    std::mt19937 rng;
};

#endif