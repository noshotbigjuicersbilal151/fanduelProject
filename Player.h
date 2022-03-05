#pragma once
#include <string>

class Player{
    
    protected:
        int cost;
        double points_scored;
        std::string name;
	std::string  position;
   public:
    Player(){}
    
    void setPoints(double points){
	this->points_scored = points;
	}
    
    double getPoints(){
	return this->points_scored; 
    }

	void setCost(int c){
	cost = c;
	}

	int getCost(){
	return this->cost;
	}

	void setName(std::string n){
	name = n;
	}

	std::string getName(){
	return this->name;
	}

	std::string getPos(){
	return this->position;
	}

    double calculateValue(){
	return cost / points_scored;
	}
    
};

