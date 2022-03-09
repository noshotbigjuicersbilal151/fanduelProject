
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "csvReader.h"
#include "src/Team.h"

using namespace std;

TEST(Webscraper, validDate){

}
TEST(FixedCSV, getPositions) {
vector<vector<string>> contents = csvReader("test.csv");
Team test = Team(contents);
test.getPositions();
vector<Player> players = test.getAllPlayers();

EXPECT_EQ("James^ Harden",players[0].getName());
EXPECT_EQ("DeMar^ DeRozan", players[1].getName());
EXPECT_EQ("Kyrie^ Irving", players[2].getName());
}

TEST(FixedCSV, valueSorter) {
vector<vector<string>> contents = csvReader("test.csv");
Team test = Team(contents);
test.getPositions();
test.valueSorter();

vector<Player> players = test.getAllPlayers();

EXPECT_EQ("Taurean Prince",players[0].getName());
EXPECT_EQ("Nemanja Bjelica", players[1].getName());
EXPECT_EQ("Rodney Stuckey", players[2].getName());
}

TEST(FixedCSV, bestByValue) {
vector<vector<string>> contents = csvReader("test.csv");
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();

vector<Player> players = test.getBestPlayers();

EXPECT_EQ("Rodney Stuckey",players[2].getName());
EXPECT_EQ("Courtney^ Lee", players[3].getName());
EXPECT_EQ("Richaun Holmes", players[4].getName());
}

TEST(FixedCSV, sortByPoints) {
vector<vector<string>> contents = csvReader("test.csv");
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();
test.sortByPointsScored();

vector<Player> players = test.getAllPlayers();

EXPECT_EQ("DeMar^ DeRozan",players[2].getName());
EXPECT_EQ("Hassan^ Whiteside", players[3].getName());
EXPECT_EQ("Draymond^ Green", players[4].getName());
}

TEST(FixedCSV, bestLineup) {
vector<vector<string>> contents = csvReader("test.csv");
Team test = Team(contents);
test.getPositions();
test.valueSorter();
test.bestByValue();
test.sortByPointsScored();
test.spendRemainingCapOnPoints();

vector<Player> players = test.getBestPlayers();

EXPECT_EQ("Karl-Anthony^ Towns",players[6].getName());
EXPECT_EQ("Malcolm Brogdon", players[7].getName());
EXPECT_EQ("Ty^ Lawson", players[8].getName());
}

TEST(FixedCSV, sortByPosition) {
vector<vector<string>> contents = csvReader("test.csv");
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




int main(int argc, char **argv) {
  cout << "Enter 2, 28, then 2018 (Feb 28, 2018) for test" << endl;
  system("python3 ~/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");
  ::testing::InitGoogleTest(&argc, argv);
  int first = RUN_ALL_TESTS();
return RUN_ALL_TESTS();
}
