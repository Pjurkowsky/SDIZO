#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <climits>
#include <functional>
#include <algorithm>
#include <chrono>

#include "MenuItem.h"
#include "Timer.h"
#include "RandomGenerator.h"

#include "../trees/RedAndBlackTree.h"
#include "../trees/Tree.h"
#include "../trees/Heap.h"

#include "../lists/Array.h"
#include "../lists/DoubleLinkedList.h"

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

class Menu
{
public:
    Menu(std::vector<MenuItem> menuItems);
    void run();

private:
    void waitForUser();
    void listFunctions(int i, int j);
    void treeFunctions(int i, int j);
    void testModeFunctions(int j);
    int getIntInput(std::string message);
    std::string getStringInput(std::string message);
    void printProgress(double precentage);
    void generateFile(std::string filename, int numbers);
    void transposeFile(std::string inputFileName, std::string outputFileName);
    double *generateArray(int numbers);
    std::vector<MenuItem> menuItems;
    bool innerLoop;
    template <class L, class T>
    void testMode(L l, T t, std::string type);
};

template <class L, class T>
void Menu::testMode(L list, T tree, std::string type)
{
    int z, y;
    Timer timer;
    z = getIntInput("How many different sizes do you want to test:");
    int *x = new int[z];

    std::cout << "Write " << z << " data structure sizes: ";
    for (int i = 0; i < z; i++)
        x[i] = getIntInput("");
    std::cout << "How many times test all " << z << " sizes: ";
    y = getIntInput("");

    double **structure_time_sums = new double *[5]();
    for (int i = 0; i < 5; i++)
        structure_time_sums[i] = new double[z]();

    std::ofstream file_array("pushTest.txt");

    RandomGenerator rg;

    if (!file_array)
    {
        std::cout << "Unable to create file\n";
        waitForUser();
        return;
    }

    for (int n = 0; n < z; n++)
    {
        for (int i = 0; i < y; i++)
        {
            int *arr = rg.generateArrayOfIntegers(x[n]);
            Array *array = new Array();
            DoubleLinkedList *dll = new DoubleLinkedList();
            Heap *heap = new Heap();
            RedAndBlackTree *bst = new RedAndBlackTree();

            if (type == "find" || type == "pop")
            {
                for (int j = 0; j < x[n]; j++)
                {
                    array->addFront(arr[j]);
                    dll->addFront(arr[j]);
                    heap->push(arr[j]);
                }
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(arr, arr + x[n], std::default_random_engine(seed));
            }

            for (int j = 0; j < x[n]; j++)
            {
                auto fa = std::bind(list, array, arr[j]);
                auto fd = std::bind(list, dll, arr[j]);
                auto fh = std::bind(tree, heap, arr[j]);
                auto fb = std::bind(tree, bst, arr[j]);

                structure_time_sums[0][n] += timer.getElapsedTime(fa);
                structure_time_sums[1][n] += timer.getElapsedTime(fd);
                structure_time_sums[2][n] += timer.getElapsedTime(fh);
                structure_time_sums[3][n] += timer.getElapsedTime(fb);
            }

            delete[] arr;
            delete array;
            delete dll;
            delete heap;
            delete bst;
        }
    }

    file_array << "liczba_danych tablica_dynamiczna double_linked_list kopiec_maksymalny drzewo_czerwono-czarne drzewo_AVL\n";
    for (int i = 0; i < z; i++)
    {
        file_array << x[i] << " ";
        for (int j = 0; j < 5; j++)
        {
            structure_time_sums[j][i] /= y * x[i];
            file_array << structure_time_sums[j][i] << " ";
        }
        file_array << '\n';
    }

    delete x;
    for (int i = 0; i < 5; i++)
        delete[] structure_time_sums[i];

    delete[] structure_time_sums;
    file_array.close();

    waitForUser();
}
#endif
