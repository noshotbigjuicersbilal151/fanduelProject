#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "csvReader.h"
#include "src/Team.h"

using namespace std;

int main(){
	bool loop;
	char response;
	do {
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
		/*These two lines of code delays the program so the user may look at their best lineup before choosing to do the program again or stop it*/
		this_thread::sleep_for(chrono::seconds(2));
        	this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1));
		/*This last segment is what allows the program to loop again */
        	cout << endl << "Do you want to find another lineup from another date?" << endl;
        	cout << "Yes (Y) / No (N) :  ";
        	cin >> response;
        	cout << endl;
        	if (response == 'Y' || response == 'y') {
            		loop = true;
        	} else {
            		loop = false;
        	}
	} while (loop);
	return 0;
}
