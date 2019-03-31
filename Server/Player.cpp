#include "Player.h"

const std::string &Player::getName() const {
    return this->name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

int Player::getPoints() const {
    return this->points;
}

void Player::setPoints(int points) {
    Player::points = points;
}