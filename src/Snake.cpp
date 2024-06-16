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

    int inFrontHead = whatIsInFrontOf(nextX, nextY);

    switch (inFrontHead) {
        case 5: // Growth item
            addBodySegment();
            snakeMap.setMap(nextY, nextX, 0);
            break;
        case 6: // Poison item
            removeBodySegment();
            snakeMap.setMap(nextY, nextX, 0);
            break;
    }


    body.push_front(std::make_pair(nextY, nextX));
    snakeMap.setMap(body.front().first, body.front().second, 3); // 머리 위치 업데이트
    snakeMap.setMap(body[1].first, body[1].second, 4); // 이전 머리를 몸통으로 업데이트

    auto tail = body.back();
    snakeMap.setMap(tail.first, tail.second, 0); // 꼬리 제거
    body.pop_back();
}

void Snake::addBodySegment() {
    auto tail = body.back();
    body.push_back(tail); // 기존 꼬리를 복제하여 새 몸통을 추가
    snakeMap.setMap(tail.first, tail.second, 4); // 새 몸통을 맵에 추가
}

void Snake::removeBodySegment() {
    if (body.size() > 1) {
        auto tail = body.back();
        body.pop_back(); // 꼬리 제거
        snakeMap.setMap(tail.first, tail.second, 0); // 맵에서 꼬리 제거
    }
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

int Snake::whatIsInFrontOf(int nextX, int nextY) {
    int mapElement = snakeMap.getMap()[nextY][nextX];
    if (mapElement == 5 || mapElement == 6) {
        return mapElement; // Collision with wall or snake body
    }
    return 0;
}

bool Snake::isCollision(int x, int y) {
    int mapElement = snakeMap.getMap()[y][x];
    return (mapElement == 1 || mapElement == 2 || mapElement == 3 || mapElement == 4);
}