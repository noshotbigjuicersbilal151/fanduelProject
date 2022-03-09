#include <iostream>
#include <string>
#include <vector>
#include "csvReader.h"
#include "src/Team.h"

using namespace std;

int main(){


 system("python3 webscraper.py");
    vector<vector<string>> content = csvReader(); //loads player info as strings

    Team fanduel = Team(content);

	fanduel.getPositions();
	fanduel.valueSorter();
	fanduel.bestByValue();
	fanduel.sortByPointsScored();
	fanduel.spendRemainingCapOnPoints();
	fanduel.sortByPosition();
	fanduel.printBestLineup();
	return 0;
}
