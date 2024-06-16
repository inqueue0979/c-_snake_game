#include "MainMenu.h"
#include "SnakeMap.h"
#include "MapData.h"
#include "ScoreBoard.h"
#include "Snake.h"
#include "Item.h"
#include "Gate.h"
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

void loadNextLevel(SnakeMap& snakeMap, Snake& snake, ScoreBoard& scoreBoard, int& currentLevel) {
    currentLevel++; // 레벨 증가
    // 레벨 데이터를 로드
    switch(currentLevel) {
        case 2:
            snakeMap.loadMap(level_2);
            break;
        // 추가 레벨 로드
        default:
            snakeMap.loadMap(level_1);
            currentLevel = 1; // 기본 레벨로 돌아감
            break;
    }
    // 스네이크 위치 초기화
    snake.reset(12, 12); // 초기 스네이크 위치 설정
    scoreBoard.setLevel(currentLevel); // 점수판에 현재 레벨 설정
    scoreBoard.reset(); // 점수판 초기화
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

    int currentLevel = 1;
    MainMenu menu;
    SnakeMap snakeMap(25, mainWin);
    snakeMap.loadMap(level_1);

    ScoreBoard scoreBoard(mainWin, 28, 24, 54, 12, currentLevel); // 초기 레벨을 매개변수로 전달
    Snake snake(12, 12, snakeMap, scoreBoard); // 초기 스네이크 위치 설정
    Item itemManager;
    Gate gateManager;

    int choice = menu.display();
    int tickCount = 0;
    int gateTimer = 0;

    if (choice == 1) { // 게임 시작
        nodelay(stdscr, TRUE); // 비차단 입력 설정
        tickCount = 0;
        gateTimer = 0;
        while (true) {
            processInput(snake);
            snake.move(gateManager);

            // 스네이크 위치 갱신 후 맵 다시 그리기
            for (const auto& part : snake.getBody()) {
                snakeMap.setMap(part.first, part.second, 4); // 4는 스네이크 몸체를 의미
            }
            snakeMap.setMap(snake.getHeadPosition().first, snake.getHeadPosition().second, 3); // 3은 스네이크 머리를 의미

            itemManager.updateItems(snakeMap); // 아이템 갱신
            if (tickCount % 20 == 0) { // 5초마다 아이템 생성
                itemManager.generateItems(snakeMap);
            }

            if (gateTimer >= 40) { // 10초마다 게이트 생성
                gateManager.generateGate(snakeMap);
                gateTimer = 0;
            } else if (gateTimer >= 60) { // 15초마다 게이트 위치 변경
                gateManager.updateGate(snakeMap);
            }

            snakeMap.drawMap(3, 1);
            scoreBoard.display();

            if (scoreBoard.checkGoalsMet()) { // 목표 조건이 충족되었는지 확인
                loadNextLevel(snakeMap, snake, scoreBoard, currentLevel); // 다음 레벨로 이동
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(250)); // 1초에 4틱 (250ms)
            scoreBoard.addScore(1);
            tickCount++;
            gateTimer++;
            tickCount %= 10000; // 오버플로우 방지
            tickCount % 4 == 0 ? scoreBoard.addGameTimer(1) : scoreBoard.addGameTimer(0); // 1초마다 게임 타이머 증가
        }
        endwin();
    } else if (choice == 2) { // 크레딧
        // 크레딧 화면 로직 추가
    } else if (choice == 3) { // 종료
        // 종료 로직 추가
    }

    // 윈도우 종료
    delwin(mainWin);
    endwin();

    return 0;
}