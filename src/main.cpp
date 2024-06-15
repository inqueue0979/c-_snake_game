#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"
#include <locale.h>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    initscr();
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    getmaxyx(stdscr, max_y, max_x);

    if(max_y < 42 || max_x < 84) {
        mvwprintw(stdscr, 1, 0, "Current Screen Size | max_y: %d, max_x: %d", max_y, max_x);
        printw("\n\nLARGER TERMINAL REQUIRED\n42x84 LEAST");
        refresh();
        getch();
        endwin();
        return 0;
    }

    MainMenu menu;
    SnakeMap snakeMap(25);
    snakeMap.loadMap(level_test);
    int choice = menu.display();

    switch (choice) {
        case 1: // 게임 시작
            snakeMap.drawMap(3, 1);
            getch();
            endwin();
            break;
        case 2: // 크레딧

            break;
        case 3: // 종료
            break;
    }

    return 0;
}
