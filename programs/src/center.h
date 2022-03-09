#pragma once

#include "Player.h"
#include <string>

class Center : public Player
{
	public:
		Center(){}
    		Center(std::string n, int c, double pts )
		{
        		name = n;
        		cost = c;
        		points_scored = pts;
        		position = "C";
			posVal = 5;
    		}
};



