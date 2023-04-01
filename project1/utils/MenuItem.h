#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include "Structure.h"
#include <vector>
struct MenuItem2
{
    std::string str;
};
struct MenuItem
{
    std::string str;
    Structure *structure;
    std::vector<MenuItem2> menuItems;
};

#endif