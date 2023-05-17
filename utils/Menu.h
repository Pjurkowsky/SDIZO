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

class Menu
{
public:
    Menu(std::vector<MenuItem> menuItems); // constructor
    void run();                            // runs menu

private:
    void waitForUser();                              // waits for user to press enter
    void listFunctions(int i, int j);                // displays list functions and calls them
    void treeFunctions(int i, int j);                // displays tree functions and calls them
    void testModeFunctions(int j);                   // displays test mode functions and calls them
    int getIntInput(std::string message);            // gets int input from user
    std::string getStringInput(std::string message); // gets string input from user
    std::vector<MenuItem> menuItems;
    bool innerLoop;
    void testLists();                                       // tests list functions
    void testLists(std::string type, int z, int y, int *x); // tests list functions
    template <class L, class T>
    void testMode(L list, T tree, std::string type); // tests push pop find functions
};

// tests push pop find functions
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

    std::ofstream file_array(type + "Test.txt");

    RandomGenerator rg;

    if (!file_array)
    {
        std::cout << "Unable to create file\n";
        waitForUser();
        return;
    }

    for (int n = 0; n < z; n++)
    {
        std::cout << "Testing " << x[n] << " elements" << '\n';
        for (int i = 0; i < y; i++)
        {
            int *arr = rg.generateArrayOfIntegers(x[n]);
            Array *array = new Array();
            DoubleLinkedList *dll = new DoubleLinkedList();
            Heap *heap = new Heap();
            RedAndBlackTree *rabt = new RedAndBlackTree();

            if (type == "find" || type == "pop")
            {
                for (int j = 0; j < x[n]; j++)
                {
                    array->addFront(arr[j]);
                    dll->addFront(arr[j]);
                    heap->push(arr[j]);
                    rabt->push(arr[j]);
                }
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(arr, arr + x[n], std::default_random_engine(seed));
            }

            int tempArray[4];
            int temp = x[n];
            if (type == "find" || type == "pop")
                x[n] = 1;
            for (int j = 0; j < x[n]; j++)
            {
                auto farr = std::bind(list, array, arr[j]);
                auto fdll = std::bind(list, dll, arr[j]);
                auto fheap = std::bind(tree, heap, arr[j]);
                auto frabt = std::bind(tree, rabt, arr[j]);

                tempArray[0] = timer.getElapsedTime(farr);
                tempArray[1] = timer.getElapsedTime(fdll);
                tempArray[2] = timer.getElapsedTime(fheap);
                tempArray[3] = timer.getElapsedTime(frabt);
            }

            structure_time_sums[0][n] += tempArray[0];
            structure_time_sums[1][n] += tempArray[1];
            structure_time_sums[2][n] += tempArray[2];
            structure_time_sums[3][n] += tempArray[3];
            x[n] = temp;
            delete[] arr;
            delete array;
            delete dll;
            delete heap;
            delete rabt;
        }
        std::cout << "Finished " << x[n] << " elements" << '\n';
    }

    file_array << "liczba_danych tablica_dynamiczna double_linked_list kopiec_maksymalny drzewo_czerwono-czarne drzewo_AVL\n";
    for (int i = 0; i < z; i++)
    {
        file_array << x[i] << " ";
        for (int j = 0; j < 5; j++)
        {
            structure_time_sums[j][i] /= y;
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
