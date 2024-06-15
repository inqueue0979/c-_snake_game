#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    if(LINES < 42 || COLS < 84) {
        initscr();
        printw("LARGER TERMINAL REQUIRED\n42x84 LEAST");
        refresh();
        getch();
        endwin();
        return 0;
    }

    MainMenu menu;
    SnakeMap snakeMap(25);
    snakeMap.loadMap(level_1);
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
