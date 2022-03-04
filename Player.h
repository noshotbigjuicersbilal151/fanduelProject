#include "Team.h"
#include <string>

class Player{
    
    private:
        int cost;
        double points_scored;
    protected:
        std::string name, position;
        
    Player(int cost, int pts){
        this->cost = cost;
        this->points_scored = pts;
    }
    
    void setCost(int cost){}
    
    void setPoints(double points){}   
    
}

