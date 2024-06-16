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
    Snake(const Snake& other);
    Snake& operator=(const Snake& other);
    void reset(int startX, int startY); // 초기화 메서드
    void changeDirection(Direction newDirection);
    void move(Gate& gateManager);
    void addBodySegment(); // 새 몸통을 추가하는 메서드
    void removeBodySegment(); // 몸통을 한 칸 제거하는 메서드
    std::pair<int, int> getHeadPosition() const;
    const std::deque<std::pair<int, int>>& getBody() const;
    bool isGameOver() const; // 게임 오버 상태 확인 메서드

private:
    bool isValidMove(int nextX, int nextY);
    int whatIsInFrontOf(int nextX, int nextY);
    bool isCollision(int x, int y);
    void handleGate(Gate& gateManager);
    int snakeLength;

    SnakeMap& snakeMap;
    ScoreBoard& scoreBoard;
    std::deque<std::pair<int, int>> body;
    Direction currentDirection;
    bool gameOver; // 게임 오버 상태를 저장하는 변수
};

#endif // SNAKE_H