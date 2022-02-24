#ifndef __SMALL_FORWARD_HPP__
#define __SMALL_FORWARD_HPP__

include "Player.h"

class SmallForward : public Player {
    string position;
public:
    SmallForward(int cost1, int pts1, int ats1, int reb1, int blk1, int stl1, int to1, string name1) : Player(cost1, pts1, ats1, reb1, blk1, stl1, to1, name1) {
        position = "Small Forward";
    }
    void setPosition(std::string pos) override {position = pos;}
    string getPosition() override {return position;}
};

#endif //__SMALL_FORWARD_HPP__
