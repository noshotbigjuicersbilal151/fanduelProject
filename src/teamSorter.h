#ifndef __TEAM_SORTER_H__
#define __TEAM_SORTER_H__

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "PointGuard.h"
#include "ShootingGuard.h"
#include "SmallForward.h"
#include "PowerForward.h"
#include "center.h"

using namespace std;

void teamSorter(vector<Player> &team) {
for(int i =0; i < team.size(); i++){
for(int k = 0; k < team.size(); k++){
if(i != k){
if(team[i].getPosVal() < team[k].getPosVal()){
swap(team[i], team[k]);
}
}
}
}
}

#endif //__TEAM_SORTER_H__
