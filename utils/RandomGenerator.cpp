#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::random_device rd;
    std::seed_seq sd{rd(), rd(), rd(), rd()};
    std::mt19937 rng(sd);
}
// generates random integer
int RandomGenerator::generateRandomInteger()
{
    std::uniform_int_distribution<int> uint_dist(-2147483648, 2147483647);
    return uint_dist(rng);
}
// generates array of random integers
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
// generates file with random integers
void RandomGenerator::generateFile(std::string filename, int numbers)
{

    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Unable to create file\n";
        return;
    }
    int *x = generateArrayOfIntegers(numbers);

    for (int i = 0; i < numbers; i++)
        file << x[i] << '\n';

    delete[] x;
    file.close();
}
