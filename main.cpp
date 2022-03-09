#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "csvReader.h"
#include "src/playerSorter.h"
#include "src/bestLineUpAlgorithm.h"
#include "src/teamSorter.h"
#include "src/valueSorter.h"

using namespace std;
int main(){

    system("python3 ~/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");

    vector<vector<string>> content = csvReader("bestPlayers.csv"); //loads player info as strings

    vector<Player> sorted = playerSorter(content);

/*sorting first by value (points * 1000 / cost)*/
    valueSorter(sorted);

    vector<Player> bestLineup = bestLineUpAlgorithm(sorted);

/*outputting team and tracking team points and team salary*/
    bool printed = false;
    if(!printed){

	    printBestLineup(bestLineup, printed);
    } 
    return 0;
}
