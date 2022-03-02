#ifndef __SMALL_FORWARD_HPP__
#define __SMALL_FORWARD_HPP__

#include "Player.h"
#include <string>

class SmallForward : public Player {
    std::string position;
public:
    SmallForward(int icost, int ipts, int iats, int ireb, int iblk, int istl, int ito, std::string iname) {
        cost = icost;
        numPoints = ipts;
        numAssists = iats;
        numReb = ireb;
        numBlock = iblk;
        numSteal = istl;
        name = std::move(iname);
        position = "Small Forward";
    }
    void setPosition(std::string pos) override {
        position = pos;
    }
    std::string getPosition() override {
        return position;
    }
};

#endif //__SMALL_FORWARD_HPP__
