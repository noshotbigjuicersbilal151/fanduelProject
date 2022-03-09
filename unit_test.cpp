#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "csvReader.h"
#include "src/Player.h"
#include "src/PointGuard.h"
#include "src/ShootingGuard.h"
#include "src/SmallForward.h"
#include "src/PowerForward.h"
#include "src/center.h"
#include "src/playerSorter.h"
#include "src/bestLineUpAlgorithm.h"
#include "src/teamSorter.h"
#include "src/valueSorter.h"

using namespace std;

TEST(FixedCSV, FirstPlayer) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ(" James^ Harden", sorted[0].getName());
}
TEST(FixedCSV, FirstPlayerPoints) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_DOUBLE_EQ(53.4, sorted[0].getPoints());
}
TEST(FixedCSV, FirstPlayerCost) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ(12100, sorted[0].getCost());
}
TEST(FixedCSV, FirstPlayerPos) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ("SG", sorted[0].getPos());
}



TEST(FixedCSV, BestLineup) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
vector<Player> bestLineup = bestLineUpAlgorithm(sorted);
bool printed = false;
EXPECT_EQ(true, printBestLineup(bestLineup, printed));
}

TEST(DynamicCSV, FirstPlayer) {
cout << "test for 2, 28, 2018" << endl;
system("python3 ~/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");
vector<vector<string>> contents = csvReader("bestPlayers.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ(" Russell^ Westbrook", sorted[0].getName());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
