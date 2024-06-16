#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>
#include "SnakeMap.h"
#include "InputHandler.h"
#include "MapData.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    Snake(int startX, int startY, SnakeMap& snakeMap);
    void changeDirection(Direction newDirection);
    void move();
    void grow();
    bool checkSnakeCollision();
    void render();
    void gameLoop();

    std::deque<std::pair<int, int>> getBody() const;

private:
    std::deque<std::pair<int, int>> body;
    Direction currentDirection;
    InputHandler inputHandler;
    int tick;
    int growthCount;
    SnakeMap& snakeMap;

    void checkMapCollision();
    void determineGateExit(int gateY, int gateX);
    bool isValidMove(int nextX, int nextY);
    bool isCollision(int x, int y);
};

#endif // SNAKE_H
