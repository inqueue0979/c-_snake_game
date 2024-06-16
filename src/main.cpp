#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"
#include "ScoreBoard.h"
#include <locale.h>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    initscr();
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    if(max_y < 42 || max_x < 84) {
        mvwprintw(stdscr, 1, 0, "Current Screen Size | max_y: %d, max_x: %d", max_y, max_x);
        printw("\n\nLARGER TERMINAL REQUIRED\n42x84 LEAST");
        refresh();
        getch();
        endwin();
        return 0;
    }

    WINDOW* mainWin = newwin(42, 84, (LINES - 42) / 2, (COLS - 84) / 2);
    wbkgd(mainWin, COLOR_PAIR(1));
    box(mainWin, 0, 0);
    wrefresh(mainWin);

    MainMenu menu;
    SnakeMap snakeMap(25, mainWin);
    snakeMap.loadMap(level_test);

    ScoreBoard scoreBoard(mainWin, 28, 24, 54, 12); // 오른쪽에 위치하도록 설정 (start_x=54, start_y=12)
    int choice = menu.display();

    switch (choice) {
        case 1: // 게임 시작
            snakeMap.drawMap(3, 1);
            scoreBoard.display();
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
