#ifndef __CENTER_HPP__
#define __CENTER_HPP__

#include "Player.h"
#include <string>

class PointGuard : public Player {
public:
	PointGuard(){}
    PointGuard(std::string n, int c, double pts, std::string t){
        name = n;
        cost = c;
        points_scored = pts;
	teamVsTeam = t;
        position = "PG";
	posVal = 1;
    }


};

#endif //__POINTGUARD_HPP__

