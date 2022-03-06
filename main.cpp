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
 
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	return content;
 
}

int main(){
vector<Player> pg;
vector<Player> sg;
vector<Player> c;
vector<Player> pf;
vector<Player> sf;
vector<vector<string>> content = csvReader();
for(int i=2;i<content.size();i++)
	{	
			
			std::string t = content[i][0];
			
		if(t[0] == 'P' && t[1] == 'G'){
                        std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
			Player temp = PointGuard(name, sal, std::stod(content[i][3]));
			if(pg.size() <= 10){ //only need top 10
			pg.push_back(temp);
			}
			
		}else if(t[0] == 'S' && t[1] == 'G'){
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = ShootingGuard(name, sal, std::stod(content[i][3]));
                        if(sg.size() <= 10){ //only need top 10
                        sg.push_back(temp);
                        }
                }else if(t[0] == 'P' && t[1] == 'F'){
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = PowerForward(name, sal, std::stod(content[i][3]));
                        if(pf.size() <= 10){ //only need top 10
                        pf.push_back(temp);
                        }
                }else if(t[0] == 'S' && t[1] == 'F'){
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = SmallForward(name, sal, std::stod(content[i][3]));
                        if(sf.size() <= 10){ //only need top 10
                        sf.push_back(temp);
                        }
                }else if(t[0] == 'C'){
			std::string salary = content[i][4] + content[i][5]; //to skip over thousands comma
                        std::string firstName = content[i][2];
                        firstName.erase(firstName.end()-1, firstName.end());
                        std::string lastName = content[i][1];
                        lastName.erase(0, 1);
                        std::string name = firstName +" " + lastName;
                        salary.erase(0,2);
                        salary.erase(salary.end(), salary.end());
                        int sal = std::stoi(salary);
                        Player temp = Center(name, sal, std::stod(content[i][3]));
                        if(c.size() <= 10){ //only need top 10
                        c.push_back(temp);
                        }
                }
	}

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

for(int i = 0; i < sorted.size(); i++){
        for(int k = 0; k < sorted.size(); k++){
                if(i != k){
                        if(sorted[k].getPoints() < sorted[i].getPoints()){
                        swap(sorted[i], sorted[k]);
                        }
                }
        }
}

for(int i =0; i < sorted.size(); i++){
	Player temp = sorted[i];
	
	for(int k = 0; k < bestLineup.size(); k++){
		
		if(temp.getPoints() > bestLineup[k].getPoints() && (salaryCap - (temp.getCost() - bestLineup[k].getCost()) >= 0)){
		int salDiff = temp.getCost() - bestLineup[k].getCost();
		bestLineup[k] = temp;
		salaryCap -= salDiff;
		break;
}


}
}

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
 

