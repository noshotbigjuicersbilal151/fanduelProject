#include "Player.h"

class Player{
    
    private:
        int cost;
        double points_scored;
    protected:
        std::string name, position;
        
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
    
    double getPts(){
        return this->points_scored;
    }
    
    
    float calculatePoints(){
        float pointsScored = 0.0;
        pointsScored += this->numPoints;
        pointsScored += 1.5 * this->numAssists;
        pointsScored += 1.2 * this->numReb;
        pointsScored += 3 * (this->numBlock + this->numSteal);
        pointsScored -= this->numTO;
        
        return pointsScored;
  }
    
    
}

