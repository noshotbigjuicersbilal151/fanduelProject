#ifndef __POWERFORWARD_HPP__
#define __POWERFORWARD_HPP__

#include "Player.h"
#include <string>

class PowerForward : public Player {
public:
    PowerForward(std::string name, int cost, double pts ){
        this->name = name;
        this->cost = cost;
        this->points_scored = pts;
        this->position = "PF";
    }
    
};

#endif //__POWERFORWARD_HPP__

