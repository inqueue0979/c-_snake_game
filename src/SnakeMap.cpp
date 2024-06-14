#include "SnakeMap.h"
#include <ncurses.h>

SnakeMap::SnakeMap(int size) : size(size) {
    map = new int*[size];
    for (int i = 0; i < size; ++i) {
        map[i] = new int[size];
    }
}

SnakeMap::~SnakeMap() {
    for (int i = 0; i < size; ++i) {
        delete[] map[i];
    }
    delete[] map;
}

void SnakeMap::loadMap(int level[21][21]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = level[i][j];
        }
    }
}

void SnakeMap::drawMap() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (map[i][j] == 1) {
                mvaddch(i, j, '#'); // 벽
            } else if (map[i][j] == 0) {
                mvaddch(i, j, ' '); // 빈 공간
            }
        }
    }
    refresh();
}

bool SnakeMap::isCollision(int x, int y) {
    return map[y][x] == 1;
}
