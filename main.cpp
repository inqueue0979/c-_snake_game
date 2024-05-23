#include <ncurses.h>

int main() {
    initscr();
    printw("NCURSES");
    refresh();
    getch();
    endwin();
    return 0;
}