#include <locale.h>
#include <ncurses.h>
#include <unistd.h>
#include "data.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "ko_KR.utf-8");
    initscr();
    start_color(); 
    init_pair(1, COLOR_WHITE, COLOR_BLACK); //윈도우 백그라운드 컬러
    attron(COLOR_PAIR(1));
    wbkgd(stdscr, COLOR_PAIR(1));  //윈도우 백그라운드 컬러
    refresh();  // 변경사항 갱신

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    if(max_y < 42 || max_x < 84)
    {
        mvwprintw(stdscr, 1, 1, "Bigger Screen Required");
        mvwprintw(stdscr, 2, 1, "42 x 84 LEAST");
        refresh();

        getch();
        endwin();

        return 0;

    }

    // 기본 윈도우 내의 서브윈도우 생성
    WINDOW *win = subwin(stdscr, 42, 84, max_y / 2 - 21, max_x / 2 - 42); 
    init_pair(2, COLOR_WHITE, COLOR_BLACK); //윈도우 백그라운드 컬러
    box(win, 0, 0);
    attron(COLOR_PAIR(2));
    wbkgd(win, COLOR_PAIR(2));
    wrefresh(win);  // 서브윈도우 변경사항 갱신

// snakewin을 win 내부에 위치시킴
    WINDOW *snakewin = subwin(win, 25, 51, max_y / 2 - 21 + 1, max_x / 2 - 42 + 1);
    box(snakewin, 0, 0);
    wrefresh(snakewin);
    wrefresh(win); 
    refresh();


    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);

    for(int k = 0; k < 50; k++)
    {
        for(int i = 0; i <= 15; i++)
        {
            attron(COLOR_PAIR(i % 5 + 1));
            mvwprintw(win, i + 10 - k, 5, snake[i].c_str());
        }

        for(int j = 0; j < 8; j++) 
        {
            attron(COLOR_PAIR(j % 5 + 1));
            mvwprintw(win, j + 16 + 10 - k, 5, text_title[j].c_str());
        }

        for(int j = 0; j < 8; j++)
        {
            attron(COLOR_PAIR(j % 5 + 1));
            mvwprintw(win, j + 26 + 10 - k, 5, univ_title[j].c_str());
        }
        attron(COLOR_PAIR(2));

        for(int j = 0; j < 7; j++)
        {
            attron(COLOR_PAIR(j % 5 + 1));
            mvwprintw(win, j + 32 + 10 - k, 5, credits[j].c_str());
        }

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 7; j++)
            {
                mvwprintw(win, j + 39 + i * 7 - k + 10, 5, name_title[i][j].c_str());
            }
        
        for(int j = 0; j < 7; j++)
        {
            mvwprintw(win, 39, 5, "⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙ ⊙");
            mvwprintw(win, 40, 5, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █|");
        }
        
        box(win, 0, 0);
        box(snakewin, 0, 0);
        beep();

        usleep(100000);
        wrefresh(win);  // 서브윈도우 변경사항 갱신
    }

    refresh();

    getch();
    delwin(win);
    endwin();

    return 0;
}