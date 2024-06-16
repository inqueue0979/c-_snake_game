#include "Gate.h"
#include <cstdlib>
#include <ctime>

Gate::Gate() : gatesActive(false), gateTimer(0) {
    std::srand(std::time(nullptr)); // 랜덤 시드 설정
}

void Gate::generateGate(SnakeMap& snakeMap) {
    clearGates(snakeMap);

    std::vector<std::pair<int, int>> wallPositions = getWallPositions(snakeMap);
    if (wallPositions.size() < 2) {
        return; // 벽 위치가 충분하지 않으면 게이트 생성 불가
    }

    std::random_shuffle(wallPositions.begin(), wallPositions.end());

    gates.clear();
    gates.push_back(wallPositions[0]);
    gates.push_back(wallPositions[1]);

    snakeMap.setMap(gates[0].first, gates[0].second, 7); // 게이트 표시
    snakeMap.setMap(gates[1].first, gates[1].second, 7); // 게이트 표시

    gatesActive = true;
}

void Gate::updateGate(SnakeMap& snakeMap) {
    if (!gatesActive && gateTimer >= 40) { // 10초마다 게이트 생성
        generateGate(snakeMap);
        gateTimer = 0;
    } else if (gatesActive && gateTimer >= 60) { // 15초마다 게이트 위치 변경
        generateGate(snakeMap);
        gateTimer = 0;
    }
    gateTimer++;
}

std::pair<int, int> Gate::getGateEntry(int index) const {
    if (index >= 0 && index < gates.size()) {
        return gates[index];
    }
    return {-1, -1};
}

std::pair<int, int> Gate::getGateExit(int index) const {
    if (index == 0) {
        return gates[1];
    } else if (index == 1) {
        return gates[0];
    }
    return {-1, -1};
}

Direction Gate::getExitDirection(const std::pair<int, int>& entryPosition, Direction entryDirection, const SnakeMap& snakeMap) const {
    int x = entryPosition.second;
    int y = entryPosition.first;
    int size = snakeMap.getSize();

    // 가장자리 벽 처리
    if (y == 0) return DOWN; // 상단 벽
    if (y == size - 1) return UP; // 하단 벽
    if (x == 0) return RIGHT; // 좌측 벽
    if (x == size - 1) return LEFT; // 우측 벽

    //가운데 벽 처리
    switch (entryDirection) {
        case UP:
            if (snakeMap.getMap()[y - 1][x] == 0) return UP;
            if (snakeMap.getMap()[y][x + 1] == 0) return RIGHT;
            if (snakeMap.getMap()[y][x - 1] == 0) return LEFT;
            return DOWN;
        case DOWN:
            if (snakeMap.getMap()[y + 1][x] == 0) return DOWN;
            if (snakeMap.getMap()[y][x + 1] == 0) return RIGHT;
            if (snakeMap.getMap()[y][x - 1] == 0) return LEFT;
            return UP;
        case LEFT:
            if (snakeMap.getMap()[y][x - 1] == 0) return LEFT;
            if (snakeMap.getMap()[y - 1][x] == 0) return UP;
            if (snakeMap.getMap()[y + 1][x] == 0) return DOWN;
            return RIGHT;
        case RIGHT:
            if (snakeMap.getMap()[y][x + 1] == 0) return RIGHT;
            if (snakeMap.getMap()[y - 1][x] == 0) return UP;
            if (snakeMap.getMap()[y + 1][x] == 0) return DOWN;
            return LEFT;
    }

    return UP; // 기본값
}

std::vector<std::pair<int, int>> Gate::getWallPositions(SnakeMap& snakeMap) {
    std::vector<std::pair<int, int>> wallPositions;
    int size = snakeMap.getSize();
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (snakeMap.getMap()[y][x] == 1) { // 벽 위치 수집
                wallPositions.push_back({y, x});
            }
        }
    }
    return wallPositions;
}

void Gate::clearGates(SnakeMap& snakeMap) {
    for (const auto& gate : gates) {
        snakeMap.setMap(gate.first, gate.second, 1); // 게이트를 벽으로 복원
    }
    gates.clear();
    gatesActive = false;
}