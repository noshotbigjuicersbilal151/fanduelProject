#include <iostream>
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
                        Player temp = ShootingGuard(name, sal, std::stod(content[i][3]));
                        if(c.size() <= 10){ //only need top 10
                        c.push_back(temp);
                        }
                }
	}
std::cout << "Point Guards: " << std::endl;

for(int i = 0; i < pg.size(); i++){
	std::cout << pg[i].getPos() << " " << pg[i].getName() << " " << pg[i].getCost() << " " << pg[i].getPoints() << std::endl;
}
std::cout << "Shooting Guards: " << std::endl;
for(int i = 0; i < sg.size(); i++){
        std::cout << sg[i].getPos() << " " << sg[i].getName() << " " << sg[i].getCost() << " " << sg[i].getPoints() << std::endl;
}
std::cout << "Power Forwards: " << std::endl;
for(int i = 0; i < pf.size(); i++){
        std::cout << pf[i].getPos() << " " << pf[i].getName() << " " << pf[i].getCost() << " " << pf[i].getPoints() << std::endl;
}
std::cout << "Small Forwards: " << std::endl;
for(int i = 0; i < sf.size(); i++){
        std::cout << sf[i].getPos() << " " << sf[i].getName() << " " << sf[i].getCost() << " " << sf[i].getPoints() << std::endl;
}
std::cout << "Centers: " << std::endl;
for(int i = 0; i < c.size(); i++){
        std::cout << c[i].getPos() << " " << c[i].getName() << " " << c[i].getCost() << " " << c[i].getPoints() << std::endl;
}
return 0;
} 
 

