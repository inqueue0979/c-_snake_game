#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>
#include "SnakeMap.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    Snake(int startX, int startY, SnakeMap& snakeMap);
    void changeDirection(Direction newDirection);
    void move();
    void render();
    void addBodySegment(); // 새 몸통을 추가하는 메서드
    std::pair<int, int> getHeadPosition() const;
    const std::deque<std::pair<int, int>>& getBody() const;

private:
    bool isValidMove(int nextX, int nextY);
    bool isCollision(int x, int y);

    SnakeMap& snakeMap;
    std::deque<std::pair<int, int>> body;
    Direction currentDirection;
};

#endif // SNAKE_H