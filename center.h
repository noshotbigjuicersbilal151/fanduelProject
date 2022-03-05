#ifndef __CENTER_HPP__
#define __CENTER_HPP__

#include "Player.h"
#include <string>

class Center : public Player {
public:
	Center(){}
    Center(std::string n, int c, double pts ){
        name = n;
        cost = c;
        points_scored = pts;
        position = "C";
    }
    
};

#endif //__CENTER_HPP__

