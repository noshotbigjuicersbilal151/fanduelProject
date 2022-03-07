#pragma once
#include <string>

class Player{
    
    protected:
        int cost;
        double points_scored;
        std::string name;
	std::string  position;
	double value;
	int posVal;
   public:
    Player(){}
    
    
    double getPoints(){
	return this->points_scored; 
    }


	int getCost(){
	return this->cost;
	}


	std::string getName(){
	return this->name;
	}

	std::string getPos(){
	return this->position;
	}

    double calculateValue(){
	value = (points_scored * 1000) / cost;
	return value;
	}

	int getPosVal(){
	return this->posVal;
	}
    
};
