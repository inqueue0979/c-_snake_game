// Snake.cpp

#include "Snake.h"
#include <ncurses.h>
#include <unistd.h>
#include "InputHandler.h"

Snake::Snake(int startX, int startY, SnakeMap& snakeMap) 
    : snakeMap(snakeMap), growthCount(0), tick(500000), currentDirection(RIGHT) {
    

    for (int i = 0; i < 3; ++i) {
        body.push_front({startY, startX - i * 2}); // Snake body segments initialized
    }

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
            nextY--;
            break;
        case DOWN:
            nextY++;
            break;
        case LEFT:
            nextX -= 2;
            break;
        case RIGHT:
            nextX += 2;
            break;
    }

    if (!isValidMove(nextX, nextY)) {
        return; // Invalid move, do not proceed
    }

    int mapElement = snakeMap.getMap()[nextY][nextX];

    switch (mapElement) {
        case 0: // 움직일 수 있는 곳
            break;
        case 1: // 기본 벽
        case 2: // immune 벽
        case 3: // 뱀 머리
        case 4: // 뱀 몸통
            return; // 움직이지 않고 함수 종료
        case 5: // Growth 아이템
            growthCount++;
            snakeMap.setMap(nextY, nextX, 0); // 아이템 제거
            break;
        case 6: // Poison 아이템
            if (!body.empty()) {
                snakeMap.setMap(body.back().first, body.back().second, 0); // 꼬리 제거
                body.pop_back();
            }
            snakeMap.setMap(nextY, nextX, 0); // 아이템 제거
            break;
        case 7: // 게이트
            determineGateExit(nextY, nextX);
            break;
        default:
            return; // 그 외의 경우 움직이지 않고 함수 종료
    }

    snakeMap.setMap(head.first, head.second, 4); // Update old head to body
    body.push_front({nextY, nextX});
    snakeMap.setMap(body.front().first, body.front().second, 3); // New head position

    // Check collision after moving
    if (isCollision(body.front().second, body.front().first)) {
        return; // Collision occurred, do not proceed
    }

    // 꼬리 제거 및 성장
    if (growthCount > 0) {
        growthCount--;
    } else {
        snakeMap.setMap(body.back().first, body.back().second, 0); // 꼬리 제거
        body.pop_back();
    }
    render(); 
}

void Snake::determineGateExit(int gateY, int gateX) {
    // Find the direction of the gate
    Direction gateDirection = currentDirection;
    int mapWidth = 25; // getSize를 통해 배열의 크기를 얻을 수 있음
    int mapHeight = 25;

    // Determine if the gate is on the edge or in the center of the map
    if ((gateY == 0 && currentDirection == UP) || 
        (gateY == mapHeight - 1 && currentDirection == DOWN) ||
        (gateX == 0 && currentDirection == LEFT) || 
        (gateX == mapWidth - 2 && currentDirection == RIGHT)) {
        // Gate is on the edge of the map
        switch (currentDirection) {
            case UP:
                currentDirection = DOWN;
                break;
            case DOWN:
                currentDirection = UP;
                break;
            case LEFT:
                currentDirection = RIGHT;
                break;
            case RIGHT:
                currentDirection = LEFT;
                break;
        }
    } else {
        // Gate is in the center of the map
        // Order of preference: current direction, clockwise, counterclockwise, opposite direction
        Direction clockwiseDir, counterclockwiseDir, oppositeDir;

        switch (currentDirection) {
            case UP:
                clockwiseDir = RIGHT;
                counterclockwiseDir = LEFT;
                oppositeDir = DOWN;
                break;
            case DOWN:
                clockwiseDir = LEFT;
                counterclockwiseDir = RIGHT;
                oppositeDir = UP;
                break;
            case LEFT:
                clockwiseDir = UP;
                counterclockwiseDir = DOWN;
                oppositeDir = RIGHT;
                break;
            case RIGHT:
                clockwiseDir = DOWN;
                counterclockwiseDir = UP;
                oppositeDir = LEFT;
                break;
        }

        // Check preferred directions first
        if (currentDirection == gateDirection) {
            // Keep the current direction
        } else if (clockwiseDir == gateDirection) {
            currentDirection = clockwiseDir;
        } else if (counterclockwiseDir == gateDirection) {
            currentDirection = counterclockwiseDir;
        } else if (oppositeDir == gateDirection) {
            currentDirection = oppositeDir;
        }
    }
}

bool Snake::isValidMove(int nextX, int nextY) {
    // Check if the move is within bounds and does not collide with walls or itself
    // int mapSize = snakeMap.getSize();
    // if (nextY < 0 || nextY >= mapSize || nextX < 0 || nextX >= mapSize) {
    //     return false; // Out of bounds
    // }
    
    int mapElement = snakeMap.getMap()[nextY][nextX];
    if (mapElement == 1 || mapElement == 2 || mapElement == 3 || mapElement == 4) {
        return false; // Collision with wall or snake body
    }

    return true;
}

bool Snake::isCollision(int x, int y) {
    // Check if there is a collision at position (x, y)
    int mapElement = snakeMap.getMap()[y][x];
    return (mapElement == 1 || mapElement == 2 || mapElement == 3 || mapElement == 4);
}

void Snake::render() {
    // for (int i = 0; i < 25; ++i) {
    //     for (int j = 0; j < 25; ++j) {
    //         if (snakeMap.getMap()[i][j] == 0) {
    //             mvaddch(i, j, ' '); // 뱀을 그릴 공간을 지우기로 설정
    //         }
    //     }
    // }

    bool isFirst = true;
    for (const auto& segment : body) {
        if (isFirst) {
            mvaddch(segment.first, segment.second, '@');
            isFirst = false;
        } else {
            mvaddch(segment.first, segment.second, 'O');
        }
    }
}


void Snake::gameLoop() {
    while (true) {
        inputHandler.updateDirection();
        int ch = inputHandler.getInput();
        // int ch = getch();
        switch (ch) {
            case KEY_LEFT:
            case 'U':
                changeDirection(LEFT);
                break;
            case 'D':
            case KEY_RIGHT:
                changeDirection(RIGHT);
                break;
            case KEY_UP:
            case 'L':
                changeDirection(UP);
                break;
            case 'R':
            case KEY_DOWN:
                changeDirection(DOWN);
                break;
            case 27: // ESC 키
                return;
        }
        move();

        if (isCollision(body.front().second, body.front().first)) {
            return;
        }

        
        render(); 
        refresh();
        usleep(tick);
    }
}
