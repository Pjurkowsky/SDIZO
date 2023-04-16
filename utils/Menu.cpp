#include "Menu.h"

Menu::Menu(std::vector<MenuItem> menuItems) : menuItems(menuItems), innerLoop(false)
{
}
// runs menu
void Menu::run()
{
    while (true)
    {
        int i = 1;
        system("clear");
        for (auto item : menuItems)
            std::cout << i++ << ": " << item.str << "\n";
        std::cin >> i;
        if (i == 6)
            exit(0);
        innerLoop = true;
        while (innerLoop)
        {
            system("clear");
            int j = 1;
            for (auto item : menuItems[i - 1].menuItems)
                std::cout << j++ << ": " << item.str << "\n";
            std::cin >> j;

            if (i == 1 || i == 2)
                listFunctions(i - 1, j);
            else if (i == 3 || i == 4)
                treeFunctions(i - 1, j);
            else if (i == 5)
                testModeFunctions(j);
        }
    }
}
// waits for user to press enter
void Menu::waitForUser()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Press any key to continue . . .\n";
    std::cin.get();
}
// displays list functions and calls them
void Menu::listFunctions(int i, int j)
{
    int x, y;
    std::string str;
    List *list = ((List *)(menuItems[i].structure));
    switch (j)
    {
    case 1:
        system("clear");
        std::cout << list->toString();
        waitForUser();
        break;
    case 2:
        list->addFront(getIntInput("Write a number to add to front: "));
        break;
    case 3:
        list->addBack(getIntInput("Write a number to add to back: "));
        break;
    case 4:
        list->addAtIndex(getIntInput("Write an index to add the number to: "),
                         getIntInput("Write a number to add: "));
        break;
    case 5:
        list->removeFromFront();
        break;
    case 6:
        list->removeFromBack();
        break;
    case 7:
        list->remove(getIntInput("Write a index to remove: "));
        break;
    case 8:
        str = list->find(getIntInput("Write a number to search for: ")) ? "Found" : "Not Found";
        std::cout << str << "\n";
        waitForUser();
        break;
    case 9:
    {
        std::ifstream file(getStringInput("Write a filename to read from: "));
        while (file >> x)
            list->addFront(x);
        file.close();
    }
    break;
    case 10:
    {
        std::ofstream file(getStringInput("Write a filename to write to: "));
        file << list->toString();
        file.close();
    }
    break;
    case 11:
        innerLoop = false;
        break;
    }
}
// displays tree functions and calls them
void Menu::treeFunctions(int i, int j)
{
    int x, y;
    std::string str;
    Tree *tree = ((Tree *)(menuItems[i].structure));
    switch (j)
    {
    case 1:
        system("clear");
        std::cout << menuItems[i].structure->toString() << '\n';
        waitForUser();
        break;
    case 2:
        system("clear");
        tree->display();
        waitForUser();
        break;
    case 3:
    {
        auto start = std::chrono::high_resolution_clock::now();

        tree->push(getIntInput("Write a number to add: "));

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double essa = elapsed.count();
        std::cout << essa;
        waitForUser();
        system("clear");
    }
    break;
    case 4:
        tree->pop(getIntInput("Write a number to delete: "));
        break;
    case 5:
        if (tree->find(getIntInput("Write a number to search for: ")) != nullptr)
            std::cout << "Found\n";
        else
            std::cout << "Not Found\n";
        waitForUser();
        break;
    case 6:
    {
        std::ifstream file(getStringInput("Write a filename to read from: "));
        while (file >> x)
            tree->push(x);
        file.close();
    }
    break;
    case 7:
    {
        std::ofstream file(getStringInput("Write a filename to write to: "));
        file << tree->toString();
        file.close();
    }
    break;
    case 8:
        innerLoop = false;
        break;
    }
}
// displays test mode functions and calls them
void Menu::testModeFunctions(int j)
{
    int x, y;
    std::string str;
    switch (j)
    {
    case 1:
        x = getIntInput("how much data to generate: ");
        system("clear");
        str = getStringInput("Write a filename to write to: ");
        {
            RandomGenerator gen;
            gen.generateFile(str, x);
        }

        break;
    case 2:
    {
        typedef void (List::*ListPush)(int x);
        typedef void (Tree::*TreePush)(int x);

        ListPush listPush = &List::addFront;
        TreePush treePush = &Tree::push;
        testMode(listPush, treePush, "push");
        break;
    }

    case 3:
    {
        typedef void (List::*ListPop)(int x);
        typedef void (Tree::*TreePop)(int x);

        ListPop listPop = &List::remove;
        TreePop treePop = &Tree::pop;

        testMode(listPop, treePop, "pop");
        break;
    }
    case 4:
    {
        typedef bool (List::*ListFind)(int x);
        typedef Tree::Node *(Tree::*TreeFind)(int x);

        ListFind listFind = &List::find;
        TreeFind treeFind = &Tree::find;

        testMode(listFind, treeFind, "find");
        break;
    }
    case 5:
        testLists();
        break;
    case 6:
        innerLoop = false;
        break;
    }
}
// gets int input from user
int Menu::getIntInput(std::string message)
{
    int x;
    std::cout << message;
    std::cin >> x;
    return x;
}
// gets string input from user
std::string Menu::getStringInput(std::string message)
{
    std::string x;
    std::cout << message;
    std::cin >> x;
    return x;
}
// tests list functions
void Menu::testLists()
{
    int z, y;

    z = getIntInput("How many different sizes do you want to test:");
    int *x = new int[z];

    std::cout << "Write " << z << " data structure sizes: ";
    for (int i = 0; i < z; i++)
        x[i] = getIntInput("");
    std::cout << "How many times test all " << z << " sizes: ";
    y = getIntInput("");
    std::cout << "Testing removeFromFront \n";
    testLists("removeFront", z, y, x);
    std::cout << "Testing removeFromBack \n";
    testLists("removeBack", z, y, x);
    std::cout << "Testing addBack \n";
    testLists("addBack", z, y, x);
    std::cout << "Testing addAtIndex \n";
    testLists("addAtIndex", z, y, x);
    delete x;
    waitForUser();
}
// tests list functions
void Menu::testLists(std::string type, int z, int y, int *x)
{
    Timer timer;
    double **structure_time_sums = new double *[2]();
    for (int i = 0; i < 2; i++)
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
            if (type == "removeFront" || type == "removeBack" || type == "addAtIndex")
            {
                for (int j = 0; j < x[n]; j++)
                {
                    array->addFront(arr[j]);
                    dll->addFront(arr[j]);
                }
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(arr, arr + x[n], std::default_random_engine(seed));
            }

            for (int j = 0; j < x[n]; j++)
            {
                if (type == "removeFront")
                {
                    timer.start();
                    array->removeFromFront();
                    timer.stop();
                    structure_time_sums[0][n] += timer.getElapsedTime();
                    timer.start();
                    dll->removeFromFront();
                    timer.stop();
                    structure_time_sums[1][n] += timer.getElapsedTime();
                }
                if (type == "removeBack")
                {
                    timer.start();
                    array->removeFromBack();
                    timer.stop();
                    structure_time_sums[0][n] += timer.getElapsedTime();
                    timer.start();
                    dll->removeFromBack();
                    timer.stop();
                    structure_time_sums[1][n] += timer.getElapsedTime();
                }
                if (type == "addBack")
                {
                    timer.start();
                    array->addBack(arr[j]);
                    timer.stop();
                    structure_time_sums[0][n] += timer.getElapsedTime();
                    timer.start();
                    dll->addBack(arr[j]);
                    timer.stop();
                    structure_time_sums[1][n] += timer.getElapsedTime();
                }
                if (type == "addAtIndex" && j == x[n] - 1)
                {
                    timer.start();
                    array->addAtIndex(j, arr[j]);
                    timer.stop();
                    structure_time_sums[0][n] += timer.getElapsedTime();
                    timer.start();
                    dll->addAtIndex(j, arr[j]);
                    timer.stop();
                    structure_time_sums[1][n] += timer.getElapsedTime();
                }
            }
            delete array;
            delete dll;
            delete[] arr;
        }
        std::cout << "Finished " << x[n] << " elements" << '\n';
    }

    file_array << "liczba_danych tablica_dynamiczna double_linked_list\n";
    for (int i = 0; i < z; i++)
    {
        file_array << x[i] << " ";
        for (int j = 0; j < 2; j++)
        {
            if (type == "addAtIndex")
                structure_time_sums[j][i] /= y;
            else
                structure_time_sums[j][i] /= y * x[i];
            file_array << structure_time_sums[j][i] << " ";
        }
        file_array << '\n';
    }

    for (int i = 0; i < 2; i++)
        delete[] structure_time_sums[i];

    delete[] structure_time_sums;
    file_array.close();
}
