#pragma once

#include "Player.h"
#include <string>

class Center : public Player {
public:
	Center(){}
    Center(std::string n, int c, double pts, std::string t ){
        name = n;
        cost = c;
        points_scored = pts;
	teamVsTeam = t;
        position = "C";
	posVal = 5;
    }
    
};



