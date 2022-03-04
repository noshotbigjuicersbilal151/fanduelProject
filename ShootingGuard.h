#ifndef __SHOOTINGGUARD_HPP__
#define __SHOOTINGGUARD_HPP__

#include "Player.h"
#include <string>

class ShootingGuard : public Player {
public:
    Center(std::string name, int cost, double pts ) {
        this->name = name;
        this->cost = cost;
        this->pts = pts;
        this->position = "SG";
    }
    
};

#endif //__SHOOTINGGUARD_HPP__

