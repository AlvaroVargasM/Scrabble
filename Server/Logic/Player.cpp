#include "Player.h"


/**
 * Returns the name of the player
 * @return name
 */
const std::string &Player::getName() const {
    return this->name;
}

/**
 * Sets the name of a player
 * @param name
 */
void Player::setName(const std::string &name) {
    Player::name = name;
}

/**
 * Returns the points of a players
 * @return points
 */
int Player::getPoints() const {
    return this->points;
}

/**
 * Sets the points for a player
 * @param points
 */
void Player::setPoints(int points) {
    Player::points = points;
}

/**
 * Set the connector
 * @param connection
 */
void Player::setConnection(int *connection) {
    this->connection = connection;
}

/**
 * Say whether or not is your turn
 * @return turn
 */
bool Player::isTurn() const {
    return turn;
}

/**
 * Sets the turn for the player
 * @param turn
 */
void Player::setTurn(bool turn) {
    Player::turn = turn;
}

/**
 * Returns a pointer to the player's connection
 * @return *Player
 */
int *Player::getConnection() const {
    return connection;
}

/**
 * Say whether the player is ready
 * @return ready
 */
bool Player::isReady() const {
    return ready;
}

/**
 * Sets the ready value
 * @param ready
 */
void Player::setReady(bool ready) {
    Player::ready = ready;
}
