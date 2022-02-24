#ifndef __TEAM_HPP__
#define __TEAM_HPP__

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

class Team {
vector<Player*> teamPlayers;
std::string teamName;
public:
Team (std::string name) {
teamName = name;
}
void addPlayer(Player* player) {
teamPlayers.push_back(player);
}

void removePlayer(std::string playerName) {
for (int i = 0; i < playerName.size(); i++){
  if (teamPlayers[i]->name = playerName;) teamPlayers.erase(teamPlayer.begin()+i);
}
}
vector getVector () {
  return teamPlayers;
}
bool team_check(teamPlayers); 
bool team_count(teamPlayers); 

};

#endif __TEAM_HPP__
