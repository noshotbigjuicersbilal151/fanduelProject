#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "csvReader.h"
#include "src/playerSorter.h"
#include "src/bestLineUpAlgorithm.h"
#include "src/teamSorter.h"
#include "src/valueSorter.h"
#include "src/Team.h"

using namespace std;

int main(){

    system("python3 ~/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");

    vector<vector<string>> content = csvReader("bestPlayers.csv"); //loads player info as strings

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
