#ifndef SNAKEMAP_H
#define SNAKEMAP_H

#include <ncurses.h>

class SnakeMap {
public:
    SnakeMap(int size, WINDOW* externalWin);
    ~SnakeMap();
    void loadMap(int mapData[25][25]);
    void drawMap(int start_x = 3, int start_y = 1);
    int** getMap() const;
    void setMap(int x, int y, int value);

private:
    int** map;
    int size;
    WINDOW* mapWin;
};

#endif // SNAKEMAP_H