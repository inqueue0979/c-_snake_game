#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"

int main() {
    MainMenu menu;
    SnakeMap snakeMap(25);
    snakeMap.loadMap(level_1);
    int choice = menu.display();

    switch (choice) {
        case 1: // 게임 시작
            snakeMap.drawMap();
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
