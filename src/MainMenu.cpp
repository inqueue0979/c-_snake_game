#include "MainMenu.h"
#include "data.h"
#include <locale.h>

// 메인 메뉴 생성자
MainMenu::MainMenu() {
    setlocale(LC_ALL, ""); // 한글, 특수문자 출력을 위해 UTF-8로 변경
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // 기본 색상 설정
    bkgd(COLOR_PAIR(1)); // 기본 배경 색상 설정
    noecho();
    cbreak();
    refresh();
}

// 메인 메뉴 소멸자
MainMenu::~MainMenu() {
    endwin();
}

// 메인 메뉴 프린트하는 함수
void MainMenu::printMenu(WINDOW *menu_win, int highlight, const char *choices[], int n_choices) {
    int x, y, i;
    x = 35;
    y = 30;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu_win);
}

// 프린팅 된 메인 메뉴를 화면에 표시하는 함수
int MainMenu::display() {
    int startx, starty, width, height;
    height = 42;
    width = 84;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    WINDOW *menu_win = newwin(height, width, starty, startx);
    keypad(menu_win, TRUE);
    const char *choices[] = {
        "🎮 Start Game",
        "🎬 Credits",
        "🚪 Exit"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 1;
    int choice = 0;
    int c;

    // 기본 윈도우 내의 서브윈도우 생성
    WINDOW *win = subwin(stdscr, 42, 84, starty, startx);
    init_pair(2, COLOR_WHITE, COLOR_BLACK); //윈도우 백그라운드 컬러
    box(win, 0, 0);
    bkgd(COLOR_PAIR(2));
    wrefresh(win);  // 서브윈도우 변경사항 갱신

    // 뱀 그림 및 로고 출력
    for (int i = 0; i < 15; ++i) {
        mvwprintw(menu_win, i + 2, 27, "%s", snake[i].c_str());
        
    }
    for (int i = 0; i < 8; ++i) {
        mvwprintw(menu_win, 16 + i, (width - text_title[i].length()) / 2, "%s", text_title[i].c_str());
    }

    wrefresh(win);

    printMenu(menu_win, highlight, choices, n_choices);
    while (1) {
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Enter key
                choice = highlight;
                break;
            default:
                break;
        }
        printMenu(menu_win, highlight, choices, n_choices);
        if (choice != 0) // User made a choice
            break;
    }

    // Clear the screen
    clear();
    refresh();
    return choice;
}
