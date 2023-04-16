#include <iostream>
#include "lists/DoubleLinkedList.h"
#include "lists/Array.h"
#include "trees/Heap.h"
#include "utils/Menu.h"
#include "utils/Timer.h"
#include "trees/RedAndBlackTree.h"
#include <vector>
#include "utils/RandomGenerator.h"

int main()
{
  Array *array = new Array();
  DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();
  Heap *heap = new Heap();
  RedAndBlackTree *rab = new RedAndBlackTree();

  std::vector<MenuItem2> listItems = {{"display"},
                                      {"addFront"},
                                      {"addBack"},
                                      {"addAtIndex"},
                                      {"removeFromFront"},
                                      {"removeFromBack"},
                                      {"removeFromIndex"},
                                      {"find"},
                                      {"readFromFile"},
                                      {"writeToFile"},
                                      {"exit"}};

  std::vector<MenuItem2> treeItems = {{"display"},
                                      {"pretty display"},
                                      {"push"},
                                      {"pop"},
                                      {"find"},
                                      {"readFromFile"},
                                      {"writeToFile"},
                                      {"exit"}};

  std::vector<MenuItem2> testModeItems = {{"generate file with x random data"},
                                          {"test PUSH operation on every data structure x times"},
                                          {"test POP operation on every data structure x times"},
                                          {"test FIND operation on every data structure x times"},
                                          {"test list only methods x times"},
                                          {"exit"}};

  std::vector<MenuItem> menuItems = {{"Array", array, {listItems}},
                                     {"Double Linked List", doubleLinkedList, {listItems}},
                                     {"Heap", heap, {treeItems}},
                                     {"Red and Black Tree", rab, {treeItems}},
                                     {"Test mode", nullptr, {testModeItems}},
                                     {"exit", nullptr, {}}};

  Menu menu(menuItems);
  menu.run();
  return 0;
}
