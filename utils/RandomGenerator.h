#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
class RandomGenerator
{
public:
    RandomGenerator();                                    // constructor
    int generateRandomInteger();                          // generates random integer
    int *generateArrayOfIntegers(size_t size);            // generates array of random integers
    void generateFile(std::string filename, int numbers); // generates file with random integers

private:
    unsigned seed;
    std::random_device rd;
    std::seed_seq sd;
    std::mt19937 rng;
};

#endif