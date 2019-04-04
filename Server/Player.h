#ifndef QUEUE_USING_OOP_PLAYER_H
#define QUEUE_USING_OOP_PLAYER_H


#include <string>

class Player {
private:
    std::string name;
    int points;
    int* connection;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getPoints() const;

    void setPoints(int points);

    void setConnection(int*);
};


#endif //QUEUE_USING_OOP_PLAYER_H
