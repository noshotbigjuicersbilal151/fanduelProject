#ifndef __CENTER_HPP__
#define __CENTER_HPP__

#include "Player.h"
#include <string>

class PointGuard : public Player {
public:
    PointGuard(std::string name, int cost, double pts ) {
        this->name = name;
        this->cost = cost;
        this->pts = pts;
        this->position = "PG";
    }
    
};

#endif //__POINTGUARD_HPP__

