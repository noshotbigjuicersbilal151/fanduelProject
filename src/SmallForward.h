#ifndef __SMALLFORWARD_HPP__
#define __SMALLFORWARD_HPP__

#include "Player.h"
#include <string>

class SmallForward : public Player {
public:
	SmallForward(){}
    SmallForward(std::string n, int c, double pts, std::string t){
        name = n;
        cost = c;
        points_scored = pts;
	teamVsTeam = t;
        position = "SF";
	posVal = 4;
    }
    
};

#endif //__SMALLFORWARD_HPP__

