#ifndef __PLAYER_SORTER_H__
#define __PLAYER_SORTER_H__

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

vector<Player> playerSorter(vector<vector<string>> content) {
    vector<Player> sorted;
    int numPg = 0;
    int numSg = 0;
    int numPf = 0;
    int numSf = 0;
    int numC = 0;
    for(int i=1;i<content.size();i++)
    {

        std::string t = content[i][0];

        if(t[0] == 'P' && t[1] == 'G'){ /*current row is a Point Guard*/
            std::string salary = content[i][4] + content[i][5]; /*to skip over thousands comma*/
            std::string firstName = content[i][2];
            firstName.erase(firstName.end()-1, firstName.end()); /*error adjustment from comma delimiter*/
            std::string lastName = content[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2); /*error asjustment*/
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary); /*converting string salary to int*/
            Player temp = PointGuard(name, sal, std::stod(content[i][3])); /*creating PointGuard obj*/
            if(numPg <= 10){ /*only need top 10*/
                sorted.push_back(temp);
                numPg++;
            }

        }else if(t[0] == 'S' && t[1] == 'G'){ /*current row is a Shooting Guard*/
            std::string salary = content[i][4] + content[i][5]; /*to skip over thousands comma*/
            std::string firstName = content[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
            std::string lastName = content[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = ShootingGuard(name, sal, std::stod(content[i][3])); /*creating ShootingGuard obj*/
            if(numSg <= 10){ /*only need top 10*/
                sorted.push_back(temp);
                numSg++;
            }
        }else if(t[0] == 'P' && t[1] == 'F'){ /*current row is a Power Forward*/
            std::string salary = content[i][4] + content[i][5]; /*to skip over thousands comma*/
            std::string firstName = content[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
            std::string lastName = content[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = PowerForward(name, sal, std::stod(content[i][3])); /*creating PowerForward obj*/
            if(numPf <= 10){ /*only need top 10*/
                sorted.push_back(temp);
                numPf++;
            }
        }else if(t[0] == 'S' && t[1] == 'F'){ /*current Row is a Small Forward*/
            std::string salary = content[i][4] + content[i][5]; /*to skip over thousands comma*/
            std::string firstName = content[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
            std::string lastName = content[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = SmallForward(name, sal, std::stod(content[i][3])); /*creating SmallForward obj*/
            if(numSf <= 10){ /*only need top 10*/
                sorted.push_back(temp);
                numSf++;
            }
        }else if(t[0] == 'C'){ /*current row is a Center*/
            std::string salary = content[i][4] + content[i][5]; /*to skip over thousands comma*/
            std::string firstName = content[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
            std::string lastName = content[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = Center(name, sal, std::stod(content[i][3])); /*creating Center obj*/
            if(numC <= 10){ /*only need top 10*/
                sorted.push_back(temp);
                numC++;
            }
        }
    }
    return sorted;
}

#endif //__PLAYER_SORTER_H__
