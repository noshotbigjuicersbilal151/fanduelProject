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

TEST(VectorTest, FirstPlayer) {
vector<vector<string>> contents = csvReader("test.csv");
vector<Player> sorted = playerSorter(contents);
EXPECT_EQ(" James^ Harden", sorted[0].getName());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
