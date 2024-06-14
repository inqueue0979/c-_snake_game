#include <iostream>
#include <ncurses.h>
#include "SnakeMap.h"
#include "Snake.h"
#include "MapData.h"

void drawSnake(const Snake& snake) {
    for (const auto& segment : snake.getBody()) {
        mvaddch(segment.second, segment.first, 'O');
    }
    refresh();
}

int main() {
    initscr();              // ncurses 초기화
    cbreak();               // 입력 버퍼링을 사용하지 않음
    noecho();               // 입력된 문자를 화면에 표시하지 않음
    keypad(stdscr, TRUE);   // 특수 키 입력 활성화
    timeout(100);           // getch() 호출 시 100ms 대기

    SnakeMap map(21);       // 맵 크기 지정
    Snake snake(10, 10);    // 뱀의 초기 위치 지정

    map.loadMap(level_1);   // 맵 데이터 로드
    map.drawMap();          // 맵 출력
    drawSnake(snake);       // 뱀 출력

    char command;
    while (true) {
        int ch = getch();
        if (ch != ERR) {
            switch (ch) {
                case KEY_UP: command = 'U'; break;
                case KEY_DOWN: command = 'D'; break;
                case KEY_LEFT: command = 'L'; break;
                case KEY_RIGHT: command = 'R'; break;
                case 'q':     // 게임 종료
                    endwin();
                    return 0;
            }
            snake.move(command);

            if (snake.checkCollision(21, 21) || map.isCollision(snake.getBody().front().first, snake.getBody().front().second)) {
                mvprintw(22, 0, "Game Over!");
                refresh();
                break;
            }

            clear();
            map.drawMap();  // 맵 출력
            drawSnake(snake);  // 뱀 출력
        }
    }

    getch();
    endwin();  // ncurses 종료
    return 0;
}
