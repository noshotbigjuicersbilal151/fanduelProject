#ifndef __POWER_FORWARD_HPP__
#define __POWER_FORWARD_HPP__

#include "Player.h"
#include <string>

class PowerForward : public Player {
    std::string position;
public:
    PowerForward(int icost, int ipts, int iats, int ireb, int iblk, int istl, int ito, std::string iname) {
        cost = icost;
        numPoints = ipts;
        numAssists = iats;
        numReb = ireb;
        numBlock = iblk;
        numSteal = istl;
        name = std::move(iname);
        position = "Power Forward";
    }
    void setPosition(std::string pos) override {
        position = pos;
    }
    std::string getPosition() override {
        return position;
    }
};

#endif //__POWER_FORWARD_HPP__
