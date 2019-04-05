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

void Player::setConnection(int *connection) {
    this->connection = connection;
}

bool Player::isTurn() const {
    return turn;
}

void Player::setTurn(bool turn) {
    Player::turn = turn;
}

int *Player::getConnection() const {
    return connection;
}

bool Player::isReady() const {
    return ready;
}

void Player::setReady(bool ready) {
    Player::ready = ready;
}
