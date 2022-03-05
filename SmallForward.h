#ifndef __SMALLFORWARD_HPP__
#define __SMALLFORWARD_HPP__

#include "Player.h"
#include <string>

class SmallForward : public Player {
public:
    SmallForward(std::string name, int cost, double pts ){
        this->name = name;
        this->cost = cost;
        this->points_scored = pts;
        this->position = "SF";
    }
    
};

#endif //__SMALLFORWARD_HPP__

