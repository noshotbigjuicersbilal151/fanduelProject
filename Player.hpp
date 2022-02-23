#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <vector>
#include <string>

class Player {
std::string name;
std:string position;
std:string team;
int stats[5];
public:
Player( std::vector<std::vector<std::string> > playerData, int row ) {
   name = playerData[row][0];
   position = playerData[row][1];
   team = playerData[row][2];
   stats[0] = playerData[row][3];
   stats[1] = playerData[row][4];
   stats[2] = playerData[row][5];
   stats[3] = playerData[row][6];
   stats[4] = playerData[row][7];

}
};
