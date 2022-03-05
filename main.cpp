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
vector<vector<string>> content = csvReader();
for(int i=2;i<content.size();i++)
	{	
		std::string t = content[i][0];
		if(t[0] == 'P'){
			
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
			
		}
	}

for(int i = 0; i < pg.size(); i++){
	std::cout << pg[i].getPos() << " " << pg[i].getName() << " " << pg[i].getCost() << " " << pg[i].getPoints() << std::endl;
}

return 0;
} 
 

