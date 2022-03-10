
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "csvReader.h"
#include "src/Team.h"

using namespace std;

TEST(FixedCSV, getPositions) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
vector<Player> players = test.getAllPlayers();

EXPECT_EQ("Russell^ Westbrook",players[0].getName());
EXPECT_EQ("Victor^ Oladipo", players[1].getName());
EXPECT_EQ("Devin^ Booker", players[2].getName());
}

TEST(FixedCSV, valueSorter) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
test.valueSorter();

vector<Player> players = test.getAllPlayers();

EXPECT_EQ("Josh^ Jackson",players[0].getName());
EXPECT_EQ("Jakob Poeltl", players[1].getName());
EXPECT_EQ("Andre Iguodala", players[2].getName());
}

TEST(FixedCSV, bestByValue) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();

vector<Player> players = test.getBestPlayers();

EXPECT_EQ("Eric Moreland",players[3].getName());
EXPECT_EQ("Shaquille Harrison", players[4].getName());
EXPECT_EQ("Jarell Martin", players[5].getName());
}

TEST(FixedCSV, sortByPoints) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();
test.sortByPointsScored();

vector<Player> players = test.getAllPlayers();

EXPECT_EQ("Marc^ Gasol",players[2].getName());
EXPECT_EQ("Devin^ Booker", players[3].getName());
EXPECT_EQ("Otto^ Porter", players[4].getName());
}

TEST(FixedCSV, bestLineup) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();
test.sortByPointsScored();
test.spendRemainingCapOnPoints();

vector<Player> players = test.getBestPlayers();

EXPECT_EQ("Jodie Meeks",players[6].getName());
EXPECT_EQ("Russell^ Westbrook", players[7].getName());
EXPECT_EQ("Andrew^ Harrison", players[8].getName());
}

TEST(FixedCSV, sortByPosition) {
vector<vector<string>> contents = csvReader();
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();
test.sortByPointsScored();
test.sortByPosition();

vector<Player> players = test.getBestPlayers();

EXPECT_EQ(1, players[0].getPosVal());
EXPECT_EQ(2, players[2].getPosVal());
EXPECT_EQ(3, players[4].getPosVal());
EXPECT_EQ(4, players[6].getPosVal());
EXPECT_EQ(5, players[8].getPosVal());
}

TEST(Webscraper, fileCreated){
bool exists = true;
system("rm bestPlayers.csv");
cout << "bestPlayers.csv has been deleted, we will now test if the program creates a new csv, enter any date" << endl;
system("python3 webscraper.py");
   ifstream ifile;
   ifile.open("bestPlayers.csv");
   if(ifile) {
      exists = true;
   } else {
      exists = false;
   }
EXPECT_TRUE(exists);
}

TEST(Webscraper, validDate){
vector<vector<string>> contents = csvReader();
int x = 0;
if(contents.size() != 0){
        x = 1;
        }
EXPECT_EQ(1, x);
}


int main(int argc, char **argv) {
cout << "Enter 2, 28, 2018 (Feb 28, 2018) for testing" << endl;
 system("python3 webscraper.py");
  ::testing::InitGoogleTest(&argc, argv);
	
	
return RUN_ALL_TESTS();

}
