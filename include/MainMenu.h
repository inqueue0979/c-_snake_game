#ifndef MAINMENU_H
#define MAINMENU_H

#include <ncurses.h>

class MainMenu {
public:
    MainMenu();
    ~MainMenu();
    int display();

private:
    void printMenu(WINDOW *menu_win, int highlight, const char *choices[], int n_choices);
};

#endif // MAINMENU_H
