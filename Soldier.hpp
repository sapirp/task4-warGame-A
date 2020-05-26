
#ifndef _soldier_H
#define _soldier_H

#include <iostream>

class Soldier
{
protected:
    int player, lifePoints;

public:
    Soldier(int p) : player(p)
    {
        std::cout << "Soldier const" << std::endl;
    }
};

#endif