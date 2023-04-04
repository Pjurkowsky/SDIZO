#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::random_device rd;
    std::seed_seq sd{rd(), rd(), rd(), rd()};
    std::mt19937 rng(sd);
}

int RandomGenerator::generateRandomInteger()
{
    std::uniform_int_distribution<int> uint_dist(-2147483648, 2147483647);
    return uint_dist(rng);
}

int *RandomGenerator::generateArrayOfIntegers(size_t size)
{

    int *x = new int[size];

    for (int i = 0; i < size; i++)
    {
        int y = generateRandomInteger();
        for (int j = 0; j < i; j++)
            while (x[j] == y)
                y = generateRandomInteger();
        x[i] = y;
    }
    return x;
}
