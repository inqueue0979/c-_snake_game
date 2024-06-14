#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);
    void move(char direction);
    void grow();
    bool checkCollision(int mapWidth, int mapHeight);
    const std::deque<std::pair<int, int> >& getBody() const;

private:
    std::deque<std::pair<int, int> > body;
    char currentDirection;
};

#endif // SNAKE_H
