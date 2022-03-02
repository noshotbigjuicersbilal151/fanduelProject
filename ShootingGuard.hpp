#ifndef __SHOOTING_GUARD_HPP__
#define __SHOOTING_GUARD_HPP__

#include "Player.h"
#include <string>

class ShootingGuard : public Player {
    std::string position;
public:
    ShootingGuard(int icost, int ipts, int iats, int ireb, int iblk, int istl, int ito, std::string iname) {
        cost = icost;
        numPoints = ipts;
        numAssists = iats;
        numReb = ireb;
        numBlock = iblk;
        numSteal = istl;
        name = std::move(iname);
        position = "Shooting Guard";
    }
    void setPosition(std::string pos) override {
        position = pos;
    }
    std::string getPosition() override {
        return position;
    }
};

#endif //__SHOOTING_GUARD_HPP__
