#ifndef __SHOOTINGGUARD_HPP__
#define __SHOOTINGGUARD_HPP__

#include "Player.h"
#include <string>

class ShootingGuard : public Player {
public:
	ShootingGuard(){}
    ShootingGuard(std::string n, int c, double pts ){
        name = n;
        cost = c;
        points_scored = pts;
        position = "SG";
    }
    
};

#endif //__SHOOTINGGUARD_HPP__

