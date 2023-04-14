cmake_minimum_required(VERSION 3.0.0)
project(project1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(program main.cpp lists/DoubleLinkedList.cpp lists/Array.cpp trees/Heap.cpp trees/RedAndBlackTree.cpp utils/Menu.cpp utils/Timer.cpp utils/RandomGenerator.cpp trees/AVLTree.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
