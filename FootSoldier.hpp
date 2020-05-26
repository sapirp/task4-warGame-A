
#ifndef _footSoldier_H
#define _footSoldier_H

#include "Soldier.hpp"

class FootSoldier : public Soldier
{

public:
    //constructor
    FootSoldier(int p) : Soldier(p)
    {
        std::cout << "FootSoldier const" << std::endl;
    }
};

#endif