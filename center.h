#ifndef __CENTER_HPP__
#define __CENTER_HPP__

#include "Player.h"
#include <string>

class Center : public Player {
public:
    Center(std::string name, int cost, double pts ){
        this->name = name;
        this->cost = cost;
        this->points_scored = pts;
        this->position = "C";
    }
    
};

#endif //__CENTER_HPP__

