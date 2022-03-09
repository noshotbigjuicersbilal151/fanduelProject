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

TEST(DynamicCSV, FirstPlayer) {
vector<vector<string>> contents = csvReader("bestPlayers.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ(" James^ Harden", sorted[0].getName());
}

int main(int argc, char **argv) {
  cout << "Enter 2, 28, then 2018 (Feb, 28 2018) for test" << endl;
  system("python3 ~/final-project-jkusc002-bnasi004-cchua032-aoce003/webscraper.py");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
