#include "Player.h"

void Player::setCost(int icost) {
    cost = icost;
}
void Player::setPoints(int inumPoints) {
    numPoints = inumPoints;
}
void Player::setAssists(int inumAssists) {
    numAssists = inumAssists;
}
void Player::setReb(int inumReb) {
    numReb = inumReb;
}
void Player::setBlocks(int inumBlock) {
    numBlock = inumBlock;
}
void Player::setSteals(int inumSteals) {
    numSteal = inumSteals;
}
void Player::setTO(int inumTO) {
    numTO = inumTO;
}
void Player::setName(std::string iname) {
        name = iname;
}
int Player::getCost() {
    return cost;
}
int Player::getPts() {
    return numPoints;
}
int Player::getAssists() {
    return numAssists;
}
int Player::getReb() {
    return numReb;
}
int Player::getBlock() {
    return numBlock;
}
std::string Player::getName() {
    return name;
}
float Player::calculatePoints() {
    float pointsScored = 0.0;
    pointsScored += numPoints;
    pointsScored += 1.5 * numAssists;
    pointsScored += 1.2 * numReb;
    pointsScored += 3 * (numBlock + numSteal);
    pointsScored -= numTO;

    return pointsScored;
}
