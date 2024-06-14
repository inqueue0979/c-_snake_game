#include "Snake.h"
#include <ncurses.h>

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    currentDirection = 'R'; // 초기 방향: 오른쪽
}

void Snake::move(char direction) {
    if ((currentDirection == 'R' && direction == 'L') || 
        (currentDirection == 'L' && direction == 'R') || 
        (currentDirection == 'U' && direction == 'D') || 
        (currentDirection == 'D' && direction == 'U')) {
        direction = currentDirection;
    } else {
        currentDirection = direction;
    }

    int x = body.front().first;
    int y = body.front().second;

    switch (direction) {
        case 'U': y--; break;
        case 'D': y++; break;
        case 'L': x--; break;
        case 'R': x++; break;
    }

    body.push_front({x, y});
    body.pop_back();
}

void Snake::grow() {
    body.push_back(body.back());
}

bool Snake::checkCollision(int mapWidth, int mapHeight) {
    int x = body.front().first;
    int y = body.front().second;

    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) {
        return true;
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i] == body.front()) {
            return true;
        }
    }

    return false;
}

const std::deque<std::pair<int, int> >& Snake::getBody() const {
    return body;
}
