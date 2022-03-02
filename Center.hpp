#ifndef __CENTER_HPP__
#define __CENTER_HPP__

#include "Player.h"
#include <string>

class Center : public Player {
    std::string position;
public:
    Center(int icost, int ipts, int iats, int ireb, int iblk, int istl, int ito, std::string iname) {
        cost = icost;
        numPoints = ipts;
        numAssists = iats;
        numReb = ireb;
        numBlock = iblk;
        numSteal = istl;
        name = std::move(iname);
        position = "Center";
    }
    void setPosition(std::string pos) override {
        position = pos;
    }
    std::string getPosition() override {
        return position;
    }
};

#endif //__CENTER_HPP__
