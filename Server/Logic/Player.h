#ifndef QUEUE_USING_OOP_PLAYER_H
#define QUEUE_USING_OOP_PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int points;
    int* connection;
    bool turn;
    bool ready;

public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getPoints() const;

    void setPoints(int points);

    void setConnection(int*);

    bool isTurn() const;

    void setTurn(bool turn);

    int *getConnection() const;

    bool isReady() const;

    void setReady(bool ready);
};


#endif //QUEUE_USING_OOP_PLAYER_H
