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
    
    void setCost(int cost){}
    
    void setPoints(int numPoints){}
    
    void setAssists(int numAssists){}
    
    void setReb(int numReb){}
    
    void setBlocks(int numBlock){}
    
    void setSteals(int numSteals){}
    
    void setTO(int numTO){}
    
    void setName(String name){}
    
    void setPosition(String pos){}
    
    int getCost(){}
    
    int getPts(){}
    
    int getAssists(){}
    
    int getReb(){}
    
    int getBlock(){ }
    
    
    int getTO(){ }
    
    String getName(){}
    
    String getPosition(){}
    
    float calculatePoints(){  }
    
    
}

