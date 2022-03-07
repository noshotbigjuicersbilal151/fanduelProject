#ifndef __BEST_LINE_UP_ALGORITHM_H__
#define __BEST_LINE_UP_ALGORITHM_H__

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

vector<Player> bestLineUpAlgorithm(vector<Player> sorted){
    vector<Player> bestLineup;
    int pg_count = 0;
    int sg_count = 0;
    int pf_count = 0;
    int sf_count = 0;
    int c_count = 0;

    int pg_index = 0;
    int sg_index = 2;
    int pf_index = 4;
    int sf_index = 6;
    int c_index = 8;

    int salaryCap = 60000;
/*figuring out best lineup first based on value*/
    for(int i = 0; i < sorted.size(); i++){


        if(salaryCap - sorted[i].getCost() >= 0){

            if(sorted[i].getPos() == "C" && c_count != 1){

                bestLineup.push_back(sorted[i]);
                c_count++;
                salaryCap -= sorted[i].getCost();
                sorted.erase(sorted.begin() + i);
                i -= 1;

            }else if(sorted[i].getPos() == "SF" && sf_count != 2){
                bestLineup.push_back(sorted[i]);
                sf_count++;
                salaryCap -= sorted[i].getCost();
                sorted.erase(sorted.begin() + i);
                i -= 1;
            }else if(sorted[i].getPos() == "PF" && pf_count != 2){
                bestLineup.push_back(sorted[i]);
                pf_count++;
                salaryCap -= sorted[i].getCost();
                sorted.erase(sorted.begin() + i);
                i -=1;
            }else if(sorted[i].getPos() == "SG" && sg_count != 2){
                bestLineup.push_back(sorted[i]);
                sg_count++;
                salaryCap -= sorted[i].getCost();
                sorted.erase(sorted.begin() + i);
                i -= 1;
            }else if(sorted[i].getPos() == "PG" && pg_count != 2){
                bestLineup.push_back(sorted[i]);
                pg_count++;
                salaryCap -= sorted[i].getCost();
                sorted.erase(sorted.begin() + i);
                i -= 1;
            }

        }

    }
/*sorting by Points scored*/
    for(int i = 0; i < sorted.size(); i++){
        for(int k = 0; k < sorted.size(); k++){
            if(i != k){
                if(sorted[k].getPoints() < sorted[i].getPoints()){
                    swap(sorted[i], sorted[k]);
                }
            }
        }
    }
/*using leftover salaryCap to get players that were less valueable but scored more overall points*/
    for(int i =0; i < sorted.size(); i++){
        Player temp = sorted[i];

        for(int k = 0; k < bestLineup.size(); k++){

            if(temp.getPoints() > bestLineup[k].getPoints() && (salaryCap - (temp.getCost() - bestLineup[k].getCost()) >= 0) && temp.getPosVal() == bestLineup[k].getPosVal()){
                int salDiff = temp.getCost() - bestLineup[k].getCost();
                bestLineup[k] = temp;
                salaryCap -= salDiff;
                break;
            }


        }
    }
    return bestLineup;
}

#endif //__BEST_LINE_UP_ALGORITHM_H__
