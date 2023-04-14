#include "Menu.h"

Menu::Menu(std::vector<MenuItem> menuItems) : menuItems(menuItems), innerLoop(false)
{
}

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
            else if (i == 3 || i == 4 || i == 5)
                treeFunctions(i - 1, j);
            else if (i == 6)
                testModeFunctions(j);
        }
    }
}

void Menu::waitForUser()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Press any key to continue . . .\n";
    std::cin.get();
}

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
        tree->find(getIntInput("Write a number to search for: "));
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
        generateFile(str, x);
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
        innerLoop = false;
        break;
    }
}
int Menu::getIntInput(std::string message)
{
    int x;
    std::cout << message;
    std::cin >> x;
    return x;
}
std::string Menu::getStringInput(std::string message)
{
    std::string x;
    std::cout << message;
    std::cin >> x;
    return x;
}
void Menu::printProgress(double percentage)
{
    int val = (int)(percentage * 100);
    int lpad = (int)(percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

void Menu::generateFile(std::string filename, int numbers)
{
    uint32_t seed_val = time(NULL);
    std::random_device rd;
    std::seed_seq sd{rd(), rd(), rd(), rd()};
    std::mt19937 rng(sd);
    std::uniform_int_distribution<int> uint_dist(-2147483648, 2147483647);

    std::ofstream file(filename);
    for (int i = 0; i < numbers; i++)
        file << uint_dist(rng) << " ";

    file.close();
}

void Menu::transposeFile(std::string inputFileName, std::string outputFileName)
{
    std::ifstream infile(inputFileName);

    std::vector<std::vector<double>> matrix;
    std::string line;
    std::vector<double> average;

    while (std::getline(infile, line))
    {
        std::vector<double> row;
        std::string token;
        std::istringstream iss(line);

        while (std::getline(iss, token, ' '))
        {
            double num = std::stod(token);
            row.push_back(num);
        }

        matrix.push_back(row);
    }
    infile.close();
    std::ofstream outfile(outputFileName);
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    std::vector<std::vector<double>> transposedMatrix(nCols, std::vector<double>(nRows));
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            transposedMatrix[j][i] = matrix[i][j];

    for (int i = 0; i < nCols; i++)
    {
        double num1 = 0.0;
        for (int j = 0; j < nRows; j++)
            num1 += transposedMatrix[i][j];
        average.push_back(num1 / nRows);
    }

    for (auto &num : average)
        outfile << num << '\n';

    outfile.close();
}

double *Menu::generateArray(int numbers)
{
    uint32_t seed_val = time(NULL);
    std::random_device rd;
    std::seed_seq sd{rd(), rd(), rd(), rd()};
    std::mt19937 rng(sd);
    std::uniform_int_distribution<int> uint_dist(-2147483648, 2147483647);
    double *x = new double[numbers];
    for (int i = 0; i < numbers; i++)
    {
        int y = uint_dist(rng);
        for (int j = 0; j < i; j++)
            while (x[j] == y)
                y = uint_dist(rng);
        x[i] = y;
    }
    return x;
}
