#ifndef GATE_H
#define GATE_H

#include "SnakeMap.h"
#include "Direction.h" // Direction 열거형 포함
#include <utility>
#include <vector>

class Gate {
public:
    Gate();
    void generateGate(SnakeMap& snakeMap);
    void updateGate(SnakeMap& snakeMap);
    std::pair<int, int> getGateEntry(int index) const;
    std::pair<int, int> getGateExit(int index) const;
    Direction getExitDirection(const std::pair<int, int>& entryPosition, Direction entryDirection, const SnakeMap& snakeMap) const;

private:
    std::vector<std::pair<int, int>> gates; // 게이트 위치
    bool gatesActive;
    int gateTimer;
    std::pair<int, int> getRandomWallPosition(SnakeMap& snakeMap);
    std::vector<std::pair<int, int>> getWallPositions(SnakeMap& snakeMap);
    bool isValidGatePosition(const std::pair<int, int>& position, const SnakeMap& snakeMap);
    void clearGates(SnakeMap& snakeMap);
};

#endif // GATE_H