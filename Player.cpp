#include "Player.h"

class Player{
    
    private:
        int cost;
        int numPoints, numAssists, numReb, numBlock, numSteal, numTO;
    protected:
        String name, position;
        
    Player(int cost, int pts, ints ats, int reb, int blk, int stl, int to, String name, String pos){
        this->cost = cost;
        this->numPoints = pts;
        this->numAssists = ats;
        this->numReb = reb;
        this->numBlock = blk;
        this->numSteal = stl;
        this->name = name;
        this->position = pos;
    }
    
    void setCost(int cost){
        this->cost = cost;
    }
    
    void setPoints(int numPoints){
        this->numPoints = numPoints;
    }
    
    void setAssists(int numAssists){
        this->numAssists = numAssists;
    }
    
    void setReb(int numReb){
        this->numReb = numReb;
    }
    
    void setBlocks(int numBlock){
        this->numBlock = numBlock;
    }
    
    void setSteals(int numSteals){
        this->numSteal= = numSteals;
    }
    
    void setTO(int numTO){
        this->numTO = numTO;
    }
    
    void setName(String name){
        this->name = name;
    }
    
    void setPosition(String pos){
        this->position = pos;
    }
    
    int getCost(){
        return this->cost;
    }
    
    int getPts(){
        return this->numPoints;
    }
    
    int getAssists(){
        return this->numAssists;
    }
    
    int getReb(){
        return this->numReb;
    }
    
    int getBlock(){
        return this->numBlock;
    }
    
    int getSteal(){
        return this->numSteals;
    }
    
    int getTO(){
        return this->numTO;
    }
    
    String getName(){
        return this->name;
    }
    
    String getPosition(){
        return this->position;
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

