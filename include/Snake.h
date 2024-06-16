#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>
#include "SnakeMap.h"
#include "Gate.h"
#include "ScoreBoard.h"
#include "Direction.h" // Direction 열거형 포함

class Snake {
public:
    Snake(int startX, int startY, SnakeMap& snakeMap, ScoreBoard& scoreBoard);
    Snake(const Snake& other); // 복사 생성자
    Snake& operator=(const Snake& other); // 복사 할당 연산자

    void changeDirection(Direction newDirection);
    void move(Gate& gateManager);
    void reset(int startX, int startY); // 추가된 reset 메서드
    void addBodySegment(); // 새 몸통을 추가하는 메서드
    void removeBodySegment(); // 몸통을 한 칸 제거하는 메서드
    std::pair<int, int> getHeadPosition() const;
    const std::deque<std::pair<int, int>>& getBody() const;

private:
    bool isValidMove(int nextX, int nextY);
    int whatIsInFrontOf(int nextX, int nextY);
    bool isCollision(int x, int y);
    void handleGate(Gate& gateManager);

    SnakeMap& snakeMap;
    ScoreBoard& scoreBoard;
    std::deque<std::pair<int, int>> body;
    Direction currentDirection;
};

#endif // SNAKE_H