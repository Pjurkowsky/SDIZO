#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <climits>
#include <functional>

#include "MenuItem.h"
#include "Timer.h"
#include "../lists/Array.h"
#include "../trees/Tree.h"

#include "../trees/Heap.h"
#include "../lists/DoubleLinkedList.h"
#include "../trees/BinarySearchTree.h"

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
    void testMode(L l, T t, bool arg);
};

template <class L, class T>
void Menu::testMode(L l, T t, bool arg)
{
    int x[4], y;
    Timer timer;
    std::cout << "Write 4 data structure sizes: ";
    for (int i = 0; i < 4; i++)
        x[i] = getIntInput("");
    y = getIntInput("How many times test all 4 sizes: ");

    double structure_time_sums[5] = {};



    std::ofstream file_array("outputFiles/array.txt");
    std::ofstream file_dll("outputFiles/dll.txt");
    std::ofstream file_heap("outputFiles/heap.txt");
    std::ofstream file_bart("outputFiles/bart.txt");

    if (!file_array)
    {
        std::cout << "Unable to create essa file\n";
        waitForUser();
        return;
    }

    for (int n = 0; n < 4; n++)
    {
        for (int i = 0; i < y; i++)
        {
            double *arr = generateArray(x[n]);
            Array *array = new Array();
            DoubleLinkedList *dll = new DoubleLinkedList();
            Heap *heap = new Heap();
            // BinarySearchTree *bst = new BinarySearchTree();

            for (int j = 0; j < x[n]; j++)
            {
                auto fa = std::bind(l, array, arr[j]);
                auto fd = std::bind(l, dll, arr[j]);
                auto fh = std::bind(t, heap, arr[j]);
                //    auto fb = std::bind(t, bst, arr[j]);
                file_array << timer.getElapsedTime(fa) << " ";
                file_dll << timer.getElapsedTime(fd) << " ";
                file_heap << timer.getElapsedTime(fh) << " ";
            }

            delete[] arr;
            delete array;
            delete dll;
            delete heap;

            file_array << '\n';
            file_dll << '\n';
            file_heap << '\n';
        }
        file_array.close();
        file_dll.close();
        file_heap.close();
        file_bart.close();
    }

    transposeFile("outputFiles/array.txt", "outputFiles/array1.txt");
    transposeFile("outputFiles/dll.txt", "outputFiles/dll1.txt");
    transposeFile("outputFiles/heap.txt", "outputFiles/heap1.txt");
    //  transposeFile("outputFiles/bst.txt", "outputFiles/bst1.txt");
    waitForUser();
}
#endif
