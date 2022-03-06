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
 
vector<vector<string>> csvReader(){
	string fname = "bestPlayers.csv";
 
	vector<vector<string>> output;
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')) //separates by using commas as delimiters
				row.push_back(word);
			output.push_back(row);
		}
	}
	
 
	return output;
 
}

int main(){

system("python3 /home/csmajs/bnasi004/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");

vector<Player> pg;
vector<Player> sg;
vector<Player> c;
vector<Player> pf;
vector<Player> sf;
vector<vector<string>> content = csvReader(); //loads player info as strings
for(int i=2;i<content.size();i++)
	{	
			
			std::string t = content[i][0];
			
		if(t[0] == 'P' && t[1] == 'G'){ //current row is a Point Guard
                        std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end()); //error adjustment from comma delimiter
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2); //error asjustment
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary); //converting string salary to int
			Player temp = PointGuard(name, sal, std::stod(content[i][3])); //creating PointGuard obj
			if(pg.size() <= 10){ //only need top 10
			pg.push_back(temp);
			}
			
		}else if(t[0] == 'S' && t[1] == 'G'){ //current row is a Shooting Guard
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = ShootingGuard(name, sal, std::stod(content[i][3])); //creating ShootingGuard obj
                        if(sg.size() <= 10){ //only need top 10
                        sg.push_back(temp);
                        }
                }else if(t[0] == 'P' && t[1] == 'F'){ //current row is a Power Forward
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = PowerForward(name, sal, std::stod(content[i][3])); //creating PowerForward obj
                        if(pf.size() <= 10){ //only need top 10
                        pf.push_back(temp);
                        }
                }else if(t[0] == 'S' && t[1] == 'F'){ //current Row is a Small Forward
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = SmallForward(name, sal, std::stod(content[i][3])); //creating SmallForward obj
                        if(sf.size() <= 10){ //only need top 10
                        sf.push_back(temp);
                        }
                }else if(t[0] == 'C'){ //current row is a Center
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = Center(name, sal, std::stod(content[i][3])); //creating Center obj
                        if(c.size() <= 10){ //only need top 10
                        c.push_back(temp);
                        }
                }
	}
//Combining different positions into one vector
vector<Player> sorted;

for(int i = 0; i < pg.size(); i++){
	sorted.push_back(pg[i]);
}

for(int i = 0; i < sg.size(); i++){
        sorted.push_back(sg[i]);
}

for(int i = 0; i < pf.size(); i++){
        sorted.push_back(pf[i]);
}

for(int i = 0; i < sf.size(); i++){
        sorted.push_back(sf[i]);
}

for(int i = 0; i < c.size(); i++){
        sorted.push_back(c[i]);
}

//sorting first by value (points * 1000 / cost)
for(int i = 0; i < sorted.size(); i++){
        for(int k = 0; k < sorted.size(); k++){
                if(i != k){
                        if(sorted[k].calculateValue() < sorted[i].calculateValue()){
                        swap(sorted[i], sorted[k]);
                        }
                }
        }
}


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
//figuring out best lineup first based on value
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
//sorting by Points scored
for(int i = 0; i < sorted.size(); i++){
        for(int k = 0; k < sorted.size(); k++){
                if(i != k){
                        if(sorted[k].getPoints() < sorted[i].getPoints()){
                        swap(sorted[i], sorted[k]);
                        }
                }
        }
}
//using leftover salaryCap to get players that were less valueable but scored more overall points
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
//outputting team and tracking team points and team salary
double totalPoints = 0.0;
int teamSalary = 0;
for(int i =0; i < bestLineup.size(); i++){
	for(int k = 0; k < bestLineup.size(); k++){
	if(i != k){
		if(bestLineup[i].getPosVal() < bestLineup[k].getPosVal()){
			swap(bestLineup[i], bestLineup[k]);
	}
}
}
}
std::cout << "Best Possible Fanduel Lineup: " << std::endl << std::endl;
for(int i = 0; i < bestLineup.size(); i++){
	Player temp = bestLineup[i];
	totalPoints += temp.getPoints();
	teamSalary += temp.getCost();
	std::cout << temp.getPos() << " " << temp.getName() << " " << temp.getPoints() << " $" << temp.getCost() << " " << temp.calculateValue() << std::endl;	
}
std::cout << std::endl << "Total Points: " << totalPoints << "     Team Salary: " << teamSalary << std::endl;
return 0;

} 
 

