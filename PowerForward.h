#ifndef __POWERFORWARD_HPP__
#define __POWERFORWARD_HPP__

#include "Player.h"
#include <string>

class PowerForward : public Player {
public:
	PowerForward(){}
    PowerForward(std::string n, int c, double pts ){
        name = n;
        cost = c;
        points_scored = pts;
        position = "PF";
    }
    
};

#endif //__POWERFORWARD_HPP__

