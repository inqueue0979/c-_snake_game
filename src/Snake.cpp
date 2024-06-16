#include "Snake.h"
#include <ncurses.h>
#include <unistd.h>

Snake::Snake(int startX, int startY, SnakeMap& snakeMap) 
    : snakeMap(snakeMap), currentDirection(RIGHT) {
    body.push_front(std::make_pair(startY, startX));     // 머리
    body.push_back(std::make_pair(startY, startX - 1));  // 몸통 첫 번째 부분
    body.push_back(std::make_pair(startY, startX - 2));  // 몸통 두 번째 부분

    for (const auto& segment : body) {
        snakeMap.setMap(segment.first, segment.second, 4); // Snake body on the map
    }
    snakeMap.setMap(body.front().first, body.front().second, 3); // Snake head on the map
}

void Snake::changeDirection(Direction newDirection) {
    if ((currentDirection == UP && newDirection != DOWN) ||
        (currentDirection == DOWN && newDirection != UP) ||
        (currentDirection == LEFT && newDirection != RIGHT) ||
        (currentDirection == RIGHT && newDirection != LEFT)) {
        currentDirection = newDirection;
    }
}

void Snake::move() {
    auto head = body.front();
    int nextX = head.second;
    int nextY = head.first;

    switch (currentDirection) {
        case UP:
            nextY -= 1; // 한 칸 위로
            break;
        case DOWN:
            nextY += 1; // 한 칸 아래로
            break;
        case LEFT:
            nextX -= 1; // 한 칸 왼쪽으로
            break;
        case RIGHT:
            nextX += 1; // 한 칸 오른쪽으로
            break;
    }

    if (!isValidMove(nextX, nextY)) {
        return; // Invalid move, do not proceed
    }

    body.push_front(std::make_pair(nextY, nextX));
    snakeMap.setMap(body.front().first, body.front().second, 3); // 머리 위치 업데이트
    snakeMap.setMap(body[1].first, body[1].second, 4); // 이전 머리를 몸통으로 업데이트

    auto tail = body.back();
    snakeMap.setMap(tail.first, tail.second, 0); // 꼬리 제거
    body.pop_back();
}

std::pair<int, int> Snake::getHeadPosition() const {
    return body.front();
}

const std::deque<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

bool Snake::isValidMove(int nextX, int nextY) {
    int mapElement = snakeMap.getMap()[nextY][nextX];
    if (mapElement == 1 || mapElement == 2 || mapElement == 3 || mapElement == 4) {
        return false; // Collision with wall or snake body
    }
    return true;
}

bool Snake::isCollision(int x, int y) {
    int mapElement = snakeMap.getMap()[y][x];
    return (mapElement == 1 || mapElement == 2 || mapElement == 3 || mapElement == 4);
}