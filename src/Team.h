#pragma once

#include "PointGuard.h"
#include "ShootingGuard.h"
#include "PowerForward.h"
#include "SmallForward.h"
#include "center.h"
#include <vector>
#include <iostream>

using namespace std;


class Team{
protected:
	vector<Player> allPlayers;
	vector<Player> bestPlayers;
	vector<vector<string>> unparsedPlayers;
	int salaryCap;
public:
	Team(vector<vector<string>> players){
		for(int i = 0; i < players.size(); i++){
			unparsedPlayers.push_back(players[i]);
		}
		salaryCap = 60000;
	}

	void getPositions(){
		int numPg = 0;
	    int numSg = 0;
   	 int numPf = 0;
  	  int numSf = 0;
  	  int numC = 0;
    for(int i=1;i<unparsedPlayers.size();i++)
    {

        std::string t = unparsedPlayers[i][0];

        if(t[0] == 'P' && t[1] == 'G'){ /*current row is a Point Guard*/
            std::string salary = unparsedPlayers[i][4] + unparsedPlayers[i][5]; /*to skip over thousands comma*/
            std::string firstName = unparsedPlayers[i][2];
            firstName.erase(firstName.end()-1, firstName.end()); /*error adjustment from comma delimiter*/
	    firstName.erase(0, 1);
            std::string lastName = unparsedPlayers[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2); /*error asjustment*/
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary); /*converting string salary to int*/
            Player temp = PointGuard(name, sal, std::stod(unparsedPlayers[i][3])); /*creating PointGuard obj*/
            if(numPg <= 10){ /*only need top 10*/
                allPlayers.push_back(temp);
                numPg++;
            }

        }else if(t[0] == 'S' && t[1] == 'G'){ /*current row is a Shooting Guard*/
            std::string salary = unparsedPlayers[i][4] + unparsedPlayers[i][5]; /*to skip over thousands comma*/
            std::string firstName = unparsedPlayers[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
           firstName.erase(0, 1);
		 std::string lastName = unparsedPlayers[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = ShootingGuard(name, sal, std::stod(unparsedPlayers[i][3])); /*creating ShootingGuard obj*/
            if(numSg <= 10){ /*only need top 10*/
                allPlayers.push_back(temp);
                numSg++;
            }
        }else if(t[0] == 'P' && t[1] == 'F'){ /*current row is a Power Forward*/
            std::string salary = unparsedPlayers[i][4] + unparsedPlayers[i][5]; /*to skip over thousands comma*/
            std::string firstName = unparsedPlayers[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
           firstName.erase(0, 1);
		 std::string lastName = unparsedPlayers[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = PowerForward(name, sal, std::stod(unparsedPlayers[i][3])); /*creating PowerForward obj*/
            if(numPf <= 10){ /*only need top 10*/
                allPlayers.push_back(temp);
                numPf++;
            }
        }else if(t[0] == 'S' && t[1] == 'F'){ /*current Row is a Small Forward*/
            std::string salary = unparsedPlayers[i][4] + unparsedPlayers[i][5]; /*to skip over thousands comma*/
            std::string firstName = unparsedPlayers[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
          	firstName.erase(0, 1);
	  std::string lastName = unparsedPlayers[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = SmallForward(name, sal, std::stod(unparsedPlayers[i][3])); /*creating SmallForward obj*/
            if(numSf <= 10){ /*only need top 10*/
                allPlayers.push_back(temp);
                numSf++;
            }
        }else if(t[0] == 'C'){ /*current row is a Center*/
            std::string salary = unparsedPlayers[i][4] + unparsedPlayers[i][5]; /*to skip over thousands comma*/
            std::string firstName = unparsedPlayers[i][2];
            firstName.erase(firstName.end()-1, firstName.end());
        firstName.erase(0, 1);
	    std::string lastName = unparsedPlayers[i][1];
            lastName.erase(0, 1);
            std::string name = firstName +" " + lastName;
            salary.erase(0,2);
            salary.erase(salary.end(), salary.end());
            int sal = std::stoi(salary);
            Player temp = Center(name, sal, std::stod(unparsedPlayers[i][3])); /*creating Center obj*/
            if(numC <= 10){ /*only need top 10*/
                allPlayers.push_back(temp);
                numC++;
            }
        }
    }
    
	}

	void valueSorter() {
    for(int i = 0; i < allPlayers.size(); i++){
        for(int k = 0; k < allPlayers.size(); k++){
            if(i != k){
                if(allPlayers[k].calculateValue() < allPlayers[i].calculateValue()){
                    swap(allPlayers[i], allPlayers[k]);
                }
            }
        }
    }	
	}

	void bestByValue(){
		int pg_count = 0;
    int sg_count = 0;
    int pf_count = 0;
    int sf_count = 0;
    int c_count = 0;

/*figuring out best lineup first based on value*/
    for(int i = 0; i < allPlayers.size(); i++){


        if(salaryCap - allPlayers[i].getCost() >= 0){

            if(allPlayers[i].getPos() == "C" && c_count != 1){

                bestPlayers.push_back(allPlayers[i]);
                c_count++;
                salaryCap -= allPlayers[i].getCost();
                allPlayers.erase(allPlayers.begin() + i); //erasing player from list to prevent double adding
                i -= 1;

            }else if(allPlayers[i].getPos() == "SF" && sf_count != 2){
                bestPlayers.push_back(allPlayers[i]);
                sf_count++;
                salaryCap -= allPlayers[i].getCost();
                allPlayers.erase(allPlayers.begin() + i);
                i -= 1;
            }else if(allPlayers[i].getPos() == "PF" && pf_count != 2){
                bestPlayers.push_back(allPlayers[i]);
                pf_count++;
                salaryCap -= allPlayers[i].getCost();
                allPlayers.erase(allPlayers.begin() + i);
                i -=1;
            }else if(allPlayers[i].getPos() == "SG" && sg_count != 2){
                bestPlayers.push_back(allPlayers[i]);
                sg_count++;
                salaryCap -= allPlayers[i].getCost();
                allPlayers.erase(allPlayers.begin() + i);
                i -= 1;
            }else if(allPlayers[i].getPos() == "PG" && pg_count != 2){
                bestPlayers.push_back(allPlayers[i]);
                pg_count++;
                salaryCap -= allPlayers[i].getCost();
                allPlayers.erase(allPlayers.begin() + i);
                i -= 1;
            }

        }

    }
	}

	void sortByPointsScored(){
	/*sorting by Points scored*/
    for(int i = 0; i < allPlayers.size(); i++){
        for(int k = 0; k < allPlayers.size(); k++){
            if(i != k){
                if(allPlayers[k].getPoints() < allPlayers[i].getPoints()){
                    swap(allPlayers[i], allPlayers[k]);
                }
            }
        }
    }
	}

	void spendRemainingCapOnPoints(){
	for(int i =0; i < allPlayers.size(); i++){
        Player temp = allPlayers[i];

        for(int k = 0; k < bestPlayers.size(); k++){

            if(temp.getPoints() > bestPlayers[k].getPoints() && (salaryCap - (temp.getCost() - bestPlayers[k].getCost()) >= 0) && temp.getPosVal() == bestPlayers[k].getPosVal()){
                int salDiff = temp.getCost() - bestPlayers[k].getCost();
                bestPlayers[k] = temp;
                salaryCap -= salDiff;
                break;
            }


        }
    }

        }

	void printBestLineup(){
		 double totalPoints = 0.0;
    int teamSalary = 60000 - salaryCap;
	for(int i = 0; i < bestPlayers.size(); i++){
		  Player temp = bestPlayers[i];
        totalPoints += temp.getPoints();
        std::cout << temp.getPos() << " " << temp.getName() << " " << temp.getPoints() << " $" << temp.getCost() << " " << temp.calculateValue() << std::endl;
    }
    std::cout << std::endl <<  std::endl << "Total Points: " << totalPoints << "     Team Salary: $" << teamSalary << std::endl;	



	}	

	void sortByPosition() {
for(int i =0; i < bestPlayers.size(); i++){
for(int k = 0; k < bestPlayers.size(); k++){
if(i != k){
if(bestPlayers[i].getPosVal() < bestPlayers[k].getPosVal()){
swap(bestPlayers[i], bestPlayers[k]);
}
}
}
}
}
};
