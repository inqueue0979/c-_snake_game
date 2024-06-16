#include "SnakeMap.h"
#include "data.h"
#include <iostream>
#include <ncurses.h>

const char *block_data[10] = {" ", "■", "○", "◉", "○", "G", "P", "☐", " ", " "};

SnakeMap::SnakeMap(int size, WINDOW* externalWin) : size(size), mapWin(externalWin) {
    // 2D 배열 동적 할당
    map = new int*[size];
    for (int i = 0; i < size; ++i) {
        map[i] = new int[size];
    }
}

SnakeMap::~SnakeMap() {
    // 동적 할당 해제
    for (int i = 0; i < size; ++i) {
        delete[] map[i];
    }
    delete[] map;
}

void SnakeMap::loadMap(int mapData[25][25]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = mapData[i][j];
        }
    }
}

void SnakeMap::drawMap(int start_x, int start_y) {
    // 테두리 그리기
    box(mapWin, 0, 0);
    int width = 84;

    for (int i = 0; i < 8; ++i) {
        mvwprintw(mapWin, i + start_y, (width - text_title[i].length()) / 2, "%s", text_title[i].c_str());
    }

    start_y += 8; // 마진
    mvwprintw(mapWin, start_y, (width - 7) / 2, "%s", "Level 1");
    start_y += 3; // 마진

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            wattron(mapWin, COLOR_PAIR(2));
            mvwprintw(mapWin, i + start_y, j * 2 + start_x, (const char *)block_data[map[i][j]]); // 가로로 한 칸씩 띄워서 출력
            wattroff(mapWin, COLOR_PAIR(2));
        }
    }
    wrefresh(mapWin);
}

int** SnakeMap::getMap() const {
    return map;
}

void SnakeMap::setMap(int x, int y, int value) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        map[x][y] = value;
    }
}

int SnakeMap::getSize() const
{
    return size;
}
