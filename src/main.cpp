#include "MainMenu.h"

int main() {
    MainMenu menu;
    int choice = menu.display();

    switch (choice) {
        case 1:
            // Start Game
            // 게임 시작 로직 추가
            break;
        case 2:
            // Credits
            // 크레딧 화면 로직 추가
            break;
        case 3:
            // Exit
            // 종료 로직 추가
            break;
    }

    return 0;
}
