#include "SnakeMap.h"
#include "data.h"
#include <iostream>

SnakeMap::SnakeMap(int size) : size(size) {
    // 2D 배열 동적 할당
    map = new int*[size];
    for (int i = 0; i < size; ++i) {
        map[i] = new int[size];
    }

    // ncurses 초기화 및 윈도우 생성
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    mapWin = newwin(42, 84, (LINES - 42) / 2, (COLS - 84) / 2);
    wbkgd(mapWin, COLOR_PAIR(1));
    box(mapWin, 0, 0);
    wrefresh(mapWin);
}

SnakeMap::~SnakeMap() {
    // 동적 할당 해제
    for (int i = 0; i < size; ++i) {
        delete[] map[i];
    }
    delete[] map;
    // 윈도우 종료
    delwin(mapWin);
    endwin();
}

void SnakeMap::loadMap(int mapData[25][25]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = mapData[i][j];
        }
    }
}

void SnakeMap::drawMap(int start_x = 3, int start_y = 1) {
    // 테두리 그리기
    box(mapWin, 0, 0);
    int width = 84;

    for (int i = 0; i < 8; ++i) {
        mvwprintw(mapWin, i + start_y, (width - text_title[i].length()) / 2, "%s", text_title[i].c_str());
    }

    start_y += 8;
    mvwprintw(mapWin, start_y, (width - 7) / 2, "%s", "Level 1");

    start_y += 3;



    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (map[i][j] == 1) {
                wattron(mapWin, COLOR_PAIR(2));
                mvwprintw(mapWin, i + start_y, j * 2 + start_x, "■"); // 가로로 한 칸씩 띄워서 출력
                wattroff(mapWin, COLOR_PAIR(2));
            } else {
                mvwprintw(mapWin, i + start_y, j * 2 + start_x, " "); // 가로로 한 칸씩 띄워서 출력
            }
        }
    }
    wrefresh(mapWin);
}