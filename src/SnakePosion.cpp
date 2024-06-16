#include "Snakeposion.h"

Snakeposion::Snakeposion(int x, int y) : posX(x), posY(y) {}

int Snakeposion::getPosX() const {
    return posX;
}

int Snakeposion::getPosY() const {
    return posY;
}

void Snakeposion::setPosX(int x) {
    posX = x;
}

void Snakeposion::setPosY(int y) {
    posY = y;
}
