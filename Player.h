#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

class Player{

protected:
    int cost;
    int numPoints, numAssists, numReb, numBlock, numSteal, numTO;
    std::string name;
public:
    Player(){}

    ~Player(){}

    void setCost(int cost);

    void setPoints(int numPoints);

    void setAssists(int numAssists);

    void setReb(int numReb);

    void setBlocks(int numBlock);

    void setSteals(int numSteals);

    void setTO(int numTO);

    void setName(std::string name);

    virtual void setPosition(std::string pos) = 0;

    int getCost();

    int getPts();

    int getAssists();

    int getReb();

    int getBlock();

    int getTO();

    std::string getName();

    virtual std::string getPosition() = 0;

    float calculatePoints();
};

#endif //__PLAYER_H__
