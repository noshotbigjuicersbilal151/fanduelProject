#ifndef __SHOOTINGGUARD_HPP__
#define __SHOOTINGGUARD_HPP__

#include "Player.h"
#include <string>

class ShootingGuard : public Player {
public:
    ShootingGuard(std::string name, int cost, double pts ){
        this->name = name;
        this->cost = cost;
        this->points_scored = pts;
        this->position = "SG";
    }
    
};

#endif //__SHOOTINGGUARD_HPP__

