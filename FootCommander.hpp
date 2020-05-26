
#ifndef _footCommender_H
#define _footCommender_H

#include "FootSoldier.hpp"

class FootCommander : public FootSoldier
{

public:
    //constructor
    FootCommander(int p) : FootSoldier(p)
    {
        std::cout << "FootCommander const" << std::endl;
    }
};

#endif