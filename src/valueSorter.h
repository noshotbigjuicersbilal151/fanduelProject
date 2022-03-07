#ifndef __VALUE_SORTER_H__
#define __VALUE_SORTER_H__

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

void valueSorter(vector<Player> &sorted) {
    for(int i = 0; i < sorted.size(); i++){
        for(int k = 0; k < sorted.size(); k++){
            if(i != k){
                if(sorted[k].calculateValue() < sorted[i].calculateValue()){
                    swap(sorted[i], sorted[k]);
                }
            }
        }
    }
}

#endif //__VALUE_SORTER_H__
