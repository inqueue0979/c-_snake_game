#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"
#include "ScoreBoard.h"
#include "Snake.h"
#include <locale.h>
#include <thread>
#include <iostream>
#include <ncurses.h>
#include <chrono>

using namespace std;

void processInput(Snake& snake) {
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            snake.changeDirection(LEFT);
            break;
        case KEY_RIGHT:
            snake.changeDirection(RIGHT);
            break;
        case KEY_UP:
            snake.changeDirection(UP);
            break;
        case KEY_DOWN:
            snake.changeDirection(DOWN);
            break;
        case 'q': // 'q'를 눌러 게임 종료
            endwin();
            exit(0);
    }
}

int main() {
    setlocale(LC_ALL, ""); // UTF-8 설정

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    keypad(stdscr, TRUE); // 키패드 활성화

    // 터미널 크기 확인 및 최소 크기 확인 (42x84)
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    
    // 터미널 크기가 42x84보다 작으면 실행 X
    if (max_y < 42 || max_x < 84) {
        mvwprintw(stdscr, 1, 0, "Current Screen Size | max_y: %d, max_x: %d", max_y, max_x);
        printw("\n\nLARGER TERMINAL REQUIRED\n42x84 LEAST");
        refresh();
        getch();
        endwin();
        return 0;
    }

    // 게임 윈도우 생성
    WINDOW* mainWin = newwin(42, 84, (LINES - 42) / 2, (COLS - 84) / 2);
    wbkgd(mainWin, COLOR_PAIR(1));
    box(mainWin, 0, 0);
    wrefresh(mainWin);

    MainMenu menu;
    SnakeMap snakeMap(25, mainWin);
    snakeMap.loadMap(level_test);

    ScoreBoard scoreBoard(mainWin, 28, 24, 54, 12); // 오른쪽에 위치하도록 설정 (start_x=54, start_y=12)
    Snake snake(12, 12, snakeMap); // 초기 스네이크 위치 설정

    int choice = menu.display();

    switch (choice) {
        case 1: // 게임 시작
            nodelay(stdscr, TRUE); // 비차단 입력 설정
            while (true) {
                processInput(snake);
                snake.move();

                // 스네이크 위치 갱신 후 맵 다시 그리기
                snakeMap.loadMap(level_test); // 맵 리셋
                for (const auto& part : snake.getBody()) {
                    snakeMap.setMap(part.first, part.second, 2); // 2는 스네이크 몸체를 의미
                }
                snakeMap.setMap(snake.getHeadPosition().first, snake.getHeadPosition().second, 3); // 3은 스네이크 머리를 의미

                snakeMap.drawMap(3, 1);
                scoreBoard.display();

                std::this_thread::sleep_for(std::chrono::milliseconds(250)); // 1초에 4틱 (250ms)
            }
            endwin();
            break;
        case 2: // 크레딧

            break;
        case 3: // 종료
            break;
    }

    // 윈도우 종료
    delwin(mainWin);
    endwin();

    return 0;
}