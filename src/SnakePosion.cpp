#include "SnakePosition.h"

SnakePosition::SnakePostiion(int x, int y) : posX(x), posY(y) {}

int SnakePosition::getPosX() const {
    return posX;
}

int SnakePosition::getPosY() const {
    return posY;
}

void SnakePosition::setPosX(int x) {
    posX = x;
}

void SnakePosition::setPosY(int y) {
    posY = y;
}
