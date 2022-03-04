#include "Player.h"

class Player{
    
    private:
        int cost;
        double points_scored;
    protected:
        String name, position;
        
    Player(int cost, double pts){
        this->cost = cost;
        this->points_scored = pts;
    }
    
    void setCost(int cost){
        this->cost = cost;
    }
    
    void setPoints(double numPoints){
        this->points_scored = numPoints;
    }
    
    int getCost(){
        return this->cost;
    }
    
    double getPoints(){
        return this->points_scored;
    }
    
    
    double calculateValue(){
         return  this->points_scored / this->cost;
    }
    
    
}

