#ifndef __SHOOTINGGUARD_HPP__
#define __SHOOTINGGUARD_HPP__

#include "Player.h"
#include <string>

class ShootingGuard : public Player {
public:
	ShootingGuard(){}
    ShootingGuard(std::string n, int c, double pts, std::string t){
        name = n;
        cost = c;
        points_scored = pts;
	teamVsTeam = t;
        position = "SG";
	posVal = 2;
    }
    
};

#endif //__SHOOTINGGUARD_HPP__

