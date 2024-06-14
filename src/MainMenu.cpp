#include "MainMenu.h"
#include "data.h"
#include <locale.h>

MainMenu::MainMenu() {
    setlocale(LC_ALL, "");
    initscr();
    clear();
    noecho();
    cbreak();
}

MainMenu::~MainMenu() {
    endwin();
}

void MainMenu::printMenu(WINDOW *menu_win, int highlight, const char *choices[], int n_choices) {
    int x, y, i;
    x = 2;
    y = 2;
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

int MainMenu::display() {
    int startx, starty, width, height;
    height = 10;
    width = 30;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    WINDOW *menu_win = newwin(height, width, starty, startx);
    keypad(menu_win, TRUE);
    const char *choices[] = {
        "Start Game",
        "Credits",
        "Exit"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 1;
    int choice = 0;
    int c;

    // Print the snake art and game title
    for (int i = 0; i < 15; ++i) {
        mvprintw(i, (COLS - snake[i].length()) / 2, "%s", snake[i].c_str());
    }
    for (int i = 0; i < 8; ++i) {
        mvprintw(16 + i, (COLS - text_title[i].length()) / 2, "%s", text_title[i].c_str());
    }
    refresh();
    
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
